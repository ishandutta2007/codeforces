import java.io.*;
import java.util.*;

public class RandomPaths {
  public static int N, M, T, X;
  public static int[][] prob;
  public static Edge[] e;
  public static double[][] inp;
  public static double[][] outp;
  public static int K;
  public static double[][][][] tfd;
  public static double[][] re, im;
  
  public static void main (String[] args) throws IOException {
    InputReader in = new InputReader(System.in);
    PrintWriter out = new PrintWriter(System.out, true);
    
    N = in.nextInt();
    M = in.nextInt();
    T = in.nextInt();
    X = in.nextInt();
    K = Integer.numberOfTrailingZeros(Integer.highestOneBit(T))+2;
    
    e = new Edge[M];
    prob = new int[M][T+1];
    inp = new double[M][];
    outp = new double[M][];
    tfd = new double[M][][][];
    re = new double[K][];
    im = new double[K][];
    for (int i = 0; i < K; i++) {
      re[i] = new double[1<<i];
      im[i] = new double[1<<i];
    }
    
    int[][] dist = new int[N][N];
    for (int i = 0; i < N; i++) {Arrays.fill(dist[i], 1 << 29); dist[i][i] = 0;}
    for (int i = 0; i < M; i++) {
      int a = in.nextInt()-1, b = in.nextInt()-1, c = in.nextInt();
      e[i] = new Edge(a,b,c);
      dist[a][b] = Math.min(dist[a][b], c);
      for (int j = 1; j <= T; j++)
        prob[i][j] = in.nextInt();
    }
    
    for (int k = 0; k < N; k++) for (int i = 0; i < N; i++) for (int j = 0; j < N; j++)
      dist[i][j] = Math.min(dist[i][j], dist[i][k] + dist[k][j]);
    
    double[] res = new double[N];
    for (int i = 0; i < N-1; i++) res[i] = dist[i][N-1] + X;
    res[N-1] = 0;
    
    initTable();
    for (int i = 0; i < M; i++) init(i, dist[e[i].b][N-1] + X);
    
    for (int t = 1; t <= T; t++) {
      for (int i = 0; i < M; i++) set(i, t-1, res[e[i].b]);
      Arrays.fill(res, 1l << 60); res[N-1] = 0;
      for (int i = 0; i < M; i++) res[e[i].a] = Math.min(res[e[i].a], e[i].c + outp[i][t]);
    }
    
    out.printf("%.10f\n", res[0]);
    out.close();
    System.exit(0);
  }
  
  public static double[][] cosTable, sinTable;
  public static void initTable() {
    int levels = 18;
    cosTable = new double[levels][];
    sinTable = new double[levels][];
    for (int j = 1; j < levels; j++) {
      int n = 1 << j;
      cosTable[j] = new double[n / 2];
      sinTable[j] = new double[n / 2];
      cosTable[j][0] = 1;
      sinTable[j][0] = 0;
      double qc = Math.cos(2 * Math.PI / n), qs = Math.sin(2 * Math.PI / n);
      for (int i = 1; i < n / 2; i++) {
        cosTable[j][i] = cosTable[j][i - 1] * qc - sinTable[j][i - 1] * qs;
        sinTable[j][i] = sinTable[j][i - 1] * qc + cosTable[j][i - 1] * qs;
      }
    }
  }

  public static void transform(double[] real, double[] imag) {
    int n = real.length;
    if (n <= 1) return;
    int levels = Integer.numberOfTrailingZeros(n);

    for (int i = 0; i < n; i++) {
      int j = Integer.reverse(i) >>> (32 - levels);
      if (j > i) {
        double temp = real[i]; real[i] = real[j]; real[j] = temp;
        temp = imag[i]; imag[i] = imag[j]; imag[j] = temp;
      }
    }

    for (int size = 2; size <= n; size *= 2) {
      int halfsize = size / 2;
      int tablestep = n / size;
      for (int i = 0; i < n; i += size) {
        for (int j = i, k = 0; j < i + halfsize; j++, k += tablestep) {
          double tpre = real[j + halfsize] * cosTable[levels][k] + imag[j + halfsize] * sinTable[levels][k];
          double tpim = -real[j + halfsize] * sinTable[levels][k] + imag[j + halfsize] * cosTable[levels][k];
          real[j + halfsize] = real[j] - tpre;
          imag[j + halfsize] = imag[j] - tpim;
          real[j] += tpre;
          imag[j] += tpim;
        }
      }
    }
  }
    
  public static void init(int index, double p) {
    inp[index] = new double[T+1];
    outp[index] = new double[T+1];
    for (int i = 0; i <= T; i++) inp[index][i] = prob[index][i] / 100000.;
    
    int s = 100000;
    for (int i = 0; i <= T; i++) {
      s -= prob[index][i];
      outp[index][i] = s / 100000. * p;
    }
    
    tfd[index] = new double[K][2][];
    for (int i = 2; i < K; i++) {
      int start = (1<<(i-1))+1;
      int end = (1<<i)+1;

      int len = 2*(end-start);
      tfd[index][i][0] = new double[len];
      tfd[index][i][1] = new double[len];
      System.arraycopy(inp[index], start, tfd[index][i][0], 0, Math.min(T + 1 - start, len/2));
      transform(tfd[index][i][0], tfd[index][i][1]);
    }
  }
  
  public static void set(int index, int id, double x) {
    outp[index][id] = x;

    if (id+1 <= T) outp[index][id+1] += x * inp[index][1];
    if (id+2 <= T) outp[index][id+2] += x * inp[index][2];
    
    for (int i = 2; i < K; i++) {
      if ((((id+1) >> (i-2)) & 1) == 1) break;
      int start = id-(1<<(i-1))+1;
      int end = id+1;
      int len = 2*(end-start);
      
      Arrays.fill(re[i], 0); Arrays.fill(im[i], 0);
      System.arraycopy(outp[index], start, re[i], 0, len/2);
      transform(re[i], im[i]);
      
      for (int j = 0; j < len; j++) {
        double tre, tim;
        tre = tfd[index][i][0][j] * re[i][j] - tfd[index][i][1][j] * im[i][j];
        tim = tfd[index][i][1][j] * re[i][j] + tfd[index][i][0][j] * im[i][j];
        re[i][j] = tre;
        im[i][j] = tim;
      }
      transform(im[i], re[i]);
      
      for (int j = 0; id+j+2 <= T && j < len; j++) outp[index][id+j+2] += re[i][j] / len;
    }
  }
  
  static class Edge {
    public int a, b, c;
    public Edge(int a, int b, int c) {
      this.a = a;
      this.b = b;
      this.c = c;
    }
  }
  
  static class InputReader {
    public BufferedReader reader;
    public StringTokenizer tokenizer;

    public InputReader(InputStream stream) {
      reader = new BufferedReader(new InputStreamReader(stream), 32768);
      tokenizer = null;
    }

    public String next() {
      while (tokenizer == null || !tokenizer.hasMoreTokens()) {
        try {
          tokenizer = new StringTokenizer(reader.readLine());
        } catch (IOException e) {
          throw new RuntimeException(e);
        }
      }
      return tokenizer.nextToken();
    }

    public int nextInt() {
      return Integer.parseInt(next());
    }
  }
}
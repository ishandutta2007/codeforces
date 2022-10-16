import java.io.*;
import java.util.*;

public class giantchess {
  private static InputReader in;
  private static PrintWriter out;
  public static long gcd(long a, long b) {
    return b == 0 ? a : gcd(b, a % b);
  }

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);
    int n = in.nextInt();
    long[] x = new long[n], y = new long[n];
    for (int i = 0; i < n; i++) {
      x[i] = in.nextInt();
      y[i] = in.nextInt();
    }
    
    double eA = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 1; j < n && j < 60; j++) {
        int k = (i + j) % n;
        eA += (x[i] * y[k] - x[k] * y[i]) / (double)(1l << (j + 1));
      }
    }
    eA /= 2.;
    
    double eB = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 1; j < n && j < 60; j++) {
        int k = (i + j) % n;
        eB += gcd(Math.abs(x[i]-x[k]),Math.abs(y[i]-y[k])) / (double)(1l << (j + 1));
      }
    }
    
    if (n <= 60) {
      double same = 0;
      for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
          same += 2*(gcd(Math.abs(x[i]-x[j]), Math.abs(y[i]-y[j])));
        }
      }
      same /= (double)(1l << n);
      eB -= same;
    }
    
    if (n <= 60) {
      double num = (1l << n) - 1 - n - n * (n - 1) / 2;
      double den = (1l << n);
      eA *= den / num;
      eB *= den / num;
    }
    
    double eI = eA - eB / 2 + 1;
    
    out.printf("%.15f\n", eI);
    out.close();
    System.exit(0);
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
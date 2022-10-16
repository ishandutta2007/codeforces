import java.io.*;
import java.util.*;

public class restnumb {
  private static InputReader in;
  private static PrintWriter out;
  public static long gcd(long a, long b) {return b == 0 ? a : gcd(b, a%b);}

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);
    int N = in.nextInt(), M = in.nextInt();
    long[][] arr = new long[N][M];
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        arr[i][j] = in.nextInt();
      }
    }
    
    long[] a = new long[N];
    a[0] = 0;
    for (int i = 1; i < N; i++) a[i] = arr[i][0] - arr[0][0];
    long[] b = new long[M];
    b[0] = arr[0][0];
    for (int i = 1; i < M; i++) b[i] = arr[0][i];
    
    long g = 0;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        long q = a[i] + b[j];
        long diff = Math.abs(q - arr[i][j]);
        g = gcd(g, diff);
      }
    }
    
    boolean ok = true;
    if (g == 0) g = (long)(1e17);
    else {
      outer : for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
          if (arr[i][j] >= g) {
            ok = false;
            break outer;
          }
        }
      }
    }
    
    if (ok) {
      out.println("YES");
      out.println(g);
      out.print(a[0]);
      for (int i = 1; i < N; i++) {
        a[i] %= g;
        if (a[i] < 0) a[i] += g;
        out.print(" "+a[i]);
      }
      out.println();
      out.print(b[0]);
      for (int i = 1; i < M; i++) {
        b[i] %= g;
        if (b[i] < 0) b[i] += g;
        out.print(" "+b[i]);
      }
      out.println();
    } else {
      out.println("NO");
    }
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
import java.io.*;
import java.util.*;

public class prettysong {
  private static InputReader in;
  private static PrintWriter out;
  public static double[] har, har2;

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);
    char[] c = in.next().toCharArray();
    
    int N = c.length;
    har = new double[N+1];
    har2 = new double[N+1];
    har[0] = 0;
    har2[0] = 0;
    for (int i = 1; i <= N; i++) {
      har[i] = har[i-1] + 1. / (double)i;
      har2[i] = har2[i-1] + i / (double)(N-i+1);
    }
    double res = 0;
    for (int i = 0; i < c.length; i++) {
      if (c[i] == 'A' || c[i] == 'E' || c[i] == 'I' || c[i] == 'O' || c[i] == 'U' || c[i] == 'Y') {
        int j = Math.min(i, N-i-1);
        res += (j+1) + (j+1)*(har[N-j] - har[j+1]) + har2[j];
      }
    }
    out.printf("%.6f\n", res);
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
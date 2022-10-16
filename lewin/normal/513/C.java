import java.io.*;
import java.util.*;

public class secondprice {
  private static InputReader in;
  private static PrintWriter out;
  public static int N;
  public static int[] L, R;

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);
    N = in.nextInt();
    L = new int[N];
    R = new int[N];
    for (int i = 0; i < N; i++) {
      L[i] = in.nextInt();
      R[i] = in.nextInt();
    }
    
    double res = 0;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (i == j) continue;
        outer : for (int k = L[i]; k <= R[i]; k++) {
          // j beats i
          int c = i < j ? k : (k+1);
          if (R[j] < c) break;
          double prob = (R[j]-Math.max(c, L[j])+1) / (double)(R[j] - L[j] + 1);
          for (int m = 0; m < N; m++) {
            if (i == m || m == j) continue;
            int q = i < m ? (k-1) : k;
            if (L[m] > q) continue outer;
            prob *= (Math.min(R[m], q) - L[m] + 1) / (double)(R[m] - L[m] + 1);
          }
          prob *= 1./(double)(R[i]-L[i]+1);
          res += prob * k;
        }
      }
    }
    
    out.printf("%.15f\n", res);
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
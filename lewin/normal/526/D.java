import java.io.*;
import java.util.*;

public class necklace {
  private static InputReader in;
  private static PrintWriter out;

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);
    
    int N = in.nextInt();
    int K = in.nextInt();
    
    char[] let = in.next().toCharArray();
    int[] z = new int[N];
    int L = 0, R = 0;
    for (int i = 1; i < N; i++) {
      if (i > R) {
        L = R = i;
        while (R < N && let[R - L] == let[R])
          R++;
        z[i] = R - L;
        R--;
      } else {
        int k = i - L;
        if (z[k] < R - i + 1)
          z[i] = z[k];
        else {
          L = i;
          while (R < N && let[R - L] == let[R])
            R++;
          z[i] = R - L;
          R--;
        }
      }
    }
    z[0] = N;
    

    boolean[] res = new boolean[N+1];
    for (int len = 1; len*K <= N; len++) {
      boolean ok = true; 
      for (int i = 0; i < K; i++) {
        if (z[i*len] < len) {
          ok = false;
          break;
        }
      }
      res[K*len] |= ok;
    }
    int endpt = 0;
    for (int i = 1; i <= N; i++) {
      if (i < N && res[i]) {
        int end = Math.min(N, i+Math.min(z[i],i/K));
        endpt = Math.max(end, endpt);
      }
      
      if (i <= endpt) res[i] = true;
      
    }
    
    for (int i = 1; i <= N; i++)
      out.print(res[i]?"1":"0");
    out.println();
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
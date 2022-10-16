import java.io.*;
import java.util.*;

public class darkpark {
  private static InputReader in;
  private static PrintWriter out;

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);
    
    int N = in.nextInt();
    int len = (1<<(N+1))-1;
    int[] a = new int[len+1];
    for (int i = 2; i <= len; i++) {
      a[i] = in.nextInt();
    }
    
    int total = 0;
    for (int i = (1<<N)-1; i >= 1; i--) {
      int r = Math.max(a[2*i], a[2*i+1]);
      total += r - a[2*i]; total += r - a[2*i+1];
      a[i] += r;
    }
    
    out.println(total);
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
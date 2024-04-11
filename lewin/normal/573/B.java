import java.io.*;
import java.util.*;

public class bearblocks {
  private static InputReader in;
  private static PrintWriter out;

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);
    int n = in.nextInt();
    int[] arr = new int[n];
    for (int i = 0; i < n; i++) arr[i] = in.nextInt();
    
    int[] left = new int[n];
    int[] right = new int[n];
    
    int c = 0;
    for (int i = 0; i < n; i++) {
      c = Math.min(c+1, arr[i]);
      left[i] = c;
    }
    
    c = 0;
    for (int i = n-1; i >= 0; i--) {
      c = Math.min(c+1, arr[i]);
      right[i] = c;
    }
    
    int res = 0;
    for (int i = 0; i < n; i++) {
      res = Math.max(res, Math.min(left[i], right[i]));
    }
    out.println(res);
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
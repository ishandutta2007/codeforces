import java.io.*;
import java.util.*;

public class vaysastring {
  private static InputReader in;
  private static PrintWriter out;

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);

    int n = in.nextInt(), k = in.nextInt();
    char[] c = in.next().toCharArray();
    
    int[] pa = new int[n+1];
    int[] pb = new int[n+1];
    for (int i = 1; i <= n; i++) {
      pa[i] = pa[i-1] + (c[i-1] == 'a' ? 1 : 0);
      pb[i] = pb[i-1] + (c[i-1] == 'b' ? 1 : 0);
    }
    
    int front = 0;
    int max = 1;
    for (int i = 1; i <= n; i++) {
      while (pa[i] - pa[front] > k) front++;
      max = Math.max(max, i-front);
    }
    front = 0;
    for (int i = 1; i <= n; i++) {
      while (pb[i] - pb[front] > k) front++;
      max = Math.max(max, i-front);
    }
    out.println(max);
    
    
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
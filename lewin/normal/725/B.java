import java.io.*;
import java.util.*;

public class foodonplane {
  private static InputReader in;
  private static PrintWriter out;
  public static int[] time = {3,4,5,2,1,0};

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);

    String s = in.next();
    int off = s.charAt(s.length()-1) - 'a';
    s = s.substring(0, s.length()-1);
    long n = Long.parseLong(s);
    n--;
    long ans = (n/4) * 16L + time[off];
    if (n % 4 == 1 || n % 4 == 3) {
      ans += 6+1;
    } 
    out.println(ans+1);
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
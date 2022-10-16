import java.io.*;
import java.util.*;

public class vitalystrings {
  private static InputReader in;
  private static PrintWriter out;

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);
    
    String s = in.next();
    String t = in.next();
    char[] ans = s.toCharArray();
    boolean bre = false;
    for (int i = ans.length-1; i >= 0; i--) {
      if (ans[i] == 'z') {
        ans[i] = 'a';
      } else {
        ans[i]++;
        bre = true;
        break;
      }
    }
    
    String m = new String(ans);
    if (!bre || m.compareTo(t) >= 0) out.println("No such string");
    else out.println(m);
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
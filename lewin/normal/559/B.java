import java.io.*;
import java.util.*;

public class equivstring {
  private static InputReader in;
  private static PrintWriter out;

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);
    
    char[] s1 = in.next().toCharArray(), s2 = in.next().toCharArray();
    fix(s1, 0, s1.length-1);
    fix(s2, 0, s1.length-1);
    
    boolean eq = true;
    for (int i = 0; i < s1.length; i++) {
      if (s1[i] != s2[i]) {
        eq = false;
        break;
      }
    }
    
    out.println(eq ? "YES" : "NO");
    out.close();
    System.exit(0);
  }
  
  public static void fix(char[] s, int from, int to) {
    if ((to - from + 1) % 2 == 1) return;
    int mid = (from + to) / 2;
    int hl = (mid - from + 1);
    fix(s, from, mid);
    fix(s, mid+1, to);
    
    boolean swap = false;
    for (int i = 0; i < hl; i++) {
      if (s[from+i] < s[mid+1+i]) {
        break;
      } else if (s[from+i] > s[mid+1+i]) {
        swap = true;
        break;
      }
    }
    
    if (swap) {
      for (int i = 0; i < hl; i++) {
        char t = s[from+i];
        s[from+i] = s[mid+1+i];
        s[mid+1+i] = t;
      }
    }
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
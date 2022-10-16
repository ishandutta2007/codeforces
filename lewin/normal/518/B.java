import java.io.*;
import java.util.*;

public class tanyapost {
  private static InputReader in;
  private static PrintWriter out;

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);

    
    String s = in.next();
    String t = in.next();
    int[][] cnt = new int[2][26];
    for (char c : s.toCharArray()) {
        if (c >= 'a' && c <= 'z') {
            cnt[0][c - 'a']++;
        } else {
            cnt[1][c - 'A']++;
        }
    }
    ArrayList<Character> cc = new ArrayList<>();
    int r1 = 0, r2 = 0;
    for (char c : t.toCharArray()) {
        if (c >= 'a' && c <= 'z') {
            if (cnt[0][c - 'a'] > 0) {
                cnt[0][c - 'a']--;
                r1++;
            } else {
                cc.add(c);
            }
        } else {
            if (cnt[1][c - 'A'] > 0) {
                cnt[1][c - 'A']--;
                r1++;
            } else {
                cc.add(c);
            }
        }
    }
    for (char c : cc) {
        if (c >= 'a' && c <= 'z') {
            if (cnt[1][c - 'a'] > 0) {
                cnt[1][c - 'a']--;
                r2++;
            }
        } else {
            if (cnt[0][c - 'A'] > 0) {
                cnt[0][c - 'A']--;
                r2++;
            }
        }
    }
    out.println(r1 + " " + r2);
    out.close();
    System.exit(0);
}

  static class InputReader {
    public BufferedReader reader;
    public StringTokenizer tokenizer;

    public InputReader(InputStream stream) {
      reader = new BufferedReader(new InputStreamReader(stream), 1 << 20);
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
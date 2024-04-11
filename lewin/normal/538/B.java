import java.io.*;
import java.util.*;

public class quasi {
  private static InputReader in;
  private static PrintWriter out;

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);
    char[] s = in.next().toCharArray();
    int max = 0;
    for (int i = 0; i < s.length; i++) {
      max = Math.max(max, s[i]-'0');
    }
    out.println(max);
    for (int i = 0; i < max; i++) {
      String q = "";
      for (int j = 0; j < s.length; j++) {
        if (s[j] == '0' && q.equals("")) continue;
        if (s[j] > '0') {q += '1';s[j]--;}
        else q += '0';
      }
      if (i != 0) out.print(" ");
      out.print(q);
    }
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
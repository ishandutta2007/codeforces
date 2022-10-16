import java.io.*;
import java.util.*;

public class vitalypie {
  private static InputReader in;
  private static PrintWriter out;

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);
    int N = in.nextInt();
    char[] c = in.next().toCharArray();
    char[] keys = new char[26];
    int count = 0;
    for (int i = 0; i < N-1; i++) {
      keys[c[2*i] - 'a']++;
      if (keys[c[2 * i + 1] - 'A'] == 0) count++;
      else keys[c[2 * i + 1] - 'A']--;
    }
    out.println(count);
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
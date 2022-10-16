import java.io.*;
import java.util.*;

public class abchess {
  private static InputReader in;
  private static PrintWriter out;

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);
    int wt = 0, bt = 0;
    for (int i = 0; i < 8; i++) {
      char[] c = in.next().toCharArray();
      for (char m : c) {
        if (m == 'Q') wt += 9;
        if (m == 'R') wt += 5;
        if (m == 'B') wt += 3;
        if (m == 'N') wt += 3;
        if (m == 'P') wt += 1;
        
        if (m == 'q') bt += 9;
        if (m == 'r') bt += 5;
        if (m == 'b') bt += 3;
        if (m == 'n') bt += 3;
        if (m == 'p') bt += 1;
      }
    }
    out.println(wt > bt ? "White" : wt == bt ? "Draw" : "Black");
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
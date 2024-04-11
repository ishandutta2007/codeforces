import java.io.*;
import java.util.*;

public class philtrain {
  private static InputReader in;
  private static PrintWriter out;

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);
    int[] b = new int[] {
        0b000,
        0b011,
        0b111,
        0b111,
        0b110,
        0b111,
        0b111,
        0b111,
    };
    int t = in.nextInt();
    while (t-- > 0) {
      int n = in.nextInt(), k = in.nextInt();
      char[][] c = new char[3][n];
      int[] masks = new int[n];
      for (int i = 0; i < 3; i++)
        c[i] = in.next().toCharArray();
      
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
          if (c[j][i] == '.') masks[i] |= 1 << j;
        }
      }
      
      int mask = 0;
      if (c[0][0] == 's') mask = 1;
      if (c[1][0] == 's') mask = 2;
      if (c[2][0] == 's') mask = 4;
      
      int curcol = 0;
      while (true) {
        if (curcol+1 >= n) {
          break;
        }
        int next = b[mask & masks[curcol+1]] & masks[curcol+1];
        curcol++;
        if (curcol+1 < n) {next &= masks[curcol+1]; curcol++;}
        if (curcol+1 < n) {next &= masks[curcol+1]; curcol++;}
        mask = next;
      }
      
      out.println(mask > 0 ? "YES" : "NO");
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
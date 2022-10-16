import java.io.*;
import java.util.*;

public class lookseryparty {
  private static InputReader in;
  private static PrintWriter out;

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);
    int N = in.nextInt();
    char[][] grid = new char[N][N];
    for (int i = 0; i < N; i++) grid[i] = in.next().toCharArray();
    int[] a = new int[N];
    for (int i = 0; i < N; i++) a[i] = in.nextInt();
    
    int[] deg = new int[N];
    boolean[] w = new boolean[N];
    boolean ok = false;
    for (int iter = 0; iter < 100000; iter++) {
      ArrayList<Integer> m = new ArrayList<Integer>();
      for (int i = 0; i < N; i++) {
        if (a[i] == deg[i]) {
          m.add(i);
        }
      }
      if (m.size() == 0) {
        ok = true;
        break;
      }
      int bad = m.get((int)(Math.random()*m.size()));
      int ch = w[bad] ? -1 : 1;
      for (int i = 0; i < N; i++) if (grid[bad][i] == '1') deg[i] += ch;
      w[bad] = !w[bad];
    }
    
    if (ok) {
      int count = 0;
      for (int i = 0; i < N; i++) if (w[i]) count++;
      out.println(count);
      boolean first = true;
      for (int i = 0; i < N; i++) {
        if (w[i]) {
          if (!first) out.print(" ");
          out.print(i+1);
          first = false;
        }
      }
      out.println();
    } else {
      out.println(-1);
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
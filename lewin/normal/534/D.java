import java.io.*;
import java.util.*;

public class handshakes {
  private static InputReader in;
  private static PrintWriter out;

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);
    int N = in.nextInt();
    TreeMap<Integer, LinkedList<Integer>> ts = new TreeMap<>();
    for (int i = 1; i <= N; i++) {
      int a = in.nextInt();
      if (!ts.containsKey(a)) ts.put(a, new LinkedList<>());
      ts.get(a).add(i);
    }
    
    int[] order = new int[N];
    int idx = 0;
    int cur = 0;
    for (int i = 0; i < N; i++) {
      if (!ts.containsKey(cur) || ts.get(cur).size() == 0) break;
      order[idx++] = ts.get(cur).removeFirst();
      if (ts.get(cur).size() == 0) ts.remove(cur);
      cur++;
      while (cur > 0 && ts.ceilingKey(cur) == null) cur -= 3;
    }
    
    if (idx < N) {
      out.println("Impossible");
    } else {
      out.println("Possible");
      out.print(order[0]);
      for (int i = 1; i < N; i++) out.print(" "+order[i]);
      out.println();
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
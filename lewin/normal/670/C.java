import java.io.*;
import java.util.*;

public class cinema {
  private static InputReader in;
  private static PrintWriter out;
  public static HashMap<Integer, Integer> mp;
  
  public static int get(int id) {
    Integer x = mp.get(id);
    if (x == null) return 0;
    return x;
  }
  

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);

    int n = in.nextInt();
    mp = new HashMap<>();
    for (int i = 0; i < n; i++) {
      int key = in.nextInt();
      mp.put(key, get(key)+1);
    }
    int m = in.nextInt();
    int p1 = 0, p2 = 0, bid = 0;
    int[] b = new int[m], c = new int[m];
    for (int i = 0; i < m; i++) {
      b[i] = in.nextInt();
    }
    for (int i = 0; i < m; i++) {
      c[i] = in.nextInt();
    }
    for (int i = 0; i < m; i++) {
      int a1 = get(b[i]), a2 = get(c[i]);
      if (a1 > p1 || (a1 == p1 && a2 > p2)) {
        bid = i;
        p1 = a1;
        p2 = a2;
      }
    }
    out.println(bid+1);
    
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
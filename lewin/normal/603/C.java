import java.io.*;
import java.util.*;

public class liegelegendre {
  private static InputReader in;
  private static PrintWriter out;

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);

    int n = in.nextInt();
    odd = in.nextInt() % 2 == 1;
    mp = new HashMap<>();
    int x = 0;
    while (n-- > 0) x ^= computeNim(in.nextInt());
    out.println(x == 0 ? "Nicky" : "Kevin");
    out.close();
    System.exit(0);
  }
  
  public static boolean odd;
  public static HashMap<Integer, Integer> mp;
  public static int computeNim(int num) {
    if (num == 0) return 0;
    if (num == 1) return 1;
    if (odd && num == 3) return 1;
    if (num % 2 == 1) return 0;
    if (mp.containsKey(num)) return mp.get(num);
    boolean[] seen = new boolean[5];
    seen[computeNim(num-1)] = true;
    if (odd) seen[computeNim(num/2)] = true;
    else seen[0] = true;
    int idx = 0;
    while (seen[idx]) idx++;
    mp.put(num, idx);
    return idx;
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
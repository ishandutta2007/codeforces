import java.io.*;
import java.util.*;

public class mikebeer {
  private static InputReader in;
  private static PrintWriter out;
  public static int MAXV = 500010;

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);
    int N = in.nextInt();
    int Q = in.nextInt();
    
    int[] arr = new int[N];
    for (int i = 0; i < N; i++) arr[i] = in.nextInt();
    ArrayList<Integer>[] div = new ArrayList[N];
    int[] prime = new int[10];
    for (int i = 0; i < N; i++) {
      int t = arr[i];
      int idx = 0;
      for (int j = 2; j * j <= t; j++) {
        if (t % j == 0) {
          prime[idx++] = j;
          while (t % j == 0) t /= j;
        }
      }
      if (t > 1) prime[idx++] = t;
      
      div[i] = new ArrayList<>();
      for (int k = 0; k < 1 << idx; k++) {
        int prod = 1;
        for (int j = 0; j < idx; j++) if ((k & (1 << j)) > 0) prod *= prime[j];
        div[i].add((Integer.bitCount(k) % 2 == 1 ? -1 : 1) * prod);
      }
    }
    
    boolean[] shelf = new boolean[N];
    int[] divcount = new int[MAXV];
    long total = 0;
    StringBuffer buff = new StringBuffer();
    for (int t = 0; t < Q; t++) {
      int a = in.nextInt()-1;
      int change = shelf[a] ? -1 : 1;
      if (shelf[a]) for (int k : div[a]) divcount[Math.abs(k)]--;
      for (int k : div[a]) {
        int sign = k < 0 ? -1 : 1;
        int val = Math.abs(k);
        total += change * sign * divcount[val];
      }
      if (!shelf[a]) for (int k : div[a]) divcount[Math.abs(k)]++;
      shelf[a] ^= true;
      buff.append(total+"\n");
    }
    out.print(buff.toString());
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
import java.io.*;
import java.util.*;

public class littleartemdance {
  private static InputReader in;
  private static PrintWriter out;

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);

    int n = in.nextInt(), q = in.nextInt();
    int[] qs = new int[q];
    int[] type = new int[q];
    for (int i = 0; i < q; i++) {
      type[i] = in.nextInt();
      if (type[i] == 1) qs[i] = (n + in.nextInt()) % n;
    }
    int ch = 0;
    int mode = 0;
    for (int i = 0; i < q; i++) {
      if (type[i] == 1) {
        mode ^= qs[i]&1;
      } else {
        if (mode == 0) ch = (ch+1)%(n/2);
        else ch = (ch+n/2-1)%(n/2);
        mode ^= 1;
      }
    }
    int where = 0;
    for (int i = 0; i < q; i++) {
      if (type[i] == 1) where = (where + qs[i]) % n;
      else where ^= 1;
    }
    int[] arr = new int[n];
    for (int i = 0; i < n; i++) {
      if (i%2 == 0) arr[i] = i+1;
      else {arr[i] = (i+1 + ch*2) % n; if (arr[i] == 0) arr[i] = n;}
    }
    for (int i = 0; i < n; i++) {
      if (i != 0) out.print(" ");
      out.print(arr[(i+n-where)%n]);
    }
    out.println();
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
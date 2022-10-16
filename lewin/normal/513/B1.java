import java.io.*;
import java.util.*;

public class permb {
  private static InputReader in;
  private static PrintWriter out;

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);
    int N = in.nextInt();
    long F = Long.parseLong(in.next());
    long[] count = new long[N+1];
    count[0] = 1;
    count[1] = 1;
    for (int i = 2; i <= N; i++) {
      count[i] = count[i-1] * 2;
    }
    
    F--;
    int[] arr = new int[N];
    int fid = 0, bid = N-1;
    int curs = N-1, q = 1;
    while (fid <= bid) {
      if (F >= count[curs]) {
        F -= count[curs];
        arr[bid--] = q;
      } else {
        arr[fid++] = q;
      }
      curs--;
      q++;
    }
    out.print(arr[0]);
    for (int i = 1; i < N; i++) out.print(" "+arr[i]);
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
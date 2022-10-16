import java.io.*;
import java.util.*;

public class happyline {
  private static InputReader in;
  private static PrintWriter out;

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);
    int N = in.nextInt();
    int[] arr = new int[N];
    for (int i = 0; i < N; i++) arr[i] = in.nextInt()+i;
    Arrays.sort(arr);
    for (int i = 0; i < N; i++) arr[i] -= i;
    for (int i = 0; i < N-1; i++) {
      if (arr[i] > arr[i+1]) {
        out.println(":(");
        out.close();
        System.exit(0);
      }
    }
    out.print(arr[0]);
    for (int i = 1; i < N; i++) {
      out.print(" "+arr[i]);
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
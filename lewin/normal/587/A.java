import java.io.*;
import java.util.*;

public class duffweights {
  private static InputReader in;
  private static PrintWriter out;

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);
    int n = in.nextInt();
    int[] arr = new int[2000010];
    for (int i = 0; i < n; i++) {
      arr[in.nextInt()]++;
    }
    
    int times = 0;
    for (int i = 0; i < arr.length-1; i++) {
      if (arr[i] % 2 == 1) times++;
      arr[i+1] += arr[i]/2;
    }
    
    out.println(times);
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
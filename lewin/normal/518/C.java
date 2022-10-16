import java.io.*;
import java.util.*;

public class anyasmart {
  private static InputReader in;
  private static PrintWriter out;

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);
    int N = in.nextInt(), M = in.nextInt(), K = in.nextInt();
    
    int[] perm = new int[N];
    for (int i = 0; i < N; i++) {
      perm[i] = in.nextInt();
    }
    int[] pos = new int[N+1];
    for (int i = 0; i < N; i++) pos[perm[i]] = i;
    
    long s = 0;
    for (int i = 0; i < M; i++) {
      int index = in.nextInt();
      int j = pos[index];
      s += j / K + 1;
      
      if (j == 0) continue;
      int other = perm[j - 1];
      pos[other] = j;
      pos[index] = j - 1;
      perm[j] = perm[j - 1];
      perm[j - 1] = index;
    }
    out.println(s);
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
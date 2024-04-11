import java.io.*;
import java.util.*;

public class transmittinglevels {
  private static InputReader in;
  private static PrintWriter out;

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);
    int N = in.nextInt();
    int Q = in.nextInt();
    long[] arr = new long[2*N];
    long sumall = 0;
    for (int i = 0; i < N; i++) {
      arr[i] = arr[N+i] = in.nextInt();
      sumall += arr[i];
    }
    
    for (int q = 0; q < Q; q++) {
      long b = Long.parseLong(in.next());
      if (b >= sumall) {
        out.println(1);
        continue;
      }
      
      int[] next = new int[2 * N];
      int ptr = -1;
      long csum = 0;
      for (int i = 0; i < 2 * N; i++) {
        while (ptr+1 < 2*N && csum + arr[ptr+1] <= b) {
          csum += arr[ptr+1];
          ptr++;
        }
        next[i] = ptr+1;
        csum -= arr[i];
      }
      
      int cur = 0;
      while (true) {
        if (next[cur] >= N) {
          cur = next[cur];
          break;
        }
        cur = next[cur];
      }
      cur -= N;
      
      int start = cur;
      int count = 1;
      while (true) {
        if(cur >= 2 * N || next[cur] >= start + N) {
          break;
        }
        cur = next[cur];
        count++;
      }
      
      out.println(count);
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
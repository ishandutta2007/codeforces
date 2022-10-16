import java.io.*;
import java.util.*;

public class chainreaction {
  private static InputReader in;
  private static PrintWriter out;
  static class Pair implements Comparable<Pair> {
    public int a,b;
    public Pair(int a, int b) {
      this.a = a;
      this.b = b;
    }
    
    public int compareTo(Pair other) {
      return a - other.a;
    }
  }

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);
    int n = in.nextInt();
    Pair[] p = new Pair[n];
    for (int i = 0; i < n; i++) {
      p[i] = new Pair(in.nextInt(), in.nextInt());
    }
    Arrays.sort(p);
    
    int[] destroy = new int[n];
    destroy[0] = 0;
    for (int i = 1; i < n; i++) {
      int left = p[i].a - p[i].b;
      if (left <= p[0].a) {
        destroy[i] = i;
        continue;
      }
      int lo = 0, hi = i-1;
      while(lo<hi) {
        int mid = (lo+hi+1)/2;
        if (p[mid].a < left) lo = mid;
        else hi = mid-1;
      }
      destroy[i] = destroy[lo] + i - lo - 1;
    }
    int res = n;
    for (int i = 0; i < n; i++) {
      res = Math.min(res, n-i-1 + destroy[i]);
    }
    out.println(res);
    
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
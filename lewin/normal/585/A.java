import java.io.*;
import java.util.*;

public class genden {
  private static InputReader in;
  private static PrintWriter out;

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);
    int n = in.nextInt();
    long[] v = new long[n];
    long[] d = new long[n];
    long[] p = new long[n];
    for (int i = 0; i < n; i++) {
      v[i] = in.nextInt();
      d[i] = in.nextInt();
      p[i] = in.nextInt();
    }
    
    ArrayList<Integer> res = new ArrayList<>();
    boolean[] removed = new boolean[n];
    int[] queue = new int[n];
    int front = 0, back = 0;
    for (int i = 0; i < n; i++) {
      if (p[i] < 0) continue;
      
      res.add(i+1);
      long cursub = v[i];
      for (int j = i+1; j < n; j++) {
        if (!removed[j]) {
          p[j] -= cursub--;
          if (p[j] < 0) {
            queue[back++] = j;
            removed[j] = true;
          }
        }
        if(cursub == 0) break;
      }
      
      while (front < back) {
        int cur = queue[front++];
        for (int j = cur+1; j < n; j++) {
          p[j] -= d[cur];
          if (!removed[j] && p[j] < 0) {
            removed[j] = true;
            queue[back++] = j;
          }
        }
      }
    }
    
    out.println(res.size());
    for (int i = 0; i < res.size(); i++) {
      if (i != 0) out.print(" ");
      out.print(res.get(i));
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
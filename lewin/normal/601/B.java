import java.io.*;
import java.util.*;

public class lipschitz {
  private static InputReader in;
  private static PrintWriter out;
  static class Point implements Comparable<Point> {
    public int m, pos;
    public Point(int m, int pos) {
      this.m = m;
      this.pos = pos;
    }
    
    public int compareTo(Point other) {
      return m - other.m;
    }
  }

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);

    int n = in.nextInt(), q = in.nextInt();
    int[] arr = new int[n];
    for (int i = 0; i < n; i++) arr[i] = in.nextInt();
    int[] brr = new int[n-1];
    for (int i = 0; i < n-1; i++) {
      int d = arr[i] - arr[i+1];
      brr[i] = d>0?d:-d;
    }
    

    int[] L = new int[n+2];
    int[] R = new int[n+2];
    int[] stack = new int[n+2];
    int sidx = 0;
    for (int j = 0; j < q; j++) {
      int a = in.nextInt()-1, b = in.nextInt()-1;
      sidx = 0;
      for (int i = a; i < b; i++) {
        while (sidx > 0 && brr[stack[sidx-1]] < brr[i]) {
          sidx--;
        }
        if (sidx == 0) L[i] = a-1;
        else L[i] = stack[sidx-1];
        stack[sidx++] = i;
      }
      sidx = 0;
      for (int i = b-1; i >= a; i--) {
        while (sidx > 0 && brr[stack[sidx-1]] <= brr[i]) {
          sidx--;
        }
        if (sidx == 0) R[i] = b;
        else R[i] = stack[sidx-1];
        stack[sidx++] = i;
      }
      long res = 0;
      for (int i = a; i < b; i++) {
        res += (long)(R[i]-i) * (long)(i-L[i]) * brr[i];
      }
      out.println(res);
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
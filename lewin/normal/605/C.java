import java.io.*;
import java.util.*;

public class freelancersdream {
  private static InputReader in;
  private static PrintWriter out;
  
  static class Vector {
    public double a,b;
  }
  
  static class Point implements Comparable<Point> {
    public long a,b;
    public Point(long a, long b) {
      this.a = a;
      this.b = b;
    }
    
    public int compareTo(Point other) {
      if (a == other.a) return Long.compare(other.b, b);
      return Long.compare(a, other.a);
    }
  }

  public static boolean ccw(Point p, Point q, Point r) {
    return (r.b - p.b) * (q.a - p.a) >= (q.b - p.b) * (r.a - p.a);
  }
  public static long x,y;
  public static double solve1(Point p) {
    return Math.max(x/(double)p.a, y/(double)p.b);
  }
  public static double solve2(Point p1, Point p2) {
    int side1 = (y * p1.a > x * p1.b ? 1 : 0);
    int side2 = (y * p2.a > x * p2.b ? 1 : 0);
    if (side1 == side2) return 1l << 60;
    double lo = 0, hi = 1;
    for (int iter = 0; iter < 50; iter++) {
      double mid = (lo+hi)/2.;
      double tx = mid * p1.a + (1-mid) * p2.a;
      double ty = mid * p1.b + (1-mid) * p2.b;
      
      if (y * tx < x * ty) hi = mid;
      else lo = mid;
    }
    
    double tx = lo * p1.a + (1-lo) * p2.a;
    double ty = lo * p1.b + (1-lo) * p2.b;
    return Math.max(x/tx, y/ty);
  }
  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);

    int n = in.nextInt();
    x = in.nextInt();
    y = in.nextInt();
    Point[] p = new Point[n];
    for (int i = 0; i < n; i++) {
      p[i] = new Point(in.nextInt(), in.nextInt());
    }
    Arrays.sort(p);
    double res = 1l << 60;
    for (int i = 0; i < n; i++) {
      res = Math.min(res, solve1(p[i]));
    }
    if (n == 1) {
      out.printf("%.15f\n", res);
      out.close();
      System.exit(0);
    }
    Point[] stack = new Point[n];
    int sidx = 0;
    stack[sidx++] = p[0];
    stack[sidx++] = p[1];
    res = Math.min(res, solve2(p[0], p[1]));
    for (int i = 2; i < n; i++) {
      while (sidx > 1 && ccw(stack[sidx-2], stack[sidx-1], p[i])) {
        sidx--;
      }
      stack[sidx++] = p[i];
      res = Math.min(res, solve2(stack[sidx-2], p[i]));
    }
    out.printf("%.10f\n", res);
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
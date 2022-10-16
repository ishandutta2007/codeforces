import java.io.*;
import java.util.*;

public class chipndalerescue {
  private static InputReader in;
  private static PrintWriter out;

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);
    int x1 = in.nextInt(), y1 = in.nextInt(), x2 = in.nextInt(), y2 = in.nextInt();
    
    double dist = Math.sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
    int vmax = in.nextInt(), t = in.nextInt();
    
    int vx = in.nextInt(), vy = in.nextInt();
    int wx = in.nextInt(), wy = in.nextInt();
    double lo = 0, hi = 1000000000;
    for (int i = 0; i < 200; i++) {
      double mid = (lo+hi) / 2.;
      if (ok(mid,x1,y1,x2,y2,vx,vy,wx,wy,t,vmax)) hi = mid;
      else lo = mid;
    }
    out.printf("%.10f\n", lo);
    out.close();
    System.exit(0);
  }
  
  public static boolean ok(double mid, double x1, double y1, double x2, double y2, double vx, double vy, double wx, double wy, double t, double vmax) {
    double fx = x1;
    double fy = y1;
    
    if (mid >= t) {
      fx += t * vx;
      fy += t * vy;
      fx += (mid-t) * wx;
      fy += (mid-t) * wy;
    } else {
      fx += mid * vx;
      fy += mid * vy;
    }
    
    
    double time = Math.sqrt((x2-fx)*(x2-fx)+(y2-fy)*(y2-fy)) / vmax;
    
    return time <= mid;
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
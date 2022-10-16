import java.io.*;
import java.util.*;

public class recyclingbottles {
  private static InputReader in;
  private static PrintWriter out;
  public static int n;

  public static long[] x,y;
  public static double dist(long x1, long y1, long x2, long y2) {
    return Math.sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
  }
  public static double dist(int a, int b) {
    return Math.sqrt((x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b]));
  }
  
  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);
    
    long ax = in.nextInt();
    long ay = in.nextInt();
    long bx = in.nextInt();
    long by = in.nextInt();
    long tx = in.nextInt();
    long ty = in.nextInt();
    
    n = in.nextInt();
    x = new long[n];
    y = new long[n];
    for (int i = 0; i < n; i++) {
      x[i] = in.nextInt();
      y[i] = in.nextInt();
    }
    
    double[] basedist = new double[n];
    double sum = 0;
    for (int i = 0; i < n; i++) {
      basedist[i] = 2*dist(x[i],y[i],tx,ty);
      sum += basedist[i];
    }
    out.printf("%.10f\n", sum+Math.min(solve(ax,ay,bx,by,tx,ty),solve(bx,by,ax,ay,tx,ty)));
    out.close();
    System.exit(0);
  }
  
  public static double solve(long ax, long ay, long bx, long by, long tx, long ty) {
    double[] m1p = new double[n];
    double[] m1s = new double[n];
    for (int i = 0; i < n; i++) {
      m1p[i] = Math.min(0,dist(x[i],y[i],bx,by)-dist(x[i],y[i],tx,ty));
      if(i>0) m1p[i] = Math.min(m1p[i],m1p[i-1]);
    }
    for (int i = n-1; i >= 0; i--) {
      m1s[i] = Math.min(0,dist(x[i],y[i],bx,by)-dist(x[i],y[i],tx,ty));
      if(i+1<n) m1s[i] = Math.min(m1s[i],m1s[i+1]);
    }
    
    double ans = 1l << 50;
    for (int i = 0; i < n; i++) {
      double cost = dist(x[i],y[i],ax,ay)-dist(x[i],y[i],tx,ty);
      double sub = 0;
      if (i>0) sub = Math.min(sub, m1p[i-1]);
      if (i+1<n) sub = Math.min(sub, m1s[i+1]);
      ans = Math.min(ans, cost+sub);
    }
    return ans;

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
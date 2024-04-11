import java.io.*;
import java.util.*;

public class weaknesspoor {
  private static InputReader in;
  private static PrintWriter out;

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);
    int n = in.nextInt();
    long[] arr = new long[n];
    for (int i = 0; i < n; i++) arr[i] = in.nextInt();
    double lo = -10000, hi = 10000;
    psum = new double[n];
    for (int iter = 0; iter < 100; iter++) {
      double x1 = (2*lo + hi) / 3.;
      double x2 = (lo + 2*hi) / 3.;
      double f1 = eval(arr, x1);
      double f2 = eval(arr, x2);
      if (f1 < f2) hi = x2;
      else lo = x1;
    }
    out.printf("%.10f\n", eval(arr, lo));
    out.close();
    System.exit(0);
  }
  public static double[] psum;
  public static double eval(long[] arr, double x) {
    psum[0] = arr[0] - x;
    for (int i = 1; i < arr.length; i++) psum[i] = psum[i - 1] + arr[i] - x;
    
    double ret = 0;
    double min = 0, max = 0;
    for (int i = 0; i < arr.length; i++) {
      double t = Math.abs(psum[i] - min);
      if (t > ret) ret = t;
      min = Math.min(psum[i], min);
      
      t = Math.abs(max - psum[i]);
      if (t > ret) ret = t;
      max = Math.max(psum[i], max);
    }
    return ret;
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
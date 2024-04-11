import java.io.*;
import java.util.*;

public class littleartemrv {
  private static InputReader in;
  private static PrintWriter out;

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);

    int n = in.nextInt();
    double[] max = new double[n+1];
    for (int i = 1; i <= n; i++) max[i] = in.nextDouble() + max[i-1];
    double[] min = new double[n+1];
    for (int i = 1; i <= n; i++) min[i] = in.nextDouble();
    for (int i = n-1; i >= 1; i--) min[i] += min[i+1];

    double[] sum = new double[n+1];
    for (int i = 1; i < n; i++) {
      sum[i] = 1 + max[i] - min[i+1];
    }
    sum[n] = 2;
    double[] pref1 = new double[n+1];
    for (int i = 1; i <= n; i++) {
      pref1[i] = (sum[i] + Math.sqrt(Math.max(0,sum[i]*sum[i] - 4*max[i]))) / 2.;
    }
    double[] b1 = new double[n+1];
    double[] b2 = new double[n+1];
    for (int i = 1; i <= n; i++) {
      double need = sum[i] - sum[i-1];
      double first = pref1[i] - pref1[i-1];
      b1[i] = first;
      b2[i] = need-first;
    }
    for (int i = 1; i <= n; i++) {
      if (i != 1) out.print(" ");
      out.printf("%.10f", b1[i]);
    }
    out.println();
    for (int i = 1; i <= n; i++) {
      if (i != 1) out.print(" ");
      out.printf("%.10f", b2[i]);
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
    
    public double nextDouble() {
      return Double.parseDouble(next());
    }
  }


}
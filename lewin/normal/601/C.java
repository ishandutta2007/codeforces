import java.io.*;
import java.util.*;

public class kleofasnthlon {
  private static InputReader in;
  private static PrintWriter out;

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);

    int n = in.nextInt(), m = in.nextInt();
    if (m == 1) {
      out.println(1);
      out.close();
      System.exit(0);
    }
    int[] arr = new int[n];
    int sum = 0;
    for (int i = 0; i < n; i++) {
      sum += arr[i] = in.nextInt();
    }
    double[] prob = new double[sum];
    prob[0] = 1;
    double[] psum = new double[sum];
    Arrays.fill(psum, 1);
    
    for (int i = 0; i < n; i++) {
      for (int j = sum-1; j >= 0; j--) {
        double x = (j > 0 ? psum[j-1] : 0) - (j-m > 0 ? psum[j-m-1] : 0) - (j-arr[i] >= 0 ? prob[j-arr[i]] : 0);;
        prob[j] = x / (m-1);
      }
      psum[0] = prob[0];
      for (int j = 1; j < sum; j++) {
        psum[j] = psum[j-1] + prob[j];
      }
    }
    double x = 0;
    for (int i = sum-1; i >= 0; i--) x += prob[i];
    
    out.printf("%.15f\n", 1 + (m-1) * x);
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
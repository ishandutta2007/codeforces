import java.io.*;
import java.util.*;

public class jerryprotest {
  private static InputReader in;
  private static PrintWriter out;

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);

    int n = in.nextInt();
    int[] arr = new int[n];
    for (int i = 0; i < n; i++) arr[i] = in.nextInt();
    Arrays.sort(arr);
    double[] probdiff = new double[5000*3];
    double total = n * (n - 1) / 2;
    for (int i = 0; i < n; i++) {
      for (int j = i+1; j < n; j++) {
        probdiff[arr[j]-arr[i]] += 1. / total;
      }
    }
    
    double[] alead = new double[probdiff.length*2];
    for (int i = 0; i < probdiff.length; i++) {
      for (int j = 0; j < probdiff.length; j++) {
        alead[i+j] += probdiff[i] * probdiff[j];
      }
    }
    
    double ans = 0;
    for (int i = 0; i < probdiff.length; i++) {
      for (int j = 0; j < i; j++) {
        ans += probdiff[i] * alead[j];
      }
    }
    
    out.printf("%.10f\n", ans);
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
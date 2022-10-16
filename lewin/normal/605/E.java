import java.io.*;
import java.util.*;

public class intergalaxytrips {
  private static InputReader in;
  private static PrintWriter out;

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);

    int n = in.nextInt();
    int[][] prob = new int[n][n];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        prob[i][j] = in.nextInt();
      }
    }
    
    double[] exp = new double[n];
    double[] sum = new double[n];
    double[] div = new double[n];
    Arrays.fill(sum, 1);
    Arrays.fill(div, 1);
    Arrays.fill(exp, 1l << 60);
    exp[n-1] = 0;
    boolean[] vis = new boolean[n];
    for (int i = 0; i < n; i++) {
      double min = 1l << 60;
      int id = -1;
      for (int j = 0; j < n; j++) {
        if(!vis[j] && exp[j] < min) {
          min = exp[j];
          id = j;
        }
      }
      vis[id] = true;
      if (id == 0) break;
      
      for (int k = 0; k < n; k++) {
        if (vis[k] || prob[k][id] == 0) continue;
        sum[k] += div[k] * prob[k][id] / 100. * exp[id];
        div[k] *= (100. - prob[k][id]) / 100.;
        exp[k] = sum[k] / (1. - div[k]);
      }
    }
    out.printf("%.15f\n", exp[0]);
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
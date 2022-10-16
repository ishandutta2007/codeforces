import java.io.*;
import java.util.*;

public class littleartemmatrix {
  private static InputReader in;
  private static PrintWriter out;
  static class Query {
    public int t,r,c,x;
    public Query(int t, int r, int c, int x) {
      this.t = t;
      this.r = r;
      this.c = c;
      this.x = x;
    }
    public Query(int t, int r) {
      this.t = t;
      this.r = r;
    }
  }

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);

    int n = in.nextInt();
    int m = in.nextInt();
    int q = in.nextInt();
   
    Query[] qs= new Query[q];
    for (int i = 0; i < q; i++) {
      int t = in.nextInt();
      if (t == 1) {
        int r = in.nextInt()-1;
        qs[i] = new Query(t,r);
      } else if (t == 2) {
        int r = in.nextInt()-1;
        qs[i] = new Query(t,r);
      } else {
        int r = in.nextInt()-1, c = in.nextInt()-1, x = in.nextInt();
        qs[i] = new Query(t,r,c,x);
      }
    }
    int[][] arr = new int[n][m];
    for (int i = q-1; i >= 0; i--) {
      int t = qs[i].t;
      if (t == 1) {
        int tmp = arr[qs[i].r][m-1];
        for (int j = m-1; j >= 1; j--) {
          arr[qs[i].r][j] = arr[qs[i].r][j-1];
        }
        arr[qs[i].r][0] = tmp;
      } else if (t == 2) {
        int tmp = arr[n-1][qs[i].r];
        for (int j = n-1; j >= 1; j--) {
          arr[j][qs[i].r] = arr[j-1][qs[i].r];
        }
        arr[0][qs[i].r] = tmp;
      } else {
        arr[qs[i].r][qs[i].c] = qs[i].x;
      }
    }
    
    for (int i = 0; i <n; i++) {
      for (int j = 0; j < m; j++) {
        if (j != 0) out.print(" ");
        out.print(arr[i][j]);
      }
      out.println();
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
import java.io.*;
import java.util.*;

public class paintpebbles {
  private static InputReader in;
  private static PrintWriter out;
  
  static class Num implements Comparable<Num> {
    public int a,b;
    public Num(int a, int b) {
      this.a = a;
      this.b = b;
    }
    public int compareTo(Num other) {
      return a - other.a;
    }
  }

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);
    int N = in.nextInt(), K = in.nextInt();
    Num[] arr = new Num[N];

    int[][] r = new int[N][];
    int[] id = new int[N];
    for (int i = 0; i < N; i++) {
      arr[i] = new Num(in.nextInt(), i);
      r[i] = new int[arr[i].a];
    }
    Arrays.sort(arr);
    
    int m = arr[0].a+1;
    for (int k = 0; k < N; k++) {
      int take = Math.min(arr[k].a, m);
      arr[k].a -= take;
      while (take-->0) r[arr[k].b][id[arr[k].b]++] = 1;
    }
    
    int uc = 1;
    for (int j = 1; j < N; j++) {
      if (arr[j].a == 0) continue;
      while (arr[j].a > 0) {
        uc++;
        for (int k = j; k < N; k++) {
          arr[k].a--;
          r[arr[k].b][id[arr[k].b]++] = uc;
        }
      }
      
    }
    
    if (uc >= K+1) {
      out.println("NO");
    } else {
      out.println("YES");
      for (int i = 0; i < N; i++) {
        out.print(r[i][0]);
        for (int j = 1; j < r[i].length; j++)
          out.print(" "+r[i][j]);
        out.println();
      }
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
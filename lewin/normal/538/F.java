import java.io.*;
import java.util.*;

public class heapprob {
  private static InputReader in;
  private static PrintWriter out;

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);
    int N = in.nextInt();
    int[] a = new int[N];
    for (int i = 0; i < N; i++) a[i] = in.nextInt();
    int[] c = new int[N+1];
    for (int v = 1; v < N; v++) {
      int lowp = N-1;
      for (int k = 1; k * k < v - 1; k++) {
        int par = (v - 1) / k;
        lowp = par;
        if (a[v] < a[par]) {
          c[k]++;
          c[k+1]--;
        }
      }
      
      for (int k = 0; k < lowp; k++) {
        int par = k;
        if (a[v] < a[par]) {
          int low = (v - 1) / (k + 1) + 1, high = Math.min(N, (k == 0 ? N - 1 : ((v - 1) / k))) + 1;
          c[low]++;
          c[high]--;
        }
      }
    }
    
//    System.out.println(Arrays.toString(a));
    int x = 0;
    for (int i = 1; i < N; i++) {
      if (i != 1) out.print(" ");
      x += c[i];
      out.print(x);
    }
    out.println();
//    for (int i = 1; i < N; i++) {
//      if (i != 1) out.print(" ");
//      out.print(brute(i, a));
//    }
//    out.println();
    out.close();
    System.exit(0);
  }
  
  public static int brute(int k, int[] arr) {
    int count = 0;
    for (int i = 1; i < arr.length; i++) {
      int par = (i-1) / k;
      if (arr[i] < arr[par]) {
        count++;
      }
    }
    return count;
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
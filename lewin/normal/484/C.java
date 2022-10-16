import java.io.*;
import java.util.*;

public class strangesorting {
  private static BufferedReader in;
  private static PrintWriter out;
  public static int N;
  public static char[] let;
  public static int[] shiftright;
  public static StringBuffer ans;
  
  public static void shuffle (int k, int d) {
    int[] perm = new int[N];
    int idx = 0;
    for (int i = 0; i < d; i++) {
      for (int j = i; j < k; j += d) {
        perm[j] = idx++;
      }
    }
    for (int i = k; i < N; i++) perm[i] = i;
    perm = mult(shiftright, perm);
    
    int pow = N-k;
    int[] res = new int[N];
    System.arraycopy(perm, 0, res, 0, N);
    while (pow > 0) {
      if ((pow & 1) == 1) res = mult(res, perm);
      perm = mult(perm, perm);
      pow >>= 1;
    }
    
    char[] nlet = new char[N];
    for (int i = 0; i < N; i++) {
      nlet[(res[i] + N-k+1) % N] = let[i];
    }
    let = nlet;
    for (int i = 0; i < N; i++) {
      ans.append(let[i]);
    }
    ans.append("\n");
  }
  
  public static int[] mult(int[] a, int[] b) {
    int[] c = new int[N];
    for (int i = 0; i < N; i++) {
      c[i] = a[b[i]];
    }
    return c;
  }

  public static void main(String[] args) throws IOException {
    in = new BufferedReader(new InputStreamReader(System.in));
    out = new PrintWriter(System.out);
    
//    long start = System.currentTimeMillis();
    let = in.readLine().toCharArray();
    N = let.length;
    shiftright = new int[N];
    shiftright[0] = N-1;
    for (int i = 1; i < N; i++) shiftright[i] = i-1;
    int Q = Integer.parseInt(in.readLine());
    ans = new StringBuffer();
    StringTokenizer st;
    while (Q-- > 0) {
      st = new StringTokenizer(in.readLine());
      int K = Integer.parseInt(st.nextToken()), D = Integer.parseInt(st.nextToken());
      shuffle(K, D);
    }
    out.println(ans.toString());
//    System.out.println("Time: " + (System.currentTimeMillis() - start));
    out.close();
    System.exit(0);
  }
}
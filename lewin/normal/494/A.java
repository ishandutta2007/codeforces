import java.io.*;
import java.util.*;

public class treasure {
  private static Scanner in;
  private static PrintWriter out;

  public static void main(String[] args) throws IOException {
    in = new Scanner(System.in);
    out = new PrintWriter(System.out, true);
    char[] c = in.nextLine().toCharArray();
    int N = c.length;
    int count = 0;
    int[] val = new int[N];
    boolean neg = false;
    for (int i = 0; i < N; i++) {
      if (c[i] == '(') {
        count++;
      } else if (c[i] == ')') {
        count--;
        if (count < 0) neg = true;
      } else {
        count--;
        if (count < 0) neg = true;
      }
      val[i] = count;
    }
    if (neg) {
      out.println(-1);
      out.close();
      System.exit(0);
    }
    
    int[] min = new int[N+1];
    min[N] = 1 << 29;
    for (int i = N-1; i >= 0; i--) {
      min[i] = Math.min(min[i+1], val[i]);
    }
    
    ArrayList<Integer> res = new ArrayList<Integer>();
    int cursub = 0;
    for (int i = 0; i < N; i++) {
      if (c[i] == '#') {
        res.add(min[i] - cursub + 1);
        cursub = min[i];
      }
    }
    if (cursub != count) {
      out.println(-1);
    } else {
      for (int k : res) out.println(k);
    }
    out.close();
    System.exit(0);
  }
}
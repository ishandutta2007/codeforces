import java.io.PrintWriter;
import java.util.Scanner;


public class PermutationFinder {
  public static void main (String[] args) {
    Scanner in = new Scanner (System.in);
    PrintWriter out = new PrintWriter (System.out, true);
    
    int N = in.nextInt();
    long K = in.nextLong();
    
    long[] fib = new long[N+1];
    fib[0] = fib[1] = 1;
    for (int i = 2; i <= N; i++) fib[i] = fib[i-1]+fib[i-2];
    
    int idx = 0;
    int[] res = new int[N];
    while (idx < N) {
      if (K <= fib[N-idx-1]) {
        res[idx] = idx+1;
        idx++;
      } else {
        K -= fib[N-idx-1];
        res[idx] = idx+2;
        res[idx+1] = idx+1;
        idx += 2;
      }
    }
    
    for (int i = 0; i < N; i++) {
      if (i != 0) out.print(" ");
      out.print(res[i]);
    }
    out.println();
    out.close();
    System.exit(0);
  }
}
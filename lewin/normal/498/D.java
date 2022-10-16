import java.io.*;
import java.util.*;

public class trafficjamsinland {
  private static Scanner in;
  private static PrintWriter out;
  public static int BLOCK_SIZE = 300, LCM = 60,
            NUM_BLOCKS, N, Q, a[], tc[][];

  public static void main(String[] args) {
    in = new Scanner(System.in);
    out = new PrintWriter(System.out, true);
    
    N = in.nextInt();
    a = new int[N];
    for (int i = 0; i < N; i++) 
      a[i] = in.nextInt();
    
    NUM_BLOCKS = N / BLOCK_SIZE + 1;
    tc = new int[NUM_BLOCKS][LCM];
    for (int i = 0; i < NUM_BLOCKS; i++)
      Arrays.fill(tc[i], -1);
    
    Q = in.nextInt();
    while (Q-- > 0) {
      char cmd = in.next().charAt(0);
      if (cmd == 'C') {
        int x = in.nextInt()-1;
        a[x] = in.nextInt();
        Arrays.fill(tc[x / BLOCK_SIZE], -1);
      } else {
        int from = in.nextInt()-1, to = in.nextInt()-2, idx1 = from / BLOCK_SIZE, idx2 = to / BLOCK_SIZE;
        if (idx1 == idx2) {
          out.println(slowSolve(from, to, 0));
        } else {
          int res = slowSolve(from, (idx1+1) * BLOCK_SIZE-1, 0);
          for (int j = idx1+1; j < idx2; j++) {
            int k = res % LCM;
            if (tc[j][k] == -1) fix(j, k);
            res += tc[j][k];
          }
          res += slowSolve(idx2 * BLOCK_SIZE, to, res % LCM);
          out.println(res);
        }
      }
    }
    out.close();
    System.exit(0);
  }
  
  public static void fix(int j, int m) {
    int start = j * BLOCK_SIZE, end = Math.min(N-1, start + BLOCK_SIZE-1);
    tc[j][m] = slowSolve(start, end, m);
  }
  
  public static int slowSolve(int from, int to, int b) {
    int ct = 0;
    for (int j = from; j <= to; j++)
      ct += (ct + b) % a[j] == 0 ? 2 : 1;
    return ct;
  }
}
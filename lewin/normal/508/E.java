import java.io.*;
import java.util.*;

public class arthurbracket {
  private static BufferedReader in;
  private static PrintWriter out;
  
  public static int[][] next;
  public static int[] L, R;
  public static int N;

  public static void main(String[] args) throws IOException {
    in = new BufferedReader(new InputStreamReader(System.in));
    out = new PrintWriter(System.out, true);
    N = Integer.parseInt(in.readLine());
    L = new int[N];
    R = new int[N];
    StringTokenizer st;
    for (int i = 0; i < N; i++) {
      st = new StringTokenizer(in.readLine());
      L[i] = Integer.parseInt(st.nextToken());
      R[i] = Integer.parseInt(st.nextToken());
    }
    next = new int[N][N];
    for (int i = 0; i < N; i++) {
      if (L[i] == 1) next[i][i] = 1;
    }
    for (int len = 2; len <= N; len++) {
      for (int start = N-len; start >= 0; start--) {
        int end = start+len-1;
        for (int j = L[start]; j <= R[start]; j++) {
          if (j % 2 == 0) continue;
          int gap = (j+1)/2;
          if (start+gap > end+1) continue;
          if ((gap-1 >= 1 ? next[start+1][start+gap-1]>0 : true) 
              && (start+gap <= end ? next[start+gap][end]>0 : true)) {
            next[start][end] = j;
            break;
          }
        }
      }
    }
    
    if (next[0][N-1]==0) {
      out.println("IMPOSSIBLE");
    } else {
      fill(0, N-1, 0);
      out.println();
    }
    out.close();
    System.exit(0);
  }
  public static void fill(int start, int end, int pos) {
    if (start > end) return;
    int j = next[start][end];
    
    int gap = (j+1)/2;
    out.print('(');
    fill(start+1, start+gap-1, pos+1);
    out.print(')');
    fill(start+gap, end, pos+j+1);
  }
}
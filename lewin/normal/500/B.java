import java.io.*;
import java.util.*;

public class nyperm {
  private static BufferedReader in;
  private static PrintWriter out;

  public static void main(String[] args) throws IOException {
    in = new BufferedReader(new InputStreamReader (System.in));
    out = new PrintWriter(System.out, true);
    
    int N = Integer.parseInt(in.readLine());
    int[] perm = new int[N];
    StringTokenizer st = new StringTokenizer(in.readLine());
    for (int i = 0; i < N; i++) perm[i] = Integer.parseInt(st.nextToken())-1;
    boolean[][] swap = new boolean[N][N];
    for (int i = 0; i < N; i++) {
      String s = in.readLine();
      for (int j = 0; j < N; j++) {
        swap[i][j] = s.charAt(j) == '1';
      }
    }
    
    for (int k = 0; k < N; k++)
      for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
          swap[i][j] |= swap[i][k] && swap[k][j];
    
    for (int k = 0; k < N; k++) {
      for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
          if (swap[i][j] && perm[i] > perm[j]) {
            int t = perm[i];
            perm[i] = perm[j];
            perm[j] = t;
          }
        }
      }
    }
    
    for (int i = 0; i < N; i++) {
      if (i > 0) out.print(" ");
      out.print(perm[i]+1);
    }
    out.println();
    out.close();
    System.exit(0);
  }
}
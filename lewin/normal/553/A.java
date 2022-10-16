import java.io.*;
import java.util.*;

public class ColoredBalls {
  public static int mod = 1000000007;
  public static int MAXN = 1010;
  
  public static void main (String[] args) {
    Scanner in = new Scanner(System.in);
    PrintWriter out = new PrintWriter(System.out, true);
    
    long[][] comb = new long[MAXN][MAXN];
    comb[0][0] = 1;
    for (int i = 1; i < MAXN; i++) {
      comb[i][0] = 1;
      for (int j = 1; j <= i; j++) {
        comb[i][j] = (comb[i-1][j] + comb[i-1][j-1]) % mod;
      }
    }
    
    int K = in.nextInt();
    int[] color = new int[K];
    for (int i = 0; i < K; i++) color[i] = in.nextInt();
    
    long res = 1;
    int total = 0;
    for (int i = 0; i < K; i++) {
      res = (res * comb[total + color[i] - 1][color[i] - 1]) % mod;
      total += color[i];
    }
    
    out.println(res);
    out.close();
    System.exit(0);
  }
}
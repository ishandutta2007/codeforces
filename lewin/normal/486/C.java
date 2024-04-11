import java.io.*;
import java.util.*;

public class palindrometransform {

  private static BufferedReader in;
  private static PrintWriter out;

  public static void main(String[] args) throws IOException {
    in = new BufferedReader(new InputStreamReader(System.in));
    out = new PrintWriter(System.out, true);
    StringTokenizer st = new StringTokenizer (in.readLine());
    int N = Integer.parseInt(st.nextToken()), P = Integer.parseInt(st.nextToken());
    char[] c = in.readLine().toCharArray();
    
    int ans = 0;
    boolean[] needchange = new boolean[(N+1)/2];
    int count = 0;
    for (int i = 0; i < (N+1)/2; i++) {
      int dist = Math.abs(c[i] - c[N - i - 1]);
      dist = Math.min(dist, 26 - dist);
      ans += dist;
      needchange[i] = dist > 0;
      if (needchange[i]) count++;
    }
    P--;
    if (P >= (N+1)/2) P = N - P - 1;
    
    if (count > 0) {
      // go right
      int begin = 0;
      for (int i = 0; i < (N+1)/2; i++) {
        if (needchange[i]) {
          begin = i;
          break;
        }
      }
      
      int end = 0;
      for (int i = (N+1)/2-1; i >= 0; i--) {
        if(needchange[i]) { 
          end = i;
          break;
        }
      }
      
      ans += Math.min(Math.abs(P-begin), Math.abs(end-P)) + end-begin;
    }
    out.println(ans);
    out.close();
    System.exit(0);
  }
}
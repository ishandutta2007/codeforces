import java.io.*;
import java.util.*;

public class hackingcipher {
  private static BufferedReader in;
  private static PrintWriter out;

  public static void main(String[] args) throws IOException {
    in = new BufferedReader(new InputStreamReader(System.in));
    out = new PrintWriter(System.out, true);
    
    char[] c = in.readLine().toCharArray();
    int N = c.length;
    StringTokenizer st = new StringTokenizer(in.readLine());
    long A = Integer.parseInt(st.nextToken()), B = Integer.parseInt(st.nextToken());
    if (c[0] == '0') {
      out.println("NO");
    } else {
      boolean[] oka = new boolean[N];
      long curmod = 0;
      for (int i = 0; i < N; i++) {
        curmod = (curmod*10+c[i]-'0')%A;
        if (curmod == 0) {
          oka[i] = true;
        }
      }
      
      curmod = 0;
      long pow10 = 1;
      for (int i = N-1; i >= 1; i--) {
        curmod = (curmod+pow10*(c[i]-'0'))%B;
        pow10 = (pow10*10) % B;
        if (c[i] != '0' && curmod == 0 && oka[i-1]) {
          out.println("YES");
          out.println(new String(c, 0, i));
          out.println(new String(c, i, N-i));
          out.close();
          System.exit(0);
        }
      }
      out.println("NO");
    }
    out.close();
    System.exit(0);
  }
}
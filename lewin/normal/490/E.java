import java.io.*;
import java.util.*;

public class restincseq {
  private static BufferedReader in;
  private static PrintWriter out;

  public static void main(String[] args) throws IOException {
    in = new BufferedReader(new InputStreamReader(System.in));
    out = new PrintWriter(System.out, true);
    int N = Integer.parseInt(in.readLine());
    char[][] s = new char[N][];
    for (int i = 0; i < N; i++)
      s[i] = in.readLine().toCharArray();
    for (int i = 0; i < s[0].length; i++)
      if (s[0][i] == '?')
        s[0][i] = i == 0 ? '1' : '0';
    boolean ok = true;
    for (int i = 1; ok && i < N; i++) {
      ok &= fix(s[i-1], s[i]);
    }
    if (ok) {
      out.println("YES");
      for (int i = 0; i < N; i++)
        out.println(new String(s[i]));
    } else {
      out.println("NO");
    }
    out.close();
    System.exit(0);
  }
  public static boolean fix(char[] a, char[] b) {
    if (a.length > b.length) return false;
    if (b.length > a.length) {
      if (b[0] == '?') b[0] = '1';
      for (int i = 1; i < b.length; i++) {
        if (b[i] == '?') b[i] = '0';
      }
      return true;
    }
    if (!canPlace(a, b)) return false;
    for (int i = 0; i < b.length; i++) {
      if (b[i] == '?') {
        for (int j = i == 0 ? 1 : 0; j <= 9; j++) {
          b[i] = (char)(j + '0');
          if (canPlace(a, b)) {
            break;
          }
        }
      }
    }
    return true;
  }
  
  public static boolean canPlace(char[] a, char[] b) {
    char[] c = new char[b.length];
    System.arraycopy(b, 0, c, 0, b.length);
    for (int i = 0; i < c.length; i++) if (c[i] == '?') c[i] = '9';
    for (int i = 0; i < a.length; i++) {
      if (a[i] < c[i]) return true;
      if (a[i] > c[i]) return false;
    }
    return false;
  }
}
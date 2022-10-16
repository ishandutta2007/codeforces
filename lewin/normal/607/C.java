import java.io.*;
import java.util.*;

public class marbles {
  private static InputReader in;
  private static PrintWriter out;

  public static int[] zAlgorithm(char[] let) {
    int N = let.length;
    int[] z = new int[N];
    int L = 0, R = 0;
    for (int i = 1; i < N; i++) {
      if (i > R) {
        L = R = i;
        while (R < N && let[R - L] == let[R])
          R++;
        z[i] = R - L;
        R--;
      } else {
        int k = i - L;
        if (z[k] < R - i + 1)
          z[i] = z[k];
        else {
          L = i;
          while (R < N && let[R - L] == let[R])
            R++;
          z[i] = R - L;
          R--;
        }
      }
    }
    z[0] = N;
    return z;
  }
  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);
    int n = in.nextInt();
    char[] s1 = in.next().toCharArray();
    char[] s2 = in.next().toCharArray();
    char[] rf = new char[s2.length];
    for (int i = 0; i < s2.length; i++) {
      rf[i] = s2[s2.length-i-1];
      if (rf[i] == 'N') rf[i] = 'S';
      else if (rf[i] == 'S') rf[i] = 'N';
      else if (rf[i] == 'W') rf[i] = 'E';
      else if (rf[i] == 'E') rf[i] = 'W';
    }
    char[] concat = new char[s1.length+s2.length+1];
    System.arraycopy(rf, 0, concat, 0, rf.length);
    concat[s1.length] = '$';
    System.arraycopy(s1, 0, concat, s1.length+1, s1.length);
    int[] z = zAlgorithm(concat);
    boolean ok = true;
    for (int i = s1.length+1; i < concat.length; i++) {
      if (z[i] + i - s1.length - 1 == s1.length) {
        ok = false;
        break;
      }
    }
    out.println(ok?"YES":"NO");

//    for (int iter = 0; iter <= 100; iter++) {
//    int n = 10;
//    char[] s1 = new char[n-1], s2 = new char[n-1];
//    char[] o1 = new char[n-1], o2 = new char[n-1];
//    for (int i = 0; i < n-1; i++) {
//      int d = (int)(Math.random()*4);
//      s1[i] = x1[d];
//      o1[i] = x2[d];
//      d = (int)(Math.random()*4);
//      s2[i] = x1[d];
//      o2[i] = x2[d];
//    }
//
//    char[] rf = new char[s2.length];
//    for (int i = 0; i < s2.length; i++) {
//      rf[i] = s2[s2.length-i-1];
//      if (rf[i] == 'N') rf[i] = 'S';
//      else if (rf[i] == 'S') rf[i] = 'N';
//      else if (rf[i] == 'W') rf[i] = 'E';
//      else if (rf[i] == 'E') rf[i] = 'W';
//    }
//    char[] concat = new char[s1.length+s2.length+1];
//    System.arraycopy(rf, 0, concat, 0, rf.length);
//    concat[s1.length] = '$';
//    System.arraycopy(s1, 0, concat, s1.length+1, s1.length);
//    int[] z = zAlgorithm(concat);
//    boolean ok = true;
//    for (int i = s1.length+1; i < concat.length; i++) {
//      if (z[i] + i - s1.length - 1 == s1.length) {
//        ok = false;
//        break;
//      }
//    }
////    out.println(ok?"YES":"NO");
////    out.println(can(s1,s2)?"YES":"NO");
//    if (ok != can(s1,s2)) {
//      System.out.println(new String(s1)+" "+new String(s2)+" "+new String(concat)+" "+ok+" "+can(s1,s2));
//      out.println("BAAAD!!!");
//    }
//    }
    out.close();
    System.exit(0);
  }
  
  public static char[] x1 = "NSEW".toCharArray();
  public static char[] x2 = "SNWE".toCharArray();
  public static boolean can(char[] s1, char[] s2) {
    int n = s1.length+1;
    boolean[][] reach = new boolean[n][n];
    reach[0][0] = true;
    int[] queue = new int[n*n];
    int[][] par = new int[n][n];
    int[][] prev = new int[n][n];
    int front = 0, back = 0;
    queue[back++] = 0*n+0;
    while (front < back) {
      int x = queue[front++];
      int a = x/n, b = x%n;
      
      for (int i = 0; i < 4; i++) {
        int na = a, nb = b;
        if (a < n-1 && s1[a] == x1[i]) na++;
        else if (a > 0 && s1[a-1] == x2[i]) na--;
        if (b < n-1 && s2[b] == x1[i]) nb++;
        else if (b > 0 && s2[b-1] == x2[i]) nb--;
        if (!reach[na][nb]) {
          reach[na][nb] = true;
          queue[back++] = na*n+nb;
          par[na][nb] = i;
          prev[na][nb] = a*n+b;
        }
      }
    }
    if (!reach[n-1][n-1]) return false;
    StringBuilder bb = new StringBuilder();
    int ca = n-1, cb = n-1;
    while (ca != 0 || cb != 0) {
      bb.append(x1[par[ca][cb]]);
      int xx = prev[ca][cb];
      ca = xx/n;
      cb = xx%n;
    }
    bb.reverse();
//    System.out.println(bb.toString());
    return true;
  }

  static class InputReader {
    public BufferedReader reader;
    public StringTokenizer tokenizer;

    public InputReader(InputStream stream) {
      reader = new BufferedReader(new InputStreamReader(stream), 32768);
      tokenizer = null;
    }

    public String next() {
      while (tokenizer == null || !tokenizer.hasMoreTokens()) {
        try {
          tokenizer = new StringTokenizer(reader.readLine());
        } catch (IOException e) {
          throw new RuntimeException(e);
        }
      }
      return tokenizer.nextToken();
    }

    public int nextInt() {
      return Integer.parseInt(next());
    }
  }


}
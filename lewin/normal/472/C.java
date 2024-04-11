import java.io.*;
import java.util.*;

public class sname {
  private static BufferedReader in;
  private static PrintWriter out;

  public static void main(String[] args) throws IOException {
    in = new BufferedReader(new InputStreamReader (System.in));
    out = new PrintWriter(System.out, true);
    
    int N = Integer.parseInt(in.readLine());
    String[][] names = new String[N][2];
    for (int i = 0; i < N; i++) {
      names[i] = in.readLine().split("\\s");
    }
    int[] perm = new int[N];
    StringTokenizer st = new StringTokenizer(in.readLine());
    for (int i = 0; i < N; i++) {
      perm[i] = Integer.parseInt(st.nextToken()) - 1;
    }
    
    String pname = "";
    if (names[perm[0]][0].compareTo(names[perm[0]][1]) < 0)
      pname = names[perm[0]][0];
    else
      pname = names[perm[0]][1];
    for (int i = 1; i < N; i++) {
      if (names[perm[i]][0].compareTo(pname) > 0 && names[perm[i]][1].compareTo(pname) > 0) {
        if (names[perm[i]][0].compareTo(names[perm[i]][1]) < 0)
          pname = names[perm[i]][0];
        else
          pname = names[perm[i]][1];
      } else if (names[perm[i]][0].compareTo(pname) > 0) {
        pname = names[perm[i]][0];
      } else if (names[perm[i]][1].compareTo(pname) > 0) {
        pname = names[perm[i]][1];
      } else {
        out.println("NO");
        out.close();
        System.exit(0);
      }
    }
    out.println("YES");
    out.close();
    System.exit(0);
  }
}
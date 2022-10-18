import java.io.*;
import java.util.*;

public class B_new {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;

    void solve() throws IOException {
        int n = nextInt();
        int zayac = nextInt() - 1;
        int contr = nextInt() - 1;
        String dir = nextString();
        int dContr = 0;
        if (dir.equals("to head"))
            dContr = -1;
        else
            dContr = 1;
        char[] move = nextString().toCharArray();
        for (int i = 0; i < move.length - 1; i++) {
            if (move[i] == '0') {
                if (zayac > contr) {
                    zayac = Math.min(zayac + 1, n - 1);
                } else if (zayac < contr)
                    zayac = Math.max(zayac - 1, 0);
            }
            contr += dContr;
            if (contr == -1 || contr == n) {
                contr -= dContr;
                dContr = -dContr;
                contr += dContr;
            }
            if (move[i] == '0' && zayac == contr) {
                out.println("Controller " + (i + 1));
                return;
            }
            if (move[i] == '1') {
                if (dContr == 1)
                    zayac = 0;
                else
                    zayac = n - 1;
            }
//          if (zayac == contr) {
//              out.println("Controller " + (i + 1));
//              return;
//          }
        }
        out.println("Stowaway");
    }

    void inp() throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
        solve();
        out.close();
    }

    public static void main(String[] args) throws IOException {
        new B_new().inp();
    }

    String nextToken() {
        while (st == null || !st.hasMoreTokens()) {
            try {
                st = new StringTokenizer(br.readLine());
            } catch (Exception e) {
                eof = true;
                return "0";
            }
        }
        return st.nextToken();
    }

    String nextString() {
        while (st == null || !st.hasMoreTokens()) {
            try {
                st = new StringTokenizer(br.readLine());
            } catch (Exception e) {
                eof = true;
                return "0";
            }
        }
        return st.nextToken("\n");
    }

    int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

}
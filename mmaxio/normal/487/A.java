import java.io.*;
import java.util.*;

public class A {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;

    void solve() throws IOException {
        int h1 = nextInt();
        int atk1 = nextInt();
        int def1 = nextInt();
        int h2 = nextInt();
        int atk2 = nextInt();
        int def2 = nextInt();
        int ch = nextInt();
        int cAtk = nextInt();
        int cDef = nextInt();

        int ans = Integer.MAX_VALUE / 2;

        for (int bA = 0; bA < 2000; bA++)
            for (int bD = 0; bD < 2000; bD++) {
                int need = bA * cAtk + bD * cDef;
                int dmg1 = Math.max(atk1 + bA - def2, 0);
                int dmg2 = Math.max(atk2 - def1 - bD, 0);
                
                if (dmg1 == 0) {
                    continue;
                }
                if (dmg2 == 0) {
                    ans = Math.min(ans, need);
                    continue;
                }
                int die = (h2 + dmg1 - 1) / dmg1;
                
                int we = Math.max(1 - (h1 - die * dmg2), 0);
//              if (need == 0) {
//                  System.err.println(die);
//                  System.err.println(we);
//              }
                ans = Math.min(ans, need + we * ch);
            }
        out.println(ans);
    }

    boolean win(int h1, int atk1, int def1, int h2, int atk2, int def2) {
        int dmg1 = Math.max(atk1 - def2, 0);
        int dmg2 = Math.max(atk2 - def1, 0);
        if (dmg1 == 0) {
            return false;
        }
        if (dmg2 == 0) {
            return true;
        }
        int need = (h2 + dmg1 - 1) / dmg1;
        return h1 - need * dmg2 > 0;
    }

    A() throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
        solve();
        out.close();
    }

    public static void main(String[] args) throws IOException {
        new A();
    }

    String nextToken() {
        while (st == null || !st.hasMoreTokens()) {
            try {
                st = new StringTokenizer(br.readLine());
            } catch (Exception e) {
                eof = true;
                return null;
            }
        }
        return st.nextToken();
    }

    String nextString() {
        try {
            return br.readLine();
        } catch (IOException e) {
            eof = true;
            return null;
        }
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
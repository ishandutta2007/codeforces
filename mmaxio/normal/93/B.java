import java.io.*;
import java.util.*;

public class B {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;

    final double EPS = 1e-7;

    boolean eq0(double x) {
        return Math.abs(x) < EPS;
    }

    void solve() throws IOException {
        int n = nextInt();
        int w = nextInt();
        int m = nextInt();

        double cup = 1.0 * n * w / m;

        ArrayList<Integer>[] num = new ArrayList[m];
        ArrayList<Double>[] vol = new ArrayList[m];

        for (int i = 0; i < m; i++) {
            num[i] = new ArrayList<Integer>();
            vol[i] = new ArrayList<Double>();
        }

        int curBottle = 0, curCup = 0;
        double leftBottle = w, leftCup = cup;

        int cnt = 0;

        while (curBottle < n) {
            double go = Math.min(leftBottle, leftCup);
            num[curCup].add(curBottle + 1);
            vol[curCup].add(go);

            leftBottle -= go;
            leftCup -= go;

            if (eq0(leftCup)) {
                leftCup = cup;
                curCup++;
                cnt++;
            }

            if (eq0(leftBottle)) {
                leftBottle = w;
                curBottle++;
                cnt = 0;
            }

            if (cnt == 2) {
                out.print("NO");
                return;
            }
        }

        out.println("YES");
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < num[i].size(); j++)
                out.printf("%d %.9f ", num[i].get(j), vol[i].get(j));
            out.println();
        }
    }

    void inp() throws IOException {
        Locale.setDefault(Locale.US);
        br = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
        solve();
        out.close();
    }

    public static void main(String[] args) throws IOException {
        new B().inp();
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
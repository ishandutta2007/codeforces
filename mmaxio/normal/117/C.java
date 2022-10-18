import java.io.*;
import java.util.*;

public class C {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;

    char[][] f;

    boolean go(ArrayList<Integer> ls) {
        //System.err.println(ls);
        if (ls.size() < 3)
            return false;

        int v = ls.get(ls.size() / 2);

        ArrayList<Integer> left = new ArrayList<Integer>();
        ArrayList<Integer> right = new ArrayList<Integer>();

        for (int i = 0; i < ls.size(); i++)
            if (i != ls.size() / 2) {
                if (f[ls.get(i)][v] == '1')
                    left.add(ls.get(i));
                else
                    right.add(ls.get(i));
            }

        for (int i = 0; i < left.size(); i++)
            for (int j = 0; j < right.size(); j++) {
                if (f[right.get(j)][left.get(i)] == '1') {
                    out.print((left.get(i) + 1) + " " + (v + 1) + " "
                            + (right.get(j) + 1));
                    return true;
                }
            }

        if (go(left))
            return true;
        if (go(right))
            return true;
        
        return false;
    }

    void solve() throws IOException {

        int n = nextInt();
        f = new char[n][];

        int[] deg = new int[n];

        for (int i = 0; i < n; i++) {
            f[i] = nextToken().toCharArray();
            for (int j = 0; j < n; j++)
                if (f[i][j] == '1')
                    deg[i]++;
        }

        boolean fail = true;
        Arrays.sort(deg);
        for (int i = 0; i < n; i++)
            if (deg[i] != i) {
                fail = false;
                break;
            }

        if (fail) {
            out.print(-1);
            return;
        }

        ArrayList<Integer> ls = new ArrayList<Integer>();
        for (int i = 0; i < n; i++)
            ls.add(i);

        go(ls);

    }

    void inp() throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
        solve();
        out.close();
    }

    public static void main(String[] args) throws IOException {
        new C().inp();
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
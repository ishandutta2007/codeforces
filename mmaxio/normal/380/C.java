import java.io.*;
import java.util.*;

public class C {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;

    void add(int[] f, int pos) {
        for (int i = pos; i < f.length; i |= i + 1) {
            f[i]++;
        }
    }

    int get(int[] f, int pos) {
        int ret = 0;
        for (int i = pos; i >= 0; i = (i & (i + 1)) - 1)
            ret += f[i];
        return ret;
    }

    void solve() throws IOException {
        char[] s = nextToken().toCharArray();
        int[] op = new int[s.length];
        int szOp = 0;

        int[] corrOpen = new int[s.length];
        int[] corrClose = new int[s.length];
        int szCorr = 0;

        for (int i = 0; i < s.length; i++) {
            if (s[i] == '(') {
                op[szOp++] = i;
            } else {
                if (szOp == 0)
                    continue;
                corrOpen[szCorr] = op[--szOp];
                corrClose[szCorr] = i;
                szCorr++;
            }
        }

        int q = nextInt();
        Query[] qq = new Query[q];
        for (int i = 0; i < q; i++) {
            qq[i] = new Query(nextInt() - 1, nextInt() - 1, i);
        }

        Arrays.sort(qq);

        int[] ans = new int[q];
        int[] fen = new int[s.length];

        for (int i = 0, j = 0; i < q; i++) {
            Query cur = qq[i];
            while (j < szCorr && corrClose[j] <= cur.r) {
                add(fen, corrOpen[j++]);
            }
            ans[cur.ind] = get(fen, cur.r) - get(fen, cur.l - 1);
        }
        
        for (int i = 0; i < q; i++) {
            out.println(ans[i] << 1);
        }

    }

    static class Query implements Comparable<Query> {
        int l, r, ind;

        public Query(int l, int r, int ind) {
            this.l = l;
            this.r = r;
            this.ind = ind;
        }

        @Override
        public int compareTo(Query o) {
            return Integer.compare(r, o.r);
        }

    }

    C() throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
        solve();
        out.close();
    }

    public static void main(String[] args) throws IOException {
        new C();
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
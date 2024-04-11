import java.io.*;
import java.util.*;

public class C_new {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;

    char[] s;
    int n;

    int[] getTail(int[] p) {
        int len = 0;
        for (int i = p.length - 1; i >= 0; i = p[i]) {
            len++;
        }
        int[] ret = new int[len];
        for (int i = p.length - 1, j = 0; j < len; i = p[i], j++) {
            ret[j] = i;
        }
        return ret;
    }

    void shuffle(int k, int d) {
        int[] p = new int[k];
        for (int i = 0, z = 0; i < d; i++)
            for (int j = i; j < k; j += d) {
                p[j] = z++;
            }
        for (int i = 0; i < k; i++) {
            p[i]--;
        }
        int[] tail = getTail(p);
        boolean[] vis = new boolean[k];
        for (int i = 0; i < tail.length; i++) {
            vis[tail[i]] = true;
        }
        char[] newS = new char[n];
        Arrays.fill(newS, '*');

        int spins = n - k + 1;

        // initially in tail
        for (int i = 0; i < tail.length; i++) {
            if (i + spins >= tail.length) {
                // end in -1
                newS[tail.length - 1 - i] = s[tail[i]];
            } else {
                // didn't leave tail
                int endTailPos = i + spins;
                int endPos = tail[endTailPos];
                newS[n - k + endPos + 1] = s[tail[i]];
            }
        }

//      System.err.println(Arrays.toString(tail));
        // starts in the end of tail
        for (int i = k; i < n; i++) {
            int endTailPos = n - i;
            // System.err.println(i + " " + endTailPos);
            if (endTailPos >= tail.length) {
                // ended in -1
                newS[tail.length - k + i] = s[i];
            } else {
                int endPos = tail[endTailPos];
                newS[n - k + endPos + 1] = s[i];
            }
        }

        // cycles left!
        // this shit works i think...
        for (int i = 0; i < k; i++) {
            if (!vis[i]) {
                int[] c = getCycle(p, i);
                for (int j = 0; j < c.length; j++) {
                    vis[c[j]] = true;
                    int endPosCycle = (j + n - k + 1) % c.length;
                    int endPos = c[endPosCycle];
                    newS[n - k + endPos + 1] = s[c[j]];
                }
            }
        }
        s = newS;
    }

    int[] getCycle(int[] p, int from) {
        int len = 1;
        for (int i = p[from]; i != from; i = p[i]) {
            len++;
        }
        int[] ret = new int[len];
        ret[0] = from;
        for (int i = p[from], j = 1; j < len; i = p[i], j++) {
            ret[j] = i;
        }
        return ret;
    }

    void solve() throws IOException {
        s = nextToken().toCharArray();
        n = s.length;
        int q = nextInt();
        while (q-- > 0) {
            int k = nextInt();
            int d = nextInt();
            shuffle(k, d);
            out.println(new String(s));
        }
    }

    C_new() throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
        solve();
        out.close();
    }

    public static void main(String[] args) throws IOException {
        new C_new();
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
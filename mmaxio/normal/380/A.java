import java.io.*;
import java.util.*;

public class A {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;

    static final int NEED = 100_000;

    void solve() throws IOException {
        int m = nextInt();

        int[] a = new int[NEED];
        int sz = 0;

        long realSize = 0;
        long[] memo = new long[m];

        int[] types = new int[m];
        int[] par0 = new int[m];
        int[] par1 = new int[m];

        for (int i = 0; i < m; i++) {

            memo[i] = realSize;

            types[i] = nextInt();
            if (types[i] == 1) {
                par0[i] = nextInt();
                if (sz < NEED) {
                    a[sz++] = par0[i];
                }
                realSize++;
            } else {
                par0[i] = nextInt(); // length
                par1[i] = nextInt(); // count
                long tot = (long) par0[i] * par1[i];
                realSize += tot;
                for (int j = 0; j < tot && sz < NEED; j++) {
                    a[sz++] = a[j % par0[i]];
                }
            }
        }

        int q = nextInt();
        while (q-- > 0) {
            long ind = nextLong() - 1;
            int pos = Arrays.binarySearch(memo, ind);
            if (pos < 0) {
                pos = -pos - 2;
            }
            if (types[pos] == 1) {
                out.print(par0[pos] + " ");
            } else {
                long realPos = (ind - memo[pos]) % par0[pos];
                out.print(a[(int)realPos] + " ");
            }
        }
        
        out.println();
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
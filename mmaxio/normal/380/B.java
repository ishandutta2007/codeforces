import java.io.*;
import java.util.*;

public class B {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;

    int f(int x) {
        int ret = 0;
        while (x > 0) {
            ret++;
            x >>= 1;
        }
        return ret;
    }

    boolean isPow2(int x) {
        if (x == 0) {
            throw new AssertionError();
        }
        return (x & (x - 1)) == 0;
    }

    void solve() throws IOException {
        int n = nextInt();
        int q = nextInt();

        int[] sz = new int[n + 1];
        sz[1] = 1;
        for (int i = 1; i < n; i++) {
            sz[i + 1] = sz[i] + f(sz[i]);
        }

        int[] up = new int[sz[n] + 1];

        for (int par = 1, child = 1; child <= sz[n]; par++) {
            up[child++] = par;
            if (isPow2(par)) {
                if (child <= sz[n]) {
                    up[child++] = par;
                }
            }
        }

        List<int[]> add = new ArrayList<>();
        List<int[]> ans = new ArrayList<>();

        for (int i = 0; i < q; i++) {
            int type = nextInt();
            if (type == 1) {
                int[] tmp = { nextInt(), nextInt(), nextInt(), nextInt(), i };
                add.add(tmp);
            } else {
                int[] tmp = { nextInt(), nextInt(), i };
                ans.add(tmp);
            }
        }

        int[] outp = new int[ans.size()];
        Set<Integer> set = new HashSet<>();

        for (int level = n; level >= 1; level--) {
            for (int i = 0; i < ans.size(); i++) {
                if (ans.get(i)[0] == level) {
                    set.clear();
                    int pos = ans.get(i)[1];
                    int when = ans.get(i)[2];
                    for (int j = 0; j < add.size(); j++) {
                        int[] tmp = add.get(j);
                        // System.err.println(Arrays.toString(tmp));
                        if (tmp[0] == level && tmp[1] <= pos && pos <= tmp[2] && when > tmp[4]) {
                            set.add(tmp[3]);
                        }
                    }
                    outp[i] = set.size();
                }
            }

            for (int i = 0; i < add.size(); i++) {
                int[] tmp = add.get(i);
                if (tmp[0] == level) {
                    tmp[0]--;
                    tmp[1] = up[tmp[1]];
                    tmp[2] = up[tmp[2]];
                }
            }

        }

        for (int x : outp) {
            out.println(x);
        }

    }

    B() throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
        solve();
        out.close();
    }

    public static void main(String[] args) throws IOException {
        new B();
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
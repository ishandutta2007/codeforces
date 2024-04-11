import java.io.*;
import java.util.*;

public class B {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;

    void solve() throws IOException {
        int n = nextInt();
        int q = nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = nextInt();
        }

        final int[] b = new int[n - 1];
        for (int i = 0; i < n - 1; i++) {
            b[i] = Math.abs(a[i + 1] - a[i]);
        }

        Integer[] order = new Integer[n - 1];
        for (int i = 0; i < n - 1; i++) {
            order[i] = i;
        }
        Arrays.sort(order, new Comparator<Integer>() {

            @Override
            public int compare(Integer o1, Integer o2) {
                return Integer.compare(b[o1], b[o2]);
            }

        });

        int[] left = new int[n + 1];
        int[] right = new int[n + 1];

        for (int i = 0; i < q; i++) {
            int l = nextInt() - 1;
            int r = nextInt() - 2;

            Arrays.fill(left, -1);
            Arrays.fill(right, -1);

            long outp = 0;

            for (int j = 0; j < n - 1; j++) {
                int pos = order[j];
                int val = b[pos];
                if (pos < l || pos > r) {
                    continue;
                }

                int newL = left[pos] == -1 ? pos + 1 : left[pos];
                int newR = right[pos + 2] == -1 ? pos + 1 : right[pos + 2];
                
//              System.err.println(pos + " " + newL + " " + newR);
                
                outp += (long) val * (pos + 1 - newL + 1) * (newR - (pos + 1) + 1);
                right[newL] = newR;
                left[newR] = newL;
            }

            out.println(outp);
        }
    }

    int[] unique(int[] a) {
        Arrays.sort(a);
        int sz = 1;
        for (int i = 1; i < a.length; i++) {
            if (a[i] != a[sz - 1]) {
                a[sz++] = a[i];
            }
        }
        return Arrays.copyOf(a, sz);
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
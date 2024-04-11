import java.io.*;
import java.util.*;

public class C {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;

    class Number implements Comparable<Number> {
        int value, pos;

        public Number(int value, int pos) {
            this.value = value;
            this.pos = pos;
        }

        @Override
        public int compareTo(Number o) {
            if (value != o.value)
                return value < o.value ? -1 : 1;
            if (pos != o.pos)
                return pos < o.pos ? -1 : 1;
            return 0;
        }
    }

    class CoolHeap {
        private TreeSet<Number> least;
        private TreeSet<Number> rest;
        private int k; // maximal size of "least" set
        long sumLeast;
        long sumRest;

        public CoolHeap(int k) {
            this.k = k;
            least = new TreeSet<Number>();
            rest = new TreeSet<Number>();
        }

        void add(Number x) {
            if (k == 0) {
                sumRest += x.value;
                return;
            }
            if (least.size() < k) {
                sumLeast += x.value;
                least.add(x);
                return;
            }
            Number last = least.last();
            if (last.compareTo(x) > 0) {
                least.remove(last);
                sumLeast -= last.value;
                rest.add(last);
                sumRest += last.value;
                least.add(x);
                sumLeast += x.value;
                return;
            }
            rest.add(x);
            sumRest += x.value;
        }

        void remove(Number x) {
            if (k == 0) {
                sumRest -= x.value;
                return;
            }
            if (least.remove(x)) {
                sumLeast -= x.value;
                if (!rest.isEmpty()) {
                    Number add = rest.first();
                    rest.remove(add);
                    sumRest -= add.value;
                    least.add(add);
                    sumLeast += add.value;
                    if (least.size() != k)
                        throw new AssertionError();
                }
                return;
            }
            if (rest.remove(x)) {
                sumRest -= x.value;
                return;
            }
            throw new AssertionError();
        }
    }

    long go(int[] a, int len, int k) {
        long res = Long.MIN_VALUE;

        CoolHeap q = new CoolHeap(k);
        long sumPos = 0;
        for (int i = 0; i < len; i++) {
            if (a[i] > 0)
                sumPos += a[i];
            if (a[i] < 0)
                q.add(new Number(a[i], i));
        }
        res = Math.max(res, sumPos - q.sumLeast + q.sumRest);

        for (int i = len; i < a.length; i++) {
            if (a[i - len] > 0)
                sumPos -= a[i - len];
            if (a[i - len] < 0)
                q.remove(new Number(a[i - len], i - len));

            if (a[i] > 0)
                sumPos += a[i];
            if (a[i] < 0)
                q.add(new Number(a[i], i));

            res = Math.max(res, sumPos - q.sumLeast + q.sumRest);
        }
        return res;
    }

    void solve() throws IOException {
        int n = nextInt();
        int len = nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++)
            a[i] = nextInt();
        int k = nextInt();

        long ans = go(a, len, k);
        for (int i = 0; i < n; i++)
            a[i] = -a[i];
        ans = Math.max(ans, go(a, len, k));
        out.println(ans);
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
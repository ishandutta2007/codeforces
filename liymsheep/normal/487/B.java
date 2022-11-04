import java.io.InputStream;
import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.BufferedReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.util.Arrays;
import java.io.InputStreamReader;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskB {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int s = in.nextInt();
            int l = in.nextInt();

            int[] a = new int[n];
            for (int i = 0; i < n; ++i) {
                a[i] = in.nextInt();
            }

            int[] b = a.clone();
            for (int i = 0; i < n; ++i) {
                b[i] = -a[i];
            }

            RMQ rmq1 = new SparseTable(a);
            RMQ rmq2 = new SparseTable(b);

            IntervalTree tree = new IntervalTree(n + 1);

            int[] dp = new int[n + 1];
            dp[0] = 0;
            tree.insert(0, 0);
            for (int i = 1; i <= n; ++i) {
                int left = 0, right = i - l;
                while (left < right) {
                    int mid = (left + right) >> 1;
                    if (-rmq1.getMinValue(mid, i - 1) - rmq2.getMinValue(mid, i - 1) <= s) {
                        right = mid;
                    } else {
                        left = mid + 1;
                    }
                }
                if (right < 0 || -rmq1.getMinValue(left, i - 1) - rmq2.getMinValue(left, i - 1) > s) {
                    dp[i] = 0x3F3F3F3F;
                } else {
                    dp[i] = -tree.getMaxValue(left, i - l) + 1;
                }
                tree.insert(i, -dp[i]);
            }

            if (dp[n] >= 0x3F3F3F3F) {
                dp[n] = -1;
            }

            out.println(dp[n]);

        }

        interface RMQ {
            int getMinValue(int left, int right);

        }

        static class SparseTable implements RMQ {
            int[][] min;
            int[] orig;
            int[] log;
            int size;
            int maxPw;

            SparseTable(int[] seq) {
                this.orig = seq;
                this.size = seq.length;
                construct();
            }

            void construct() {
                int power = 1;
                while ((1 << power) < size) {
                    ++power;
                }
                maxPw = power + 1;
                min = new int[maxPw][size];
                log = new int[size + 1];
                log[0] = 0;
                for (int i = 1; i <= size; ++i) {
                    log[i] = 0;
                    while ((1 << (log[i] + 1)) < i) {
                        ++log[i];
                    }
                }

                for (int i = 0; i < size; ++i) {
                    min[0][i] = orig[i];
                }

                for (int i = 1; i < maxPw; ++i) {
                    for (int j = 0; j < size; ++j) {
                        min[i][j] = min[i - 1][j];
                        if (j + (1 << (i - 1)) < size) {
                            min[i][j] = Math.min(min[i][j], min[i - 1][j + (1 << (i - 1))]);
                        }
                    }
                }
            }


            public int getMinValue(int left, int right) {
                if (right < left) {
                    return Integer.MAX_VALUE;
                }
                int step = log[right - left + 1];
                return Math.min(min[step][left], min[step][right - (1 << step) + 1]);
            }

        }

        class IntervalTree {
            int size;
            int[] val;

            IntervalTree(int length) {
                this.size = length;
                val = new int[length * 4 + 100];
                Arrays.fill(val, -0x3F3F3F3F);
            }

            int getMaxValue(int left, int right, int l, int r, int x) {
                if (l <= left && r >= right) {
                    return val[x];
                }
                int mid = (left + right) >> 1;
                int ret = Integer.MIN_VALUE;
                if (l <= mid) ret = getMaxValue(left, mid, l, r, x * 2);
                if (r > mid) ret = Math.max(ret, getMaxValue(mid + 1, right, l, r, x * 2 + 1));
                return ret;
            }

            int getMaxValue(int left, int right) {
                return getMaxValue(0, size - 1, left, right, 1);
            }

            void insert(int left, int right, int pos, int x, int value) {
                if (left == right) {
                    val[x] = Math.max(val[x], value);
                    return;
                }

                int mid = (left + right) >> 1;
                if (pos <= mid) {
                    insert(left, mid, pos, x * 2, value);
                } else {
                    insert(mid + 1, right, pos, x * 2 + 1, value);
                }

                val[x] = Math.max(val[x * 2], val[x * 2 + 1]);
            }

            void insert(int pos, int value) {
                insert(0, size - 1, pos, 1, value);
            }

        }

    }

    static class InputReader {
        BufferedReader reader;
        StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream));
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (Exception e) {
                    throw new UnknownError();
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

    }
}
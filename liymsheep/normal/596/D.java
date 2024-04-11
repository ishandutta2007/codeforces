import java.io.InputStream;
import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.util.Arrays;

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
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        private int n;
        private int h;
        private int[] left;
        private int[] right;
        private double p;
        private int[] a;
        private double[] mem;

        private double dp(int l, int r, int state) {
            if (l > r) {
                return 0.0;
            }
            if (mem[l * n * 4 + r * 4 + state] > -0.5) {
                return mem[l * n * 4 + r * 4 + state];
            }
            double value = 0;
            boolean fallL = state % 2 == 1;
            boolean fallR = state / 2 == 1;


            double deltaL, deltaR;

            if (!fallL) {
                deltaL = Math.min(h, a[l] - a[l - 1]);
            } else {
                if (a[l] - a[l - 1] >= 2 * h) {
                    deltaL = h;
                } else {
                    deltaL = a[l] - a[l - 1] - h;
                }
            }

            if (!fallR) {
                deltaR = Math.min(h, a[r + 1] - a[r]);
            } else {
                if (a[r + 1] - a[r] >= 2 * h) {
                    deltaR = h;
                } else {
                    deltaR = a[r + 1] - a[r] - h;
                }
            }

            if (l == r) {
                value += p * deltaL;
                value += (1 - p) * deltaR;

                return mem[l * n * 4 + r * 4 + state] = value;
            }

            value += 0.5 * p * (deltaL + dp(l + 1, r, state & 2));
            value += 0.5 * (1 - p) * (deltaR + dp(l, r - 1, state & 1));

            int toL = Math.min(r, right[l]);
            if (toL < r) {
                value += 0.5 * (1 - p) * (a[toL] - a[l] + h + dp(toL + 1, r, state | 1));
            } else {
                value += 0.5 * (1 - p) * (a[r] - a[l] + deltaR);
            }

            int toR = Math.max(l, left[r]);
            if (toR > l) {
                value += 0.5 * p * (a[r] - a[toR] + h + dp(l, toR - 1, state | 2));
            } else {
                value += 0.5 * p * (a[r] - a[l] + deltaL);
            }

            return mem[l * n * 4 + r * 4 + state] = value;
        }

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            n = in.nextInt();
            h = in.nextInt();
            p = Double.parseDouble(in.next());
            a = new int[n + 2];
            a[n] = -1000000000;
            a[n + 1] = 1000000000;
            for (int i = 0; i < n; ++i) {
                a[i] = in.nextInt();
            }
            Arrays.sort(a);
            n += 2;

            left = new int[n];
            right = new int[n];

            for (int i = 0; i < n; ++i) {
                left[i] = i;
                if (i > 0 && a[i] - a[i - 1] < h) {
                    left[i] = left[i - 1];
                }
            }

            for (int i = n - 1; i >= 0; --i) {
                right[i] = i;
                if (i != n - 1 && a[i + 1] - a[i] < h) {
                    right[i] = right[i + 1];
                }
            }

            mem = new double[n * n * 4];
            Arrays.fill(mem, -1.0);

            out.printf("%.10f\n", dp(1, n - 2, 0));
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
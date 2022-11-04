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
        private int[][] multiply(int[][] a, int[][] b) {
            int n = a.length;
            int[][] result = new int[n][n];
            for (int[] i : result) {
                Arrays.fill(i, -1);
            }
            for (int i = 0; i < n; ++i) {
                result[i][i] = 0;
            }
            for (int k = 0; k < n; ++k) {
                for (int i = 0; i <= k; ++i) {
                    if (a[i][k] != -1) {
                        for (int j = k; j < n; ++j) {
                            if (b[k][j] != -1) {
                                result[i][j] = Math.max(result[i][j], a[i][k] + b[k][j]);
                            }
                        }
                    }
                }
            }
            return result;
        }

        private int[][] power(int[][] a, int p) {
            int n = a.length;
            int[][] result = new int[n][n];
            for (int[] i : result) {
                Arrays.fill(i, -1);
            }
            for (int i = 0; i < n; ++i) {
                result[i][i] = 0;
            }
            for (; p != 0; p >>= 1) {
                if (p % 2 == 1) result = multiply(result, a);
                a = multiply(a, a);
            }
            return result;
        }

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int t = in.nextInt();

            int[] arr = new int[n];
            for (int i = 0; i < n; ++i) {
                arr[i] = in.nextInt();
            }

            Order order = new Order(arr);
            for (int i = 0; i < n; ++i) {
                arr[i] = order.get(arr[i]);
            }

            int[][] period = new int[order.size()][order.size()];
            for (int[] a : period) {
                Arrays.fill(a, -1);
            }
            for (int begin = 0; begin < order.size(); ++begin) {
                int[] dp = new int[n + 1];
                int[] val = new int[n + 1];
                val[0] = begin;
                for (int i = 1; i <= n; ++i) {
                    val[i] = arr[i - 1];
                }
                Arrays.fill(dp, -1);
                dp[0] = 0;
                for (int i = 1; i <= n; ++i) {
                    for (int j = 0; j < i; ++j) {
                        if (dp[j] != -1 && val[i] >= val[j]) {
                            dp[i] = Math.max(dp[i], dp[j] + 1);
                        }
                    }
                }

                for (int i = 0; i <= n; ++i) {
                    period[begin][val[i]] = Math.max(period[begin][val[i]], dp[i]);
                }
                for (int i = 0; i < period.length; ++i) {
                    if (i > 0 && period[begin][i - 1] > period[begin][i]) {
                        period[begin][i] = period[begin][i - 1];
                    }
                }
            }

            int[][] result = power(period, t);
            int answer = 0;
            for (int i = 0; i < period.length; ++i) {
                answer = Math.max(answer, result[0][i]);
            }

            out.println(answer);
        }

        static class Order {
            private int[] arr;

            Order(int orig[]) {
                int[] temp = orig.clone();
                Arrays.sort(temp);

                int total = 1;
                for (int i = 1; i < temp.length; ++i)
                    if (temp[i] != temp[i - 1])
                        ++total;

                arr = new int[total];
                arr[0] = temp[0];
                total = 1;
                for (int i = 1; i < temp.length; ++i)
                    if (temp[i] != temp[i - 1])
                        arr[total++] = temp[i];
            }

            public int size() {
                return arr.length;
            }

            public int get(int x) {
                return Arrays.binarySearch(arr, x);
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
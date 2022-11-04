import java.io.InputStream;
import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.BufferedReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;
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
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        private int gcd(int a, int b) {
            if (b == 0) {
                return a;
            }
            return gcd(b, a % b);
        }

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int[] a = new int[n];
            for (int i = 0; i < n; ++i) {
                a[i] = in.nextInt();
            }

            int[] aCopy = new int[a.length * 2];
            for (int i = 0; i < 2 * n; ++i) {
                aCopy[i] = a[i % n];
            }
            a = aCopy;

            int cont = 0;
            for (int i = 1; i < n; ++i) {
                if (n % i == 0) {
                    ++cont;
                }
            }

            int[] numbers = new int[cont];
            cont = 0;
            for (int i = 1; i < n; ++i) {
                if (n % i == 0) {
                    numbers[cont++] = i;
                }
            }

            int[] g = new int[n + 1];
            for (int i = 1; i <= n; ++i) {
                g[i] = gcd(n, i);
            }

            long answer = 0;
            int[] gcdCount = new int[n + 1];
            int[] maxValue = new int[n];
            for (int j = 0; j < cont; ++j) {
                for (int i = 0; i < numbers[j]; ++i) {
                    maxValue[i] = 0;
                }

                gcdCount[0] = 0;
                for (int i = 1; i <= n; ++i) {
                    gcdCount[i] = gcdCount[i - 1];
                    if (g[i] == numbers[j]) {
                        ++gcdCount[i];
                    }
                }

                for (int i = 0; i < n; ++i) {
                    maxValue[i % numbers[j]] = Math.max(maxValue[i % numbers[j]], a[i]);
                }

                int nextBlock = n;
                while (nextBlock < 2 * n && maxValue[nextBlock % numbers[j]] <= a[nextBlock]) {
                    ++nextBlock;
                }

                for (int i = n - 1; i >= 0; --i) {
                    if (maxValue[i % numbers[j]] > a[i]) {
                        nextBlock = i;
                    }

                    answer += gcdCount[Math.min(nextBlock - i, n)];
                }

//            System.err.println("num = " + numbers[j] + ", answer = " + answer);
            }

            out.println(answer);
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
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
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int[] a = new int[n];
            int[] count = new int[n];
            for (int i = 0; i < n; ++i) {
                a[i] = in.nextInt() - 1;
                ++count[a[i]];
            }

            int[] parity = new int[2];
            for (int i : count) {
                ++parity[i % 2];
            }

            if (n % 2 == 0 && parity[1] > 0
                    || n % 2 == 1 && parity[1] != 1) {
                out.println(0);
                return;
            }

            int[] countL = new int[n];
            int[] countR = new int[n];

            for (int i = 0; i < (n + 1) / 2; ++i) {
                ++countL[a[i]];
                ++countR[a[n - 1 - i]];
            }

            boolean badHalf = false;
            for (int i = 0; i < n; ++i) {
                if (countL[i] != countR[i]) {
                    badHalf = true;
                    break;
                }
            }

            int prefixLength = 0;
            int suffixLength = 0;
            for (int i = 0; i < (n + 1) / 2; ++i) {
                if (a[i] == a[n - 1 - i]) {
                    ++prefixLength;
                } else {
                    break;
                }
            }

            {
                int l = (n + 1) / 2 - 1, r = n / 2;
                for (int i = 0; i < (n + 1) / 2; ++i) {
                    if (a[l - i] == a[r + i]) {
                        ++suffixLength;
                    } else {
                        break;
                    }
                }
            }

            long answer = 0L;
            if (prefixLength + suffixLength >= (n + 1) / 2) {
                answer = (n + 1L) * n / 2;
                out.println(answer);
                return;
            }

            System.err.println("pre = " + prefixLength + " suf = " + suffixLength);

            if (!badHalf) {
                if (n % 2 == 1) {
                    answer = suffixLength * 2L * (prefixLength + 1);
                } else {
                    answer = (suffixLength + 1) * 2L * (prefixLength + 1);
                }
            }

            answer += prefixLength * 1L * prefixLength;

            Arrays.fill(count, 0);
            Arrays.fill(countL, 0);
            Arrays.fill(countR, 0);

            int[] b = new int[n - 2 * prefixLength];
            for (int i = prefixLength; i < n - prefixLength; ++i) {
                b[i - prefixLength] = a[i];
            }

            int m = b.length;
            for (int i = 0; i < m; ++i) {
                ++count[b[i]];
            }

            for (int i = 0; i < (m + 1) / 2; ++i) {
                answer += prefixLength + 1;
                ++countL[b[i]];
                if (countL[b[i]] * 2 > count[b[i]]) {
                    break;
                }
            }

            for (int i = 0; i < (m + 1) / 2; ++i) {
                if (i == 0) {
                    answer += prefixLength;
                } else {
                    answer += prefixLength + 1;
                }

                ++countR[b[m - 1 - i]];
                if (countR[b[m - 1 - i]] * 2 > count[b[m - 1 - i]]) {
                    break;
                }
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
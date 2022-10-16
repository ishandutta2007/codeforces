import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskB {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            char[] s = in.next().toCharArray();
            int n = s.length;

            double[] seen = new double[26];
            Arrays.fill(seen, -1);
            double ans = 0;
            for (int open = 0; open < n; open++) {
                int c = s[open] - 'a';
                if (seen[c] != -1) {
                    ans += seen[c];
                    continue;
                }

                int[][] freq = new int[n][26];
                int tot = 0;
                for (int i = 0; i < n; i++) {
                    if (s[i] == s[open]) {
                        tot++;
                        for (int j = 0; j < n; j++) {
                            int q = s[(i + j) % n] - 'a';
                            freq[j][q]++;
                        }
                    }
                }

                double best = 0;
                for (int guess = 1; guess < n; guess++) {
                    double cur = 0;
                    for (int r = 0; r < 26; r++) {
                        if (freq[guess][r] > 0) {
                            double see = freq[guess][r] / (double) tot;
                            double right = freq[guess][r] == 1 ? 1 : 0;
                            cur += see * right;
                        }
                    }
                    if (cur > best) best = cur;
                }
                ans += seen[c] = best;
            }
            out.printf("%.10f\n", ans / n);
        }

    }

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1 << 16];
        private int curChar;
        private int numChars;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public int read() {
            if (this.numChars == -1) {
                throw new InputMismatchException();
            } else {
                if (this.curChar >= this.numChars) {
                    this.curChar = 0;

                    try {
                        this.numChars = this.stream.read(this.buf);
                    } catch (IOException var2) {
                        throw new InputMismatchException();
                    }

                    if (this.numChars <= 0) {
                        return -1;
                    }
                }

                return this.buf[this.curChar++];
            }
        }

        public String next() {
            int c;
            while (isSpaceChar(c = this.read())) {
                ;
            }

            StringBuilder result = new StringBuilder();
            result.appendCodePoint(c);

            while (!isSpaceChar(c = this.read())) {
                result.appendCodePoint(c);
            }

            return result.toString();
        }

        public static boolean isSpaceChar(int c) {
            return c == 32 || c == 10 || c == 13 || c == 9 || c == -1;
        }

    }

    static class OutputWriter {
        private final PrintWriter writer;

        public OutputWriter(OutputStream outputStream) {
            writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
        }

        public OutputWriter(Writer writer) {
            this.writer = new PrintWriter(writer);
        }

        public void printf(String format, Object... objects) {
            writer.printf(format, objects);
        }

        public void close() {
            writer.close();
        }

    }
}
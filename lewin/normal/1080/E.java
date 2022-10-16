import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.ArrayList;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author lewin
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        ESonyaAndMatrixBeauty solver = new ESonyaAndMatrixBeauty();
        solver.solve(1, in, out);
        out.close();
    }

    static class ESonyaAndMatrixBeauty {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt(), m = in.nextInt();
            char[][] grid = new char[n][m];
            for (int i = 0; i < n; i++) {
                grid[i] = in.next().toCharArray();
            }

            int[][] rnd = new int[26][m + 1];
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < rnd[i].length; j++) {
                    rnd[i][j] = (int) (Math.random() * Integer.MAX_VALUE);
                }
            }

            long res = 0;
            for (int i = 0; i < m; i++) {
                int[] bmasks = new int[n];
                int[][] count = new int[n][26];
                int[] hash = new int[n];
                for (int j = i; j < m; j++) {
                    int par = (j - i) % 2;
                    ArrayList<Integer> rr = new ArrayList<>();
                    for (int k = 0; k < n; k++) {
                        int id = grid[k][j] - 'a';
                        bmasks[k] ^= 1 << id;
                        hash[k] ^= rnd[id][++count[k][id]];
                        if (Integer.bitCount(bmasks[k]) <= 1 - par) {
                            rr.add(hash[k]);
                        } else {
                            res += countPalindromes(rr);
                            rr = new ArrayList<>();
                        }
                    }
                    res += countPalindromes(rr);
                }
            }
            out.println(res);
        }

        int countPalindromes(ArrayList<Integer> s) {
            int[] t = new int[s.size() * 2 + 3];
            t[0] = -2;
            t[s.size() * 2 + 2] = -1;
            for (int i = 0; i < s.size(); i++) {
                t[2 * i + 1] = -3;
                t[2 * i + 2] = s.get(i);
            }
            t[s.size() * 2 + 1] = -3;
            int ret = 0;
            int[] p = new int[t.length];
            int center = 0, right = 0;
            for (int i = 1; i < t.length - 1; i++) {
                int mirror = 2 * center - i;

                if (right > i)
                    p[i] = Math.min(right - i, p[mirror]);

                while (t[i + (1 + p[i])] == t[i - (1 + p[i])])
                    p[i]++;

                if (i + p[i] > right) {
                    center = i;
                    right = i + p[i];
                }
                if (i % 2 == 0) ret += (p[i] + 1) / 2;
                else ret += p[i] / 2;
            }
            return ret;
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

        public int nextInt() {
            int c;
            for (c = this.read(); isSpaceChar(c); c = this.read()) {
                ;
            }

            byte sgn = 1;
            if (c == 45) {
                sgn = -1;
                c = this.read();
            }

            int res = 0;

            while (c >= 48 && c <= 57) {
                res *= 10;
                res += c - 48;
                c = this.read();
                if (isSpaceChar(c)) {
                    return res * sgn;
                }
            }

            throw new InputMismatchException();
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

        public void close() {
            writer.close();
        }

        public void println(long i) {
            writer.println(i);
        }

    }
}
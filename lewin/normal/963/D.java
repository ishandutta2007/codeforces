import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.IOException;
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
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        public static final int K = 26;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            String s = in.next() + "$";
            int n = s.length();

            int[] sa = SuffixArray3.buildSuffixArray(s.toCharArray());
            int[][] occ = new int[n + 1][K];
            int[] count = new int[K + 1];
            for (int i = 0; i < n; i++) {
                int t = s.charAt(sa[i] == 0 ? n - 1 : sa[i] - 1) - 'a';
                if (t >= 0) {
                    occ[i][t]++;
                    count[t + 1]++;
                }
                System.arraycopy(occ[i], 0, occ[i + 1], 0, K);
            }
            for (int i = 1; i < count.length; i++) {
                count[i] += count[i - 1];
            }

            int[] t = new int[n + 1];
            int q = in.nextInt();
            while (q-- > 0) {
                int k = in.nextInt();
                char[] tt = in.next().toCharArray();
                int begin = 0, end = n - 1;
                for (int j = tt.length - 1; end - begin + 1 >= k && j >= 0; j--) {
                    int let = tt[j] - 'a';
                    int nbegin = count[let] + (begin == 0 ? 0 : occ[begin - 1][let]) + 1;
                    int nend = count[let] + occ[end][let];
                    begin = nbegin;
                    end = nend;
                }
                if (end - begin + 1 < k) {
                    out.println(-1);
                    continue;
                }
                int idx = 0;
                for (int j = begin; j <= end; j++) t[idx++] = sa[j];
                Arrays.sort(t, 0, idx);
                int ww = Integer.MAX_VALUE;
                for (int j = 0; j + k - 1 < idx; j++) {
                    ww = Math.min(ww, t[j + k - 1] - t[j]);
                }
                out.println(ww + tt.length);
            }

        }

    }

    static class SuffixArray3 {
        public static int[] buildSuffixArray(char[] _s) {
            int[] s = compress(_s);
            int n = s.length;
            int[] am = new int[n];
            for (int x : s) {
                ++am[x];
            }
            int[] start = new int[n];
            int numCols = 0;
            int total = 0;
            for (int i = 0; i < n; i++) {
                if (am[i] > 0) {
                    start[numCols] = total;
                    total += am[i];
                    ++numCols;
                }
            }
            int[] sa = new int[n];
            int[] tmp = start.clone();
            int[] col = new int[n];
            for (int i = 0; i < n; i++) {
                col[i] = s[i];
                sa[tmp[col[i]]++] = i;
            }
            int len = 1;
            while (len < n) {
                int[] ncol = new int[n];
                int[] nsa = new int[n];
                for (int i = 0; i < n; i++) {
                    int j = sa[i] - len;
                    if (j < 0) {
                        j += n;
                    }
                    nsa[start[col[j]]++] = j;
                }
                numCols = 1;
                start[0] = 0;
                for (int i = 0; i < n; i++) {
                    if (i > 0) {
                        int u = nsa[i];
                        int v = nsa[i - 1];
                        if (col[u] != col[v] || col[(u + len) % n] != col[(v + len) % n]) {
                            start[numCols] = i;
                            ++numCols;
                        }
                    }
                    ncol[nsa[i]] = numCols - 1;
                }
                col = ncol;
                sa = nsa;
                len *= 2;
            }
            return sa;
        }

        private static int[] compress(char[] s) {
            char[] sorted = s.clone();
            Arrays.sort(sorted);
            int k = 0;
            for (int i = 0; i < sorted.length; i++) {
                if (i == 0 || sorted[i] != sorted[i - 1]) {
                    sorted[k++] = sorted[i];
                }
            }
            int[] res = new int[s.length];
            for (int i = 0; i < s.length; i++) {
                res[i] = Arrays.binarySearch(sorted, 0, k, s[i]);
            }
            return res;
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

        public void println(int i) {
            writer.println(i);
        }

    }
}
import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.HashSet;
import java.util.AbstractCollection;
import java.io.Writer;
import java.io.OutputStreamWriter;
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
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        public int MAXK = 50;
        public int MAXN = 200;
        public HashSet<String>[][] mp;
        public String[] prefix;
        public String[] suffix;
        public long INF = 1L << 60;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt();
            prefix = new String[MAXN + 1];
            suffix = new String[MAXN + 1];
            long[] len = new long[MAXN + 1];
            mp = new HashSet[MAXN + 1][MAXK + 1];

            for (int i = 0; i <= MAXN; i++) for (int j = 0; j <= MAXK; j++) mp[i][j] = new HashSet<>();
            for (int i = 0; i < n; i++) {
                prefix[i] = suffix[i] = in.next();
                len[i] = prefix[i].length();
            }

            int q = in.nextInt();
            while (q-- > 0) {
                int a = in.nextInt() - 1, b = in.nextInt() - 1;
                len[n] = Math.min(INF, len[a] + len[b]);
                if (len[a] <= MAXK && len[b] <= MAXK) {
                    String s = prefix[a] + prefix[b];
                    prefix[n] = s.substring(0, Math.min(MAXK, s.length()));
                    suffix[n] = s.substring(Math.max(0, s.length() - MAXK));
                } else if (len[a] <= MAXK) {
                    prefix[n] = (prefix[a] + prefix[b]).substring(0, MAXK);
                    suffix[n] = suffix[b];
                } else if (len[b] <= MAXK) {
                    prefix[n] = prefix[a];
                    suffix[n] = (suffix[a] + suffix[b]).substring(suffix[a].length() + suffix[b].length() - MAXK);
                } else {
                    prefix[n] = prefix[a];
                    suffix[n] = suffix[b];
                }
                for (int k = 0; k <= MAXK; k++) {
                    mp[n][k].addAll(mp[a][k]);
                    mp[n][k].addAll(mp[b][k]);
                }
                String mid = suffix[a] + prefix[b];
                for (int r = 1; r <= MAXK; r++) {
                    for (int j = 0; j < mid.length() - r + 1; j++) {
                        mp[n][r].add(mid.substring(j, j + r));
                    }
                }

                int ans = 0;
                while (mp[n][ans + 1].size() == 1L << (ans + 1)) ans++;
                out.println(ans);
                n++;
            }
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

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
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
}
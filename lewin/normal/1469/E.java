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
        EABitSimilar solver = new EABitSimilar();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class EABitSimilar {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt(), k = in.nextInt();
            char[] s = in.next().toCharArray();
            for (int i = 0; i < n; i++) {
                if (s[i] == '0') s[i] = 1;
                else s[i] = 0;
            }
            var sa = buildSuffixAutomaton(new String(s));
            int m = sa.length;
            int[] indeg = new int[m];
            for (int i = 0; i < sa.length; i++) {
                if (sa[i].next[0] != -1) indeg[sa[i].next[0]]++;
                if (sa[i].next[1] != -1) indeg[sa[i].next[1]]++;
            }
            int[] order = new int[m];
            int front = 0, back = 0;
            for (int i = 0; i < m; i++) {
                if (indeg[i] == 0) {
                    order[back++] = i;
                }
            }
            while (front < back) {
                int cur = order[front++];
                if (sa[cur].next[0] != -1 && --indeg[sa[cur].next[0]] == 0) order[back++] = sa[cur].next[0];
                if (sa[cur].next[1] != -1 && --indeg[sa[cur].next[1]] == 0) order[back++] = sa[cur].next[1];
            }

            int[] full = new int[m];
            for (int i = m - 1; i >= 0; i--) {
                int cur = order[i];
                int a = sa[cur].next[0], b = sa[cur].next[1];
                if (a == -1 || b == -1) continue;
                full[cur] = Math.min(full[a], full[b]) + 1;
            }
            if (full[0] >= k) {
                out.println("NO");
                return;
            }
            int cstate = 0;
            char[] res = new char[k];
            for (int i = 0; i < k; i++) {
                if (cstate == -1 || sa[cstate].next[0] == -1 || full[sa[cstate].next[0]] < (k - i - 1)) {
                    res[i] = '0';
                } else {
                    res[i] = '1';
                }
                if (cstate != -1) cstate = sa[cstate].next[res[i] - '0'];

            }
            out.println("YES");
            out.println(new String(res));
        }

        public static EABitSimilar.State[] buildSuffixAutomaton(CharSequence s) {
            int n = s.length();
            EABitSimilar.State[] st = new EABitSimilar.State[Math.max(2, 2 * n - 1)];
            st[0] = new EABitSimilar.State();
            st[0].suffLink = -1;
            int last = 0;
            int size = 1;
            for (int i = 0; i < s.length(); i++) {
                char c = s.charAt(i);
                int cur = size++;
                st[cur] = new EABitSimilar.State();
                st[cur].length = i + 1;
                st[cur].firstPos = i;
                int p = last;
                for (; p != -1 && st[p].next[c] == -1; p = st[p].suffLink) {
                    st[p].next[c] = cur;
                }
                if (p == -1) {
                    st[cur].suffLink = 0;
                } else {
                    int q = st[p].next[c];
                    if (st[p].length + 1 == st[q].length) {
                        st[cur].suffLink = q;
                    } else {
                        int clone = size++;
                        st[clone] = new EABitSimilar.State();
                        st[clone].length = st[p].length + 1;
                        System.arraycopy(st[q].next, 0, st[clone].next, 0, st[q].next.length);
                        st[clone].suffLink = st[q].suffLink;
                        for (; p != -1 && st[p].next[c] == q; p = st[p].suffLink) {
                            st[p].next[c] = clone;
                        }
                        st[q].suffLink = clone;
                        st[cur].suffLink = clone;
                    }
                }
                last = cur;
            }
            return Arrays.copyOf(st, size);
        }

        public static class State {
            public int length;
            public int suffLink;
            public int firstPos = -1;
            public int[] next = new int[2];

            {
                Arrays.fill(next, -1);
            }
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
                throw new UnknownError();
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

        public void print(Object... objects) {
            for (int i = 0; i < objects.length; i++) {
                if (i != 0) {
                    writer.print(' ');
                }
                writer.print(objects[i]);
            }
        }

        public void println(Object... objects) {
            print(objects);
            writer.println();
        }

        public void close() {
            writer.close();
        }

    }
}
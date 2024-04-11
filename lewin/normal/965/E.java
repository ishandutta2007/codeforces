import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.Comparator;
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
        TaskE solver = new TaskE();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskE {
        boolean[] leaf;
        int[][] child;
        int q;
        int MAXN = 200010;

        TaskE.Set solve(int node) {
            int big = -1;
            TaskE.Set[] sets = new TaskE.Set[26];
            for (int i = 0; i < 26; i++) {
                if (child[node][i] != -1) {
                    sets[i] = solve(child[node][i]);
                    if (big == -1 || sets[i].pq.size() > sets[big].pq.size()) {
                        big = i;
                    }
                    sets[i].offset++;
                }
            }
            if (big == -1) {
                PriorityQueue<Integer> r = new PriorityQueue<>(Comparator.reverseOrder());
                r.add(0);
                return new TaskE.Set(r, 0);
            }

            TaskE.Set ret = sets[big];
            for (int i = 0; i < 26; i++) {
                if (sets[i] != null && i != big) {
                    while (sets[i].pq.size() > 0) {
                        int t = sets[i].pq.poll() + sets[i].offset - ret.offset;
                        ret.pq.add(t);
                    }
                }
            }
            if (leaf[node]) {
                ret.pq.add(-ret.offset);
            } else if (node != 0) {
                ret.pq.poll();
                ret.pq.add(-ret.offset);
            }
            return ret;
        }

        void insert(int node, char[] s, int idx) {
            if (idx == s.length) {
                leaf[node] = true;
                return;
            }
            int t = child[node][s[idx] - 'a'];
            if (t == -1) {
                child[node][s[idx] - 'a'] = q++;
            }
            insert(child[node][s[idx] - 'a'], s, idx + 1);
        }

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt();
            child = new int[MAXN][26];
            leaf = new boolean[MAXN];
            AUtils.deepFill(child, -1);
            q = 1;
            for (int i = 0; i < n; i++) {
                insert(0, in.next().toCharArray(), 0);
            }

            TaskE.Set x = solve(0);
            int ret = 0;
            while (x.pq.size() > 0) {
                ret += x.pq.poll() + x.offset;
            }
            out.println(ret);
        }

        static class Set {
            public PriorityQueue<Integer> pq;
            public int offset;

            public Set(PriorityQueue<Integer> pq, int offset) {
                this.pq = pq;
                this.offset = offset;
            }


            public String toString() {
                return "Set{" +
                        "pq=" + pq +
                        ", offset=" + offset +
                        '}';
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

    static class AUtils {
        public static void deepFill(int[][] x, int val) {
            for (int[] y : x) deepFill(y, val);
        }

        public static void deepFill(int[] x, int val) {
            Arrays.fill(x, val);
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
import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.HashMap;
import java.util.InputMismatchException;
import java.io.IOException;
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
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        public int n;
        public TaskC.SegmentTree root;
        public int[] pc;
        public int[] lastcount;
        public static int[] seq;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            n = in.nextInt();
            int[] arr = in.readIntArray(n);
            HashMap<Integer, Integer> mp = new HashMap<>();
            seq = new int[n + 1];
            for (int i = 0; i < n; i++) {
                seq[i] = mp.getOrDefault(arr[i], -1);
                mp.put(arr[i], i);
            }
            seq[n] = n;
            root = new TaskC.SegmentTree(0, n);
            pc = new int[n];
            lastcount = new int[n];
            StringBuilder b = new StringBuilder();
            for (int i = 0; i < n; i++) {
                pc[i] = i;
                lastcount[i] = 0;
            }
            int p = n;
            for (int i = 1; i <= n; i++) {
                if (p == 1) {
                    if (i != 1) b.append(" ");
                    b.append(1);
                    continue;
                }
                int count = 0;
                int cur = 0;
                while (cur < n) {
                    cur = findnext(cur, i);
                    count++;
                }
                if (i != 1) b.append(" ");
                b.append(count);
                p = count;
            }
            out.println(b.toString());
        }

        public int findnext(int pos, int need) {
            int www = need - lastcount[pos] + 1;
            int ret = root.getNext(pc[pos], pos, www);
            pc[pos] = ret;
            lastcount[pos] = need;
            return ret;
        }

        static class SegmentTree {
            public int[] arr;
            public int start;
            public int end;
            public TaskC.SegmentTree lchild;
            public TaskC.SegmentTree rchild;

            public SegmentTree(int start, int end) {
                this.start = start;
                this.end = end;
                arr = new int[end - start + 2];
                arr[0] = -1;
                if (start == end) {
                    arr[1] = seq[start];
                } else {
                    int mid = (start + end) >> 1;
                    lchild = new TaskC.SegmentTree(start, mid);
                    rchild = new TaskC.SegmentTree(mid + 1, end);
                    int lidx = 1, ridx = 1;

                    int idx = 1;
                    int[] larr = lchild.arr, rarr = rchild.arr;
                    while (lidx < larr.length && ridx < rarr.length) {
                        if (larr[lidx] < rarr[ridx]) {
                            arr[idx++] = larr[lidx++];
                        } else {
                            arr[idx++] = rarr[ridx++];
                        }
                    }
                    while (lidx < larr.length) {
                        arr[idx++] = larr[lidx++];
                    }
                    while (ridx < rarr.length) {
                        arr[idx++] = rarr[ridx++];
                    }
                }
            }

            public int query(int s, int e, int k) {
                if (start == s && end == e) {
                    int d = Arrays.binarySearch(arr, k);
                    if (d < 0) d = -(d + 1);
                    return d - 1;
                }
                int mid = (start + end) >> 1;
                if (mid >= e) return lchild.query(s, e, k);
                else if (mid < s) return rchild.query(s, e, k);
                else {
                    int x = lchild.query(s, mid, k);
                    x += rchild.query(mid + 1, e, k);
                    return x;
                }
            }

            public int getNext(int s, int k, int xxx) {
                if (start == end) {
                    return start;
                }
                int mid = (start + end) >> 1;
                if (s > mid) return rchild.getNext(s, k, xxx);
                int x = lchild.query(s, mid, k);
                if (xxx <= x)
                    return lchild.getNext(s, k, xxx);
                else
                    return rchild.getNext(mid + 1, k, xxx - x);
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

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public int[] readIntArray(int tokens) {
            int[] ret = new int[tokens];
            for (int i = 0; i < tokens; i++) {
                ret[i] = nextInt();
            }
            return ret;
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

        public static boolean isSpaceChar(int c) {
            return c == 32 || c == 10 || c == 13 || c == 9 || c == -1;
        }

    }
}
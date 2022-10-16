import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.InputMismatchException;
import java.io.IOException;
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
        DRestorePermutation solver = new DRestorePermutation();
        solver.solve(1, in, out);
        out.close();
    }

    static class DRestorePermutation {
        static long[] arr;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt();
            arr = in.readLongArray(n);
            DRestorePermutation.SegmentTree rt = new DRestorePermutation.SegmentTree(0, n - 1);
            int[] ret = new int[n];
            for (int i = 1; i <= n; i++) {
                int idx = rt.getZero();
                ret[idx] = i;
                rt.update(idx, n - 1, i);
            }
            out.println(ret);
        }

        static class SegmentTree {
            public long min;
            public long sub;
            public boolean haszero;
            public DRestorePermutation.SegmentTree left;
            public DRestorePermutation.SegmentTree right;
            public int start;
            public int end;

            public SegmentTree(int start, int end) {
                this.start = start;
                this.end = end;
                if (start != end) {
                    int mid = (start + end) / 2;
                    left = new DRestorePermutation.SegmentTree(start, mid);
                    right = new DRestorePermutation.SegmentTree(mid + 1, end);
                    this.min = Math.min(left.min, right.min);
                    this.sub = 0;
                    this.haszero = left.haszero || right.haszero;
                } else {
                    this.min = arr[start];
                    this.sub = 0;
                    this.haszero = this.min == 0;
                }
            }

            public void upd(long csub) {
                sub += csub;
                min -= csub;
                haszero = min == 0;
            }

            public void push() {
                if (left != null) {
                    left.upd(this.sub);
                    right.upd(this.sub);
                    this.sub = 0;
                }
            }

            public void join() {
                if (left != null) {
                    this.min = Math.min(left.min, right.min);
                    this.haszero = left.haszero || right.haszero;
                }
            }

            public void update(int s, int e, long csub) {
                if (this.start == s && this.end == e) {
                    upd(csub);
                    return;
                }
                push();
                int mid = (start + end) / 2;
                if (e <= mid) left.update(s, e, csub);
                else if (mid < s) right.update(s, e, csub);
                else {
                    left.update(s, mid, csub);
                    right.update(mid + 1, e, csub);
                }
                this.join();
            }

            public int getZero() {
                if (start == end) {
                    this.min = 1L << 60;
                    this.haszero = false;
                    return start;
                }
                push();
                int ans;
                if (right.haszero) ans = right.getZero();
                else ans = left.getZero();
                join();
                return ans;
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

        public long[] readLongArray(int tokens) {
            long[] ret = new long[tokens];
            for (int i = 0; i < tokens; i++) {
                ret[i] = nextLong();
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

        public long nextLong() {
            int c;
            for (c = this.read(); isSpaceChar(c); c = this.read()) {
                ;
            }

            byte sgn = 1;
            if (c == 45) {
                sgn = -1;
                c = this.read();
            }

            long res = 0L;

            while (c >= 48 && c <= 57) {
                res *= 10L;
                res += (long) (c - 48);
                c = this.read();
                if (isSpaceChar(c)) {
                    return res * (long) sgn;
                }
            }

            throw new InputMismatchException();
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

        public void print(int[] array) {
            for (int i = 0; i < array.length; i++) {
                if (i != 0) {
                    writer.print(' ');
                }
                writer.print(array[i]);
            }
        }

        public void println(int[] array) {
            print(array);
            writer.println();
        }

        public void close() {
            writer.close();
        }

    }
}
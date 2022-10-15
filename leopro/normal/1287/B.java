import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.function.IntConsumer;
import java.util.InputMismatchException;
import java.io.IOException;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        FastScanner in = new FastScanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskB solver = new TaskB(in, out);
        try {
            solver.solve();
        } catch (ExitException ignored) {
        }
        out.close();
    }

    static class TaskB {
        FastScanner sc;
        PrintWriter out;

        public TaskB(FastScanner sc, PrintWriter out) {
            this.sc = sc;
            this.out = out;
        }

        public void solve() {
            times(1, this::solve);
        }

        public void solve(int time) {
            int n = sc.nextInt();
            int k = sc.nextInt();
            LongArray set = new LongArray(n);
            for (int i = 0; i < n; i++) {
                long val = 0;
                for (char chr : sc.nextLine().toCharArray()) {
                    if (chr == 'S') {
                        val = (val << 2) + 0;
                    } else if (chr == 'E') {
                        val = (val << 2) + 1;
                    } else {
                        val = (val << 2) + 2;
                    }
                }
                set.add(val);
            }
            set.sort();

            int ans = 0;
            long[] array = set.array;
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    long shift = 0;
                    long m3 = 0;
                    long m1 = array[i];
                    long m2 = array[j];
                    for (int m = 0; m < k; m++) {
                        long v1 = m1 & 3;
                        long v2 = m2 & 3;
                        if (v1 == v2) {
                            m3 += v1 << shift;
                        } else {
                            m3 += (3 - v1 - v2) << shift;
                        }
                        shift += 2;
                        m1 >>= 2;
                        m2 >>= 2;
                    }

                    if (set.contains(m3, j)) ans++;
                }
            }
            answer(ans);

        }

        private void answer(Object ans) {
            out.println(ans);
            throw new ExitException();
        }

        private void times(int n, IntConsumer consumer) {
            for (int i = 0; i < n; i++) {
                try {
                    consumer.accept(i);
                } catch (ExitException ignored) {
                }
            }
        }

    }

    static class ExitException extends RuntimeException {
    }

    static class FastScanner {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;

        public FastScanner(InputStream stream) {
            this.stream = stream;
        }

        int read() {
            if (numChars == -1)
                throw new InputMismatchException();
            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (numChars <= 0) return -1;
            }
            return buf[curChar++];
        }

        boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        boolean isEndline(int c) {
            return c == '\n' || c == '\r' || c == -1;
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public String next() {
            int c = read();
            while (isSpaceChar(c)) c = read();
            StringBuilder res = new StringBuilder();
            do {
                res.appendCodePoint(c);
                c = read();
            } while (!isSpaceChar(c));
            return res.toString();
        }

        public String nextLine() {
            int c = read();
            while (isEndline(c))
                c = read();
            StringBuilder res = new StringBuilder();
            do {
                res.appendCodePoint(c);
                c = read();
            } while (!isEndline(c));
            return res.toString();
        }

    }

    static class LongArray {
        public long[] array;
        public int size;

        public LongArray() {
            this(20);
        }

        public LongArray(int capacity) {
            this.array = new long[capacity];
        }

        public void add(long n) {
            ensureCapacity(size + 1);
            array[size++] = n;
        }

        public void sort() {
            shuffle();
            Arrays.sort(array, 0, size);
        }

        void shuffle() {
            for (int i = 0; i < size; i++) {
                int r = i + (int) (Math.random() * (size - i));
                {
                    long tmp = array[i];
                    array[i] = array[r];
                    array[r] = tmp;
                }
            }
        }

        public boolean contains(long n, int from) {
            return contains(n, from, size);
        }

        boolean contains(long n, int from, int till) {
            int lo = from;
            int hi = till;
            while (hi - lo > 1) {
                int med = (hi + lo) >> 1;
                long mValue = array[med];
                if (mValue == n) return true;
                else if (mValue < n) lo = med;
                else hi = med;
            }
            return false;
        }

        private void ensureCapacity(int cap) {
            if (cap > array.length) grow();
        }

        private void grow() {
            int oldCapacity = array.length;
            int newCapacity = oldCapacity + (oldCapacity >> 1);
            array = Arrays.copyOf(array, newCapacity);
        }

    }
}
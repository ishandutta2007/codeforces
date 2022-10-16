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
import java.util.Random;
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
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt();
            TreapBST.Treap root = null;
            for (int i = 0; i < n; i++) {
                int l = in.nextInt(), r = in.nextInt();
                TreapBST.TreapPair x = TreapBST.split(root, r);
                if (TreapBST.getSize(x.right) > 0) {
                    x.right = TreapBST.removeMin(x.right);
                }
                TreapBST.TreapPair y = TreapBST.split(x.left, l);
                if (y.right != null) {
                    y.right.lazy += 1;
                    y.right.key += 1;
                }
                y.right = TreapBST.insert(y.right, l);

                root = TreapBST.merge(TreapBST.merge(y.left, y.right), x.right);
//            System.out.println(i);
//            TreapBST.print(root);
//            System.out.println();
            }
            out.println(TreapBST.getSize(root));
        }

    }

    static class TreapBST {
        static Random random = new Random();

        public static int getSize(TreapBST.Treap root) {
            return root == null ? 0 : root.size;
        }

        public static TreapBST.TreapPair split(TreapBST.Treap root, int minRight) {
            if (root == null)
                return new TreapBST.TreapPair(null, null);
            root.update();
            if (root.key >= minRight) {
                TreapBST.TreapPair leftSplit = split(root.left, minRight);
                root.left = leftSplit.right;
                root.update();
                leftSplit.right = root;
                return leftSplit;
            } else {
                TreapBST.TreapPair rightSplit = split(root.right, minRight);
                root.right = rightSplit.left;
                root.update();
                rightSplit.left = root;
                return rightSplit;
            }
        }

        public static TreapBST.Treap merge(TreapBST.Treap left, TreapBST.Treap right) {
            if (left == null)
                return right;
            if (right == null)
                return left;
            left.update();
            right.update();
            // if (random.nextInt(left.size + right.size) < left.size) {
            if (left.prio > right.prio) {
                left.right = merge(left.right, right);
                left.update();
                return left;
            } else {
                right.left = merge(left, right.left);
                right.update();
                return right;
            }
        }

        public static TreapBST.Treap insert(TreapBST.Treap root, int key) {
            TreapBST.TreapPair t = split(root, key);
            return merge(merge(t.left, new TreapBST.Treap(key)), t.right);
        }

        public static TreapBST.Treap removeMin(TreapBST.Treap root) {
            if (root.left == null) {
                return root.right;
            }
            return merge(merge(removeMin(root.left), new TreapBST.Treap(root.key)), root.right);
        }

        public static class Treap {
            public int key;
            public int size;
            public long prio;
            public int lazy;
            public TreapBST.Treap left;
            public TreapBST.Treap right;

            public Treap(int key) {
                this.key = key;
                prio = random.nextLong();
                size = 1;
                lazy = 0;
            }

            public void update() {
                size = 1 + getSize(left) + getSize(right);
                if (lazy > 0) {
                    if (left != null) {
                        left.lazy += lazy;
                        left.key += lazy;
                    }
                    if (right != null) {
                        right.lazy += lazy;
                        right.key += lazy;
                    }
                    lazy = 0;
                }
            }

        }

        public static class TreapPair {
            public TreapBST.Treap left;
            public TreapBST.Treap right;

            public TreapPair(TreapBST.Treap left, TreapBST.Treap right) {
                this.left = left;
                this.right = right;
            }

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
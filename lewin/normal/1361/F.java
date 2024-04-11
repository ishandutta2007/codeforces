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
 *
 * @author lewin
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        IJohnnyAndNewToy solver = new IJohnnyAndNewToy();
        solver.solve(1, in, out);
        out.close();
    }

    static class IJohnnyAndNewToy {
        int n;
        int[] p;
        int[] w;
        IJohnnyAndNewToy.Tree[] leaf;
        int lidx;
        long ans = 0;

        public IJohnnyAndNewToy.Tree create(int start, int end) {
            if (start + 1 == end) {
                leaf[lidx] = new IJohnnyAndNewToy.Tree();
                leaf[lidx].vals = new TreapBST.Treap(p[start]);
                leaf[lidx].count = 0;
                leaf[lidx].size = 1;
                return leaf[lidx++];
            }
            int mn = start + 1;
            for (int i = start + 1; i < end; i++) {
                if (w[i] < w[mn]) mn = i;
            }
            IJohnnyAndNewToy.Tree cur = new IJohnnyAndNewToy.Tree();
            cur.left = create(start, mn);
            cur.right = create(mn, end);
            cur.left.par = cur;
            cur.left.side = 0;
            cur.right.par = cur;
            cur.right.side = 1;
            cur.size = cur.left.size + cur.right.size;
            cur.a1 = 0;
            cur.a2 = 0;
            for (int i = start; i < mn; i++) {
                int c1 = TreapBST.rank(cur.right.vals, p[i]);
                cur.a1 += c1;
                cur.a2 += cur.right.size - c1;
            }
            cur.count = Math.min(cur.a1, cur.a2);
            ans += cur.count;
            cur.vals = null;
            for (int i = start; i < end; i++) {
                cur.vals = TreapBST.insert(cur.vals, p[i]);
            }
            return cur;
        }

        void remove(IJohnnyAndNewToy.Tree cur, int value) {
            cur.vals = TreapBST.remove(cur.vals, value);
            cur.size--;
            int side = cur.side;
            cur = cur.par;
            while (cur != null) {
                if (side == 0) {
                    int c = TreapBST.rank(cur.right.vals, value);
                    cur.a1 -= c;
                    cur.a2 -= cur.right.size - c;
                } else {
                    int c = TreapBST.rank(cur.left.vals, value);
                    cur.a2 -= c;
                    cur.a1 -= cur.left.size - c;
                }
                ans -= cur.count;
                cur.count = Math.min(cur.a1, cur.a2);
                ans += cur.count;

                cur.size--;
                cur.vals = TreapBST.remove(cur.vals, value);
                side = cur.side;
                cur = cur.par;
            }
        }

        void add(IJohnnyAndNewToy.Tree cur, int value) {
            cur.vals = TreapBST.insert(cur.vals, value);
            cur.size++;
            int side = cur.side;
            cur = cur.par;
            while (cur != null) {
                if (side == 0) {
                    int c = TreapBST.rank(cur.right.vals, value);
                    cur.a1 += c;
                    cur.a2 += cur.right.size - c;
                } else {
                    int c = TreapBST.rank(cur.left.vals, value);
                    cur.a2 += c;
                    cur.a1 += cur.left.size - c;
                }
                ans -= cur.count;
                cur.count = Math.min(cur.a1, cur.a2);
                ans += cur.count;

                cur.size++;
                cur.vals = TreapBST.insert(cur.vals, value);
                side = cur.side;
                cur = cur.par;
            }
        }

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            n = in.nextInt();
            p = in.readIntArrayAndDecrementOne(n);
            w = new int[n + 1];
            for (int i = 1; i < n; i++) w[i] = in.nextInt() - 1;
            leaf = new IJohnnyAndNewToy.Tree[n];
            lidx = 0;
            create(0, n);
            int q = in.nextInt();
            while (q-- > 0) {
                int x = in.nextInt() - 1, y = in.nextInt() - 1;
                if (x != y) {
                    remove(leaf[x], p[x]);
                    remove(leaf[y], p[y]);
                    add(leaf[x], p[y]);
                    add(leaf[y], p[x]);
                    int t = p[x];
                    p[x] = p[y];
                    p[y] = t;
                }
                out.println(ans);
            }
        }

        static class Tree {
            public IJohnnyAndNewToy.Tree left;
            public IJohnnyAndNewToy.Tree right;
            public IJohnnyAndNewToy.Tree par;
            public int side;
            public TreapBST.Treap vals;
            public long count;
            public long a1;
            public long a2;
            public int size;

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

        public int[] readIntArrayAndDecrementOne(int tokens) {
            int[] ret = new int[tokens];
            for (int i = 0; i < tokens; i++) {
                ret[i] = nextInt() - 1;
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
            if (left != null) left.update();
            if (right != null) right.update();
            if (left == null)
                return right;
            if (right == null)
                return left;
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

        public static TreapBST.Treap remove(TreapBST.Treap root, int key) {
            TreapBST.TreapPair t = split(root, key);
            return merge(t.left, split(t.right, key + 1).right);
        }

        public static int rank(TreapBST.Treap root, int val) {
            if (root == null) {
                return 0;
            }
            if (root.key <= val) {
                return rank(root.right, val) + 1 + getSize(root.left);
            } else {
                return rank(root.left, val);
            }
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
                if (lazy != 0) {
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
}
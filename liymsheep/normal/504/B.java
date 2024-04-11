import java.io.InputStream;
import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.BufferedReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.InputStreamReader;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskB {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int[] p1 = new int[n];
            int[] p2 = new int[n];
            for (int i = 0; i < n; ++i) {
                p1[i] = in.nextInt();
            }
            for (int i = 0; i < n; ++i) {
                p2[i] = in.nextInt();
            }

            BitIndexedTree bit1 = new BitIndexedTree(n);
            BitIndexedTree bit2 = new BitIndexedTree(n);
            boolean carry = false;
            int[] rank = new int[n];
            for (int i = n - 1; i >= 0; --i) {
                int numbers = n - i;
                int rank1 = bit1.getSum(p1[i]);
                int rank2 = bit2.getSum(p2[i]);
//            System.err.println(i + " " + rank1 + " " + rank2 + " " + carry);
                rank[i] = (rank1 + rank2 + (carry ? 1 : 0)) % numbers;
                carry = (rank1 + rank2 + (carry ? 1 : 0)) >= numbers;
                bit1.update(p1[i], 1);
                bit2.update(p2[i], 1);
            }

//        System.err.println(Arrays.toString(rank));

            BitIndexedTree bit = new BitIndexedTree(n);
            for (int i = 0; i < n; ++i) {
                bit.update(i, 1);
            }

            for (int i = 0; i < n; ++i) {
                if (i > 0) out.print(" ");
                int ans = bit.locate(rank[i] + 1);
                out.print(ans);
                bit.update(ans, -1);
            }
            out.println();
        }

        static class BitIndexedTree {
            int[] arr;
            private int size;

            BitIndexedTree(int size) {
                this.size = size;
                arr = new int[size + 2];
            }

            private int lowbit(int x) {
                return x & -x;
            }

            public void update(int x, int y) {
                ++x;
                while (x < arr.length) {
                    arr[x] += y;
                    x += lowbit(x);
                }
            }

            public int getSum(int x) {
                ++x;
                int ret = 0;
                while (x > 0) {
                    ret += arr[x];
                    x -= lowbit(x);
                }

                return ret;
            }

            public int locate(int x) {
                int current = 0;
                for (int i = 20; i >= 0; --i) {
                    if ((current + (1 << i)) < arr.length) {
                        if (arr[current + (1 << i)] < x) {
                            x -= arr[current + (1 << i)];
                            current += (1 << i);
                        }
                    }
                }
                if (current >= arr.length) throw new RuntimeException();
                return current;
            }

        }

    }

    static class InputReader {
        BufferedReader reader;
        StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream));
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (Exception e) {
                    throw new UnknownError();
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

    }
}
import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.math.BigInteger;
import java.io.IOException;
import java.util.BitSet;
import java.io.BufferedReader;
import java.io.InputStreamReader;
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
        PrintWriter out = new PrintWriter(outputStream);
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt(), m = in.nextInt();
            BitSet[] basisidx = new BitSet[n];
            BigInteger[] basis = new BigInteger[n];
            BigInteger[] vals = new BigInteger[n];
            for (int i = 0; i < n; i++) {
                vals[i] = BigInteger.ZERO;
            }

            TaskD.Pair[] p = new TaskD.Pair[m];
            for (int i = 0; i < m; i++) {
                int a = in.nextInt() - 1, b = in.nextInt() - 1;
                p[i] = new TaskD.Pair(a, b);
                vals[a] = vals[a].setBit(b);
            }
            for (int i = 0; i < n; i++) {
                BitSet r = new BitSet();
                BigInteger x = vals[i];
                r.set(i);
                for (int j = 0; j < i; j++) {
                    BigInteger t = x.xor(basis[j]);
                    if (t.compareTo(x) < 0) {
                        x = t;
                        r.xor(basisidx[j]);
                    }
                }
                basis[i] = x;
                basisidx[i] = r;
            }
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    if (basis[i].compareTo(basis[j]) < 0) {
                        BigInteger t = basis[i];
                        basis[i] = basis[j];
                        basis[j] = t;

                        basisidx[i].xor(basisidx[j]);
                        basisidx[j].xor(basisidx[i]);
                        basisidx[i].xor(basisidx[j]);
                    }
                }
            }
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    if (basis[i].testBit(n-j-1)) {
                        basis[i] = basis[i].xor(basis[j]);
                        basisidx[i].xor(basisidx[j]);
                    }
                }
            }

            for (int i = 0; i < m; i++) {
                if (basisidx[n - 1 - p[i].b].get(p[i].a)) {
                    out.println("NO");
                } else {
                    out.println("YES");
                }
            }
        }

        static class Pair {
            public int a;
            public int b;

            public Pair(int a, int b) {
                this.a = a;
                this.b = b;
            }

        }

    }

    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

    }
}
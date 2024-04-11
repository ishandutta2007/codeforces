import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.HashMap;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.Map.Entry;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.io.BufferedReader;
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
        InputReader2 in = new InputReader2(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        BFishWeight solver = new BFishWeight();
        solver.solve(1, in, out);
        out.close();
    }

    static class BFishWeight {
        public void solve(int testNumber, InputReader2 in, OutputWriter out) {
            int n = in.nextInt(), m = in.nextInt(), k = in.nextInt();
            HashMap<Integer, Integer> ct = new HashMap<>();
            for (int i = 0; i < n; i++) {
                int a = in.nextInt() - 1;
                if (ct.containsKey(a)) {
                    ct.put(a, ct.get(a) + 1);
                } else {
                    ct.put(a, 1);
                }
            }
            for (int i = 0; i < m; i++) {
                int b = in.nextInt() - 1;
                if (ct.containsKey(b)) {
                    ct.put(b, ct.get(b) - 1);
                } else {
                    ct.put(b, -1);
                }
            }
            BFishWeight.Pair[] ps = new BFishWeight.Pair[ct.size()];
            int id = 0;
            for (var e : ct.entrySet()) {
                int a = e.getKey(), b = e.getValue();
                ps[id++] = new BFishWeight.Pair(a, b);
            }
            Arrays.sort(ps, Comparator.comparingInt(x -> x.a));

            int bcount = 0, acount = 0;
            for (int i = ps.length - 1; i >= 0; i--) {
                if (ps[i].which == 0) {
                    acount += ps[i].b;
                } else {
                    bcount += ps[i].b;
                }
                if (acount > bcount) {
                    out.println("YES");
                    return;
                }
            }
            out.println("NO");
        }

        static class Pair {
            public int a;
            public int b;
            public int which;

            public Pair(int a, int b) {
                this.a = a;
                if (b > 0) {
                    this.b = b;
                    this.which = 0;
                } else {
                    this.b = -b;
                    this.which = 1;
                }
            }

        }

    }

    static class InputReader2 {
        private BufferedReader in;
        private StringTokenizer st;

        public InputReader2(InputStream stream) {
            in = new BufferedReader(new InputStreamReader(stream));
            st = null;
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public String next() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(in.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
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
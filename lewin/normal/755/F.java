import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.math.BigInteger;
import java.io.BufferedReader;
import java.util.Collections;
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
        TaskF solver = new TaskF();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskF {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt(), k = in.nextInt();
            int[] perm = new int[n];
            for (int i = 0; i < n; i++) perm[i] = in.nextInt() - 1;
            boolean[] vis = new boolean[n];
            ArrayList<Integer> cycles = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                if (!vis[i]) {
                    int c = i;
                    int size = 0;
                    do {
                        vis[c] = true;
                        c = perm[c];
                        size++;
                    } while (c != i);
                    cycles.add(size);
                }
            }
            int max = 0;
            int tk = k;
            for (int d : cycles) {
                int take = Math.min(tk, d / 2);
                max += take * 2;
                tk -= take;
            }
            for (int d : cycles) {
                if (d % 2 == 1) {
                    if (tk > 0) {
                        max++;
                        tk--;
                    }
                }
            }
            int min = k;
            // check if subset of cycles equals k
            if (!can(cycles, Math.min(k, n - k))) min++;
            out.println(min + " " + max);
        }

        public boolean can(ArrayList<Integer> items, int need) {
            if (need == 0) return true;
            for (int s : items) if (s == need) return true;
            ArrayList<Integer> d = new ArrayList<>();
            for (int s : items) if (s <= need) d.add(s);
            Collections.sort(d);
            BigInteger mask = BigInteger.ONE;
            mask = mask.shiftLeft(need);
            for (int i = 0; i < d.size(); i++) {
                int j = i;
                while (j + 1 < d.size() && d.get(j + 1) == d.get(i)) j++;
                int amt = j - i + 1;
                int nxt = 1;
                while (amt > 0) {
                    int w = Math.min(amt, nxt);
                    amt -= w;
                    nxt *= 2;
                    mask = mask.or(mask.shiftRight(d.get(i) * w));
                }
                i = j;
            }
            return mask.testBit(0);
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
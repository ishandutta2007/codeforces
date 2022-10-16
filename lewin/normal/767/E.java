import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.PriorityQueue;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.io.BufferedReader;
import java.util.Comparator;
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
        TaskE solver = new TaskE();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskE {
        public int m;
        public int[] choices;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt();
            m = in.nextInt();
            int[] tt = in.readIntArray(n);
            int[] arr = new int[n];
            for (int i = 0; i < n; i++) arr[i] = tt[i] % 100;
            int[] w = in.readIntArray(n);
            PriorityQueue<TaskE.Item> pq = new PriorityQueue<>(Comparator.comparingLong(x -> x.weight));
            long ccoins = m;
            choices = new int[n];
            long ans = 0;
            for (int i = 0; i < n; i++) {
                if (arr[i] == 0) continue;
                int change = 100 - arr[i];
                ccoins -= arr[i];
                pq.add(new TaskE.Item(i, 1L * change * w[i]));
                if (ccoins < 0) {
                    TaskE.Item d = pq.poll();
                    choices[d.idx] = 1;
                    ans += d.weight;
                    ccoins += 100;
                }
            }
            out.println(ans);
            for (int i = 0; i < n; i++) {
                if (choices[i] == 1) {
                    out.println((tt[i] + 99) / 100 + " " + 0);
                } else {
                    out.println((tt[i] / 100) + " " + (tt[i] % 100));
                }
            }
        }

        static class Item {
            public int idx;
            public long weight;

            public Item(int idx, long weight) {
                this.idx = idx;
                this.weight = weight;
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

        public int[] readIntArray(int tokens) {
            int[] ret = new int[tokens];
            for (int i = 0; i < tokens; i++) {
                ret[i] = nextInt();
            }
            return ret;
        }

        public int nextInt() {
            return Integer.parseInt(next());
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

        public void println(long i) {
            writer.println(i);
        }

    }
}
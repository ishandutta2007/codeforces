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
import java.io.BufferedReader;
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
            int[] f = new int[n + 1];
            for (int i = 1; i <= n; i++) f[i] = in.nextInt();
            boolean[] ok = new boolean[n + 1];
            for (int i = 1; i <= n; i++) {
                if (f[i] == i) {
                    ok[i] = true;
                }
            }
            for (int i = 1; i <= n; i++) {
                if (!ok[f[i]]) {
                    out.println(-1);
                    return;
                }
            }
            int count = 0;
            int[] label = new int[n + 1];
            int idx = 1;
            ArrayList<Integer> x = new ArrayList<>();
            for (int i = 1; i <= n; i++) {
                if (ok[i]) {
                    count++;
                    label[i] = idx++;
                    x.add(i);
                }
            }
            out.println(count);
            for (int i = 1; i <= n; i++) {
                if (i != 1) out.print(" ");
                out.print(label[f[i]]);
            }
            out.println();
            for (int j = 0; j < x.size(); j++) {
                if (j != 0) out.print(" ");
                out.print(x.get(j));
            }
            out.println();
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

        public void println() {
            writer.println();
        }

        public void close() {
            writer.close();
        }

        public void print(int i) {
            writer.print(i);
        }

        public void println(int i) {
            writer.println(i);
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
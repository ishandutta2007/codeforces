import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.io.BufferedReader;
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
        CBubbleStrike solver = new CBubbleStrike();
        solver.solve(1, in, out);
        out.close();
    }

    static class CBubbleStrike {
        double getProb(int x, int n) {
            return 3.0 / 2.0 * x / n * (n - x) / (n - 1) * (n - x - 1) / (n - 2) + 3.0 * x / n * (x - 1) / (n - 1) * (n - x) / (n - 2) + 1.0 * x / n * (x - 1) / (n - 1) * (x - 2) / (n - 2);
        }

        public void solve(int testNumber, InputReader2 in, OutputWriter out) {
            int n = in.nextInt();
            double p = in.nextDouble();
            int x = 0;
            while (getProb(x, n) < p) x++;
            out.println(x);
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

        public double nextDouble() {
            return Double.parseDouble(next());
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
}
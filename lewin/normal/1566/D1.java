import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
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
        D1SeatingArrangementsEasyVersion solver = new D1SeatingArrangementsEasyVersion();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class D1SeatingArrangementsEasyVersion {
        public void solve(int testNumber, InputReader2 in, OutputWriter out) {
            int n = in.nextInt(), m = in.nextInt();
            int[] arr = in.readIntArray(n * m);
            D1SeatingArrangementsEasyVersion.order[] od = new D1SeatingArrangementsEasyVersion.order[m];
            for (int i = 0; i < m; i++) {
                od[i] = new D1SeatingArrangementsEasyVersion.order(arr[i], i);
            }
            Arrays.sort(od, (a, b) -> {
                if (a.sight != b.sight) return b.sight - a.sight;
                return a.idx - b.idx;
            });
            int ans = 0;
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < i; j++) {
                    if (od[i].idx < od[j].idx) {
                        ans++;
                    }
                }
            }
            out.println(ans);

        }

        static class order {
            public int sight;
            public int idx;

            public order(int sight, int idx) {
                this.sight = sight;
                this.idx = idx;
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

        public void close() {
            writer.close();
        }

        public void println(int i) {
            writer.println(i);
        }

    }
}
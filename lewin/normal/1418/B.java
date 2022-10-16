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
        BNegativePrefixes solver = new BNegativePrefixes();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class BNegativePrefixes {
        public int eval(int[] arr) {
            int mxk = 0, p = 0;
            for (int k = 0; k < arr.length; k++) {
                p += arr[k];
                if (p < 0) mxk = k + 1;
            }
            return mxk;
        }

        public void solve(int testNumber, InputReader2 in, OutputWriter out) {
            int n = in.nextInt();
            int[] arr = in.readIntArray(n);
            int[] locked = in.readIntArray(n);
            int[] neg = new int[n], pos = new int[n];
            int nid = 0, pid = 0;
            for (int i = 0; i < n; i++) {
                if (locked[i] == 0) {
                    if (arr[i] < 0) {
                        neg[nid++] = arr[i];
                    } else {
                        pos[pid++] = arr[i];
                    }
                }
            }
            Arrays.sort(neg, 0, nid);
            Arrays.sort(pos, 0, pid);

            int[] best = Arrays.copyOf(arr, n);
            int mk = eval(best);
            for (int takeneg = 0; takeneg <= nid; takeneg++) {
                int[] barr = new int[n];
                int idnb = 0;
                int tt = takeneg;
                int idp = pid - 1;
                int idnf = nid - 1;
                for (int i = 0; i < n; i++) {
                    if (locked[i] == 1) {
                        barr[i] = arr[i];
                    } else {
                        if (tt > 0) {
                            barr[i] = neg[idnb++];
                            tt--;
                        } else if (idp >= 0) {
                            barr[i] = pos[idp--];
                        } else {
                            barr[i] = neg[idnf--];
                        }
                    }
                }
                int tk = eval(barr);
                if (tk < mk) {
                    best = barr;
                    mk = tk;
                }
            }
            out.println(best);
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

        public void print(int[] array) {
            for (int i = 0; i < array.length; i++) {
                if (i != 0) {
                    writer.print(' ');
                }
                writer.print(array[i]);
            }
        }

        public void println(int[] array) {
            print(array);
            writer.println();
        }

        public void close() {
            writer.close();
        }

    }
}
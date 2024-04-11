import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.stream.IntStream;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.io.Writer;
import java.io.OutputStreamWriter;
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
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        CPetyaAndExam solver = new CPetyaAndExam();
        solver.solve(1, in, out);
        out.close();
    }

    static class CPetyaAndExam {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int t = in.nextInt();
            while (t-- > 0) {
                int n = in.nextInt(), T = in.nextInt(), a = in.nextInt(), b = in.nextInt();
                int[] ds = in.readIntArray(n);
                int[] req = in.readIntArray(n);
                PriorityQueue<CPetyaAndExam.Problem> pq = new PriorityQueue<>(Comparator.comparingInt(x -> x.time));
                int hard = AUtils.sum(ds), easy = n - hard;
                for (int i = 0; i < n; i++) {
                    pq.add(new CPetyaAndExam.Problem(req[i], ds[i]));
                }
                long used = 0;
                int count = 0;
                long best = 0;
                while (pq.size() > 0) {
                    CPetyaAndExam.Problem p = pq.poll();
                    // leave at time p.time - 1
                    long timeleft = p.time - 1 - used;
                    if (timeleft >= 0) {
                        long takeeasy = Math.min(easy, timeleft / a);
                        timeleft -= takeeasy * a;
                        long takehard = Math.min(hard, timeleft / b);
                        best = Math.max(best, count + takeeasy + takehard);
                    }
                    // leave at time p.time
                    used += p.type == 0 ? a : b;
                    count++;
                    if (p.type == 0) easy--;
                    else hard--;
                    while (pq.size() > 0 && pq.peek().time == p.time) {
                        CPetyaAndExam.Problem q = pq.poll();
                        used += q.type == 0 ? a : b;
                        count++;
                        if (q.type == 0) easy--;
                        else hard--;
                    }
                    timeleft = p.time - used;
                    if (timeleft >= 0) {
                        long takeeasy = Math.min(easy, timeleft / a);
                        timeleft -= takeeasy * a;
                        long takehard = Math.min(hard, timeleft / b);
                        best = Math.max(best, count + takeeasy + takehard);
                    }
                }
                // leave at time T
                long timeleft = T - used;
                if (timeleft >= 0) {
                    long takeeasy = Math.min(easy, timeleft / a);
                    timeleft -= takeeasy * a;
                    long takehard = Math.min(hard, timeleft / b);
                    best = Math.max(best, count + takeeasy + takehard);
                }
                out.println(best);
            }
        }

        static class Problem {
            int time;
            int type;

            public Problem(int time, int type) {
                this.time = time;
                this.type = type;
            }

        }

    }

    static class AUtils {
        public static int sum(int[] arr) {
            return Arrays.stream(arr).reduce(0, Integer::sum);
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

        public int[] readIntArray(int tokens) {
            int[] ret = new int[tokens];
            for (int i = 0; i < tokens; i++) {
                ret[i] = nextInt();
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
}
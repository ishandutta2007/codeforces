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
        TaskA solver = new TaskA();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskA {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int hy = in.nextInt();
            int ay = in.nextInt();
            int dy = in.nextInt();

            int hm = in.nextInt();
            int am = in.nextInt();
            int dm = in.nextInt();

            int h = in.nextInt();
            int a = in.nextInt();
            int d = in.nextInt();

            int ans = Integer.MAX_VALUE;
            for (int ad = 0; ad <= dm + hm; ++ad) {
                for (int dd = 0; dd <= am; ++dd) {
                    for (int hd = 0; hd <= Math.max(0, am - (dd + dy)) * 100; ++hd) {
                        int hx = hd + hy;
                        int ax = ad + ay;
                        int dx = dd + dy;

                        if (ax > dm) {
                            if (am <= dx || hx > am - dx
                                    && ((hm + (ax - dm - 1)) / (ax - dm)) <= ((hx - (am - dx) + (am - dx - 1)) / (am - dx))) {
                                ans = Math.min(ans, hd * h + ad * a + dd * d);
                            }
                        }
                    }
                    if (dd + dy >= am) break;
                }
                if (ad + ay >= dm + hm) break;
            }

            out.println(ans);
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
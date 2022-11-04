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
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            Point a = new Point(in.nextInt(), in.nextInt());
            Point b = new Point(in.nextInt(), in.nextInt());
            Point c = new Point(in.nextInt(), in.nextInt());

            if (a.subtract(b).det(a.subtract(c)) == 0) {
                Point dir = a.subtract(b);
                if (dir.x == 0 || dir.y == 0) {
                    out.println(1);
                    return;
                }
            }

            long[] xs = new long[]{a.x, b.x, c.x};
            long[] ys = new long[]{a.y, b.y, c.y};

            for (long x : xs) {
                outer:
                for (long y : ys) {
                    Point o = new Point(x, y);

                    int dirs = 0;
                    for (Point t : new Point[]{a, b, c}) {
                        Point p = t.subtract(o);
                        if (p.x != 0 && p.y != 0) {
                            continue outer;
                        }
if (p.x == 0 && p.y == 0) continue;
                        if (p.x == 0) {
                            dirs |= 1 << (p.y < 0 ? 0 : 1);
                        } else {
                            dirs |= 1 << (p.x < 0 ? 2 : 3);
                        }
                    }

                    if (Integer.bitCount(dirs) == 2) {
                        out.println(2);
                        return;
                    }
                }
            }

            out.print(3);
        }

        static class Point {
            long x;
            long y;

            Point(long x, long y) {
                this.x = x;
                this.y = y;
            }

            Point subtract(Point o) {
                return new Point(x - o.x, y - o.y);
            }

            long det(Point o) {
                return x * o.y - y * o.x;
            }

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
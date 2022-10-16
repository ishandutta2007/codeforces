import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.ArrayList;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.Comparator;
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
        TaskE solver = new TaskE();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskE {
        public double EPS = 1e-12;

        public TaskE.Circle solveApollonius(TaskE.Circle c1, TaskE.Circle c2, TaskE.Circle c3, int s1,
                                            int s2, int s3) {
            double x1 = c1.center[0];
            double y1 = c1.center[1];
            double r1 = c1.radius;
            double x2 = c2.center[0];
            double y2 = c2.center[1];
            double r2 = c2.radius;
            double x3 = c3.center[0];
            double y3 = c3.center[1];
            double r3 = c3.radius;


            double v11 = 2 * x2 - 2 * x1;
            double v12 = 2 * y2 - 2 * y1;
            double v13 = x1 * x1 - x2 * x2 + y1 * y1 - y2 * y2 - r1 * r1 + r2 * r2;
            double v14 = 2 * s2 * r2 - 2 * s1 * r1;

            double v21 = 2 * x3 - 2 * x2;
            double v22 = 2 * y3 - 2 * y2;
            double v23 = x2 * x2 - x3 * x3 + y2 * y2 - y3 * y3 - r2 * r2 + r3 * r3;
            double v24 = 2 * s3 * r3 - 2 * s2 * r2;

            double w12 = v12 / v11;
            double w13 = v13 / v11;
            double w14 = v14 / v11;

            double w22 = v22 / v21 - w12;
            double w23 = v23 / v21 - w13;
            double w24 = v24 / v21 - w14;

            double P = -w23 / w22;
            double Q = w24 / w22;
            double M = -w12 * P - w13;
            double N = w14 - w12 * Q;

            double a = N * N + Q * Q - 1;
            double b = 2 * M * N - 2 * N * x1 + 2 * P * Q - 2 * Q * y1 + 2 * s1 * r1;
            double c = x1 * x1 + M * M - 2 * M * x1 + P * P + y1 * y1 - 2 * P * y1 - r1 * r1;

            double D = b * b - 4 * a * c;
            if (D < -EPS || Math.abs(a) < EPS) {
                return null;
            }
            double rs = (-b - Math.sqrt(Math.max(0, D))) / (2 * a);
            double xs = M + N * rs;
            double ys = P + Q * rs;
            return new TaskE.Circle(new double[]{xs, ys}, rs);
        }

        public boolean ccw(double[] a, double[] b, double[] c) {
            return (c[1] - a[1]) * (b[0] - a[0]) > (b[1] - a[1]) * (c[0] - a[0]);
        }

        public double dist(double[] x, double[] y) {
            return Math.sqrt((x[0] - y[0]) * (x[0] - y[0]) + (x[1] - y[1]) * (x[1] - y[1]));
        }

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int x1 = in.nextInt(), y1 = in.nextInt(), x2 = in.nextInt(), y2 = in.nextInt();
            double angle = Math.random() * Math.PI * 2;
            double ca = Math.cos(angle), sa = Math.sin(angle);
            TaskE.Circle c1 = new TaskE.Circle(new double[]{ca * x1 - sa * y1, sa * x1 + ca * y1}, 0);
            TaskE.Circle c2 = new TaskE.Circle(new double[]{ca * x2 - sa * y2, sa * x2 + ca * y2}, 0);
            int n = in.nextInt();
            ArrayList<TaskE.Event> es = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                int x = in.nextInt(), y = in.nextInt();
                TaskE.Circle c = new TaskE.Circle(new double[]{ca * x - sa * y, sa * x + ca * y}, in.nextInt());
                TaskE.Circle a1 = solveApollonius(c, c1, c2, +1, +1, +1);
                TaskE.Circle a2 = solveApollonius(c, c1, c2, -1, +1, +1);
                boolean b1 = ccw(c1.center, c2.center, a1.center);
                boolean b2 = ccw(c1.center, c2.center, a2.center);
                double e1 = a1.radius * (b1 ? -1 : 1);
                double e2 = a2.radius * (b2 ? -1 : 1);

                if (e1 > e2) {
                    double t = e1;
                    e1 = e2;
                    e2 = t;
                }
                es.add(new TaskE.Event(e1, +1));
                es.add(new TaskE.Event(e2, -1));
            }
            es.add(new TaskE.Event(dist(c1.center, c2.center) / 2, 0));
            es.add(new TaskE.Event(-dist(c1.center, c2.center) / 2, 0));
            Collections.sort(es, Comparator.comparingDouble(x -> x.rad));
            double best = 1L << 60;
            int ss = 0;
            for (int i = 0; i < es.size(); i++) {
                TaskE.Event e = es.get(i);
                if (ss == 0) {
                    best = Math.min(best, Math.abs(e.rad));
                }
                ss += e.type;
                if (ss == 0) {
                    best = Math.min(best, Math.abs(e.rad));
                }
            }
            out.printf("%.20f\n", best);

        }

        static class Circle {
            public double[] center;
            public double radius;

            public Circle(double[] center, double radius) {
                this.center = center;
                this.radius = radius;
            }

            public String toString() {
                return String.format("Circle[x=%.5f,y=%.5f,r=%.5f]", center[0], center[1],
                        radius);
            }

        }

        static class Event {
            public double rad;
            public int type;

            public Event(double rad, int type) {
                this.rad = rad;
                this.type = type;
            }

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

        public void printf(String format, Object... objects) {
            writer.printf(format, objects);
        }

        public void close() {
            writer.close();
        }

    }

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;

        public InputReader(InputStream stream) {
            this.stream = stream;
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
}
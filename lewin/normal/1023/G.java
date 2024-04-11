import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.util.Set;
import java.util.InputMismatchException;
import java.util.HashMap;
import java.io.IOException;
import java.util.TreeSet;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;
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
        PiscesFast solver = new PiscesFast();
        solver.solve(1, in, out);
        out.close();
    }

    static class PiscesFast {
        public static int INF = (int) (1e9);
        public static int TIME = 0;
        int n;

        static int sgn(int x) {
            if (x == 0) return 0;
            return x < 0 ? -1 : 1;
        }

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            n = in.nextInt();
            PiscesFast.Node[] ns = new PiscesFast.Node[n];
            for (int i = 0; i < n; i++) ns[i] = new PiscesFast.Node(i);
            for (int i = 0; i < n - 1; i++) {
                int a = in.nextInt() - 1;
                int b = in.nextInt() - 1;
                int w = in.nextInt() * 2;
                ns[a].addEdge(ns[b], w);
                ns[b].addEdge(ns[a], w);
            }

            int k = in.nextInt();
            for (int i = 0; i < k; i++) {
                int d = in.nextInt() * 2;
                int f = in.nextInt();
                int l = in.nextInt() - 1;

                ns[l].addObservation(d, f);
            }

            ns[0].dfsSize(null);
            out.println(ns[0].dfs(null).getMax());
        }

        static class State {
            TreeSet<PiscesFast.State.Segment> small;
            TreeSet<PiscesFast.State.Point> bounds;

            void addSegment(PiscesFast.State.Point l, PiscesFast.State.Point r) {
                int speed = sgn(r.diff) - sgn(l.diff);
                if (speed > 0) {
                    int t = (r.pos() - l.pos() + speed - 1) / speed + TIME;
                    small.add(new PiscesFast.State.Segment(t, l));
                }
            }

            void removeSegment(PiscesFast.State.Point l, PiscesFast.State.Point r) {
                int speed = sgn(r.diff) - sgn(l.diff);
                if (speed > 0) {
                    int t = (r.pos() - l.pos() + speed - 1) / speed + TIME;
                    small.remove(new PiscesFast.State.Segment(t, l));
                }
            }

            public State() {
                bounds = new TreeSet<>();
                small = new TreeSet<>();
                bounds.add(new PiscesFast.State.Point(-INF, 0));
                bounds.add(new PiscesFast.State.Point(INF, 0));
                addSegment(bounds.first(), bounds.last());
            }

            void proceed(int time) {
                while (small.size() > 0 && small.first().a <= time) {
                    PiscesFast.State.Point a = small.first().p;
                    PiscesFast.State.Point b = bounds.higher(a);
                    int ctime = small.first().a;
                    removeSegment(a, b);

                    int pos = a.pos(ctime);
                    int cdiff = a.diff + b.diff;
                    if (b.pos(ctime) != pos && cdiff > 0) pos--;

                    PiscesFast.State.Point c = bounds.lower(a);
                    PiscesFast.State.Point d = bounds.higher(b);
                    removeSegment(c, a);
                    removeSegment(b, d);
                    bounds.remove(b);
                    bounds.remove(a);

                    PiscesFast.State.Point x = new PiscesFast.State.Point(pos, cdiff, ctime);
                    bounds.add(x);
                    addSegment(c, x);
                    addSegment(x, d);
                }
                TIME = time;
            }

            int get(int x) {
                int ans = 0;
                PiscesFast.State.Point p = bounds.ceiling(new PiscesFast.State.Point(x, 0));
                if (p.pos() == x && p.diff < 0) ans = Math.max(ans, -p.diff);
                p = bounds.ceiling(new PiscesFast.State.Point(x + 1, 0));
                if (p.pos() == x + 1 && p.diff > 0) ans = Math.max(ans, p.diff);
                return ans;
            }

            void add(int x, int t) {
                PiscesFast.State.Point toadd = new PiscesFast.State.Point(x, t);
                PiscesFast.State.Point g = bounds.ceiling(toadd);
                if (toadd.compareTo(g) < 0) {
                    PiscesFast.State.Point a = bounds.lower(g);
                    removeSegment(a, g);
                    bounds.add(toadd);
                    addSegment(a, toadd);
                    addSegment(toadd, g);
                } else {
                    PiscesFast.State.Point a = bounds.lower(g);
                    PiscesFast.State.Point b = bounds.higher(g);
                    removeSegment(a, g);
                    removeSegment(g, b);
                    toadd = new PiscesFast.State.Point(x, t + g.diff);
                    bounds.remove(g);
                    bounds.add(toadd);
                    addSegment(a, toadd);
                    addSegment(toadd, b);
                }
            }

            int getMax() {
                int res = 0;
                int c = 0;
                for (PiscesFast.State.Point p : bounds) {
                    c += p.diff;
                    res = Math.max(res, c);
                }
                return res;
            }

            static class Point implements Comparable<PiscesFast.State.Point> {
                public int x;
                public int diff;

                public Point(int x, int diff) {
                    this(x, diff, TIME);
                }

                public Point(int x, int diff, int time) {
                    this.diff = diff;
                    this.x = x + sgn(diff) * time;
                }

                public int pos() {
                    return pos(TIME);
                }

                public int pos(int time) {
                    return x - sgn(diff) * time;
                }

                public int compareTo(PiscesFast.State.Point other) {
                    return pos() - other.pos();
                }

                public boolean equals(Object o) {
                    if (this == o) return true;
                    if (o == null || getClass() != o.getClass()) return false;

                    PiscesFast.State.Point point = (PiscesFast.State.Point) o;

                    if (x != point.x) return false;
                    return diff == point.diff;
                }

                public int hashCode() {
                    int result = x;
                    result = 31 * result + diff;
                    return result;
                }

                public String toString() {
                    return x + " " + diff;
                }

            }

            static class Segment implements Comparable<PiscesFast.State.Segment> {
                public int a;
                public PiscesFast.State.Point p;

                public Segment(int index, PiscesFast.State.Point p) {
                    this.a = index;
                    this.p = p;
                }

                public int compareTo(PiscesFast.State.Segment other) {
                    if (a != other.a) return a - other.a;
                    else return p.compareTo(other.p);
                }

                public boolean equals(Object o) {
                    if (this == o) return true;
                    if (o == null || getClass() != o.getClass()) return false;

                    PiscesFast.State.Segment segment = (PiscesFast.State.Segment) o;

                    if (a != segment.a) return false;
                    return p != null ? p.equals(segment.p) : segment.p == null;
                }

                public int hashCode() {
                    int result = a;
                    result = 31 * result + (p != null ? p.hashCode() : 0);
                    return result;
                }

            }

        }

        static class Node {
            List<PiscesFast.Node> children;
            List<Integer> weights;
            int index;
            int size;
            List<Integer> order;
            HashMap<Integer, Integer> observations;

            public Node(int index) {
                this.index = index;
                children = new ArrayList<>();
                weights = new ArrayList<>();
                observations = new HashMap<>();
                order = new ArrayList<>();
            }

            public void addEdge(PiscesFast.Node other, int weight) {
                children.add(other);
                weights.add(weight);
                order.add(order.size());
            }

            public void addObservation(int time, int fish) {
                observations.put(time, fish);
            }

            public void dfsSize(PiscesFast.Node parent) {
                this.size = 1;
                for (PiscesFast.Node x : children) {
                    if (x == parent) continue;
                    x.dfsSize(this);
                    this.size += x.size;
                }
                order.sort(Comparator.comparingInt(x -> -children.get(x).size));
            }

            public PiscesFast.State dfs(PiscesFast.Node parent) {
                PiscesFast.State cur = null;
                for (int i = 0; i < children.size(); i++) {
                    PiscesFast.Node c = children.get(order.get(i));
                    int len = weights.get(order.get(i));
                    if (c == parent) continue;
                    TIME -= len;
                    PiscesFast.State t = c.dfs(this);
                    t.proceed(TIME + len - 1);
                    if (cur == null) {
                        cur = t;
                    } else {
                        for (PiscesFast.State.Point p : t.bounds) {
                            if (p.pos() > -INF && p.pos() < INF) {
                                cur.add(p.pos(), p.diff);
                            }
                        }
                    }
                }
                if (cur == null) cur = new PiscesFast.State();

                Set<Integer> g = observations.keySet();
                for (int k : g) {
                    observations.put(k, Math.max(0, observations.get(k) - cur.get(k)));
                }
                cur.proceed(TIME + 1);
                for (Map.Entry<Integer, Integer> e : observations.entrySet()) {
                    int k = e.getKey(), v = e.getValue();
                    cur.add(k, v);
                    cur.add(k + 1, -v);
                }
                return cur;
            }

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

        public void println(int i) {
            writer.println(i);
        }

    }
}
import java.io.*;
import java.util.*;

public class Task {

    final int N = 100 * 1000 + 10;
    final int INF = (int) 1e9;

    class SegmentTree {
        int[] data = new int[4 * N + 10];

        void put(int i, int tl, int tr, int pos, int val) {
            if (tl == tr) {
                data[i] = val;
                return;
            }
            int m = (tl + tr) / 2;
            if (pos <= m)
                put(2 * i + 1, tl, m, pos, val);
            else
                put(2 * i + 2, m + 1, tr, pos, val);
            data[i] = Math.min(data[2 * i + 1], data[2 * i + 2]);
        }

        void put(int pos, int val) {
            put(0, 0, N, pos, val);
        }

        int get(int i, int tl, int tr, int l, int r) {
            if (l == tl && r == tr)
                return data[i];
            int m = (tl + tr) / 2;
            int ml = INF;
            int mr = INF;
            if (l <= m)
                ml = get(2 * i + 1, tl, m, l, Math.min(r, m));
            if (r > m)
                mr = get(2 * i + 2, m + 1, tr, Math.max(m + 1, l), r);
            return Math.min(ml, mr);
        }

        int get(int l, int r) {
            return get(0, 0, N, l, r);
        }
    }

    final int CELL = 1;
    final int CLOSE = 2;

    class Event {
        int x;
        int lowY;
        int highY;
        int oldX;
        int type;
        int id;

        Event(int x, int ly, int hy, int oldX, int type, int id) {
            this.x = x;
            lowY = ly;
            highY = hy;
            this.oldX = oldX;
            this.type = type;
            this.id = id;
        }
    }

    int[] cnt;
    int[] x1;
    int[] x2;
    int[] y1;
    int[] y2;
    int[] x;
    int[] y;

    void run() {
        SegmentTree st = new SegmentTree();
        ArrayList<Event> events = new ArrayList<>();
        for (int i = 0; i < x1.length; i++) {
            events.add(new Event(x2[i], y1[i], y2[i], x1[i], CLOSE, i));
        }
        for (int i = 0; i < x.length; i++) {
            events.add(new Event(x[i], y[i], -1, -1, CELL, -1));
        }
        Collections.sort(events, new Comparator<Event>() {
            @Override
            public int compare(Event o1, Event o2) {
                if (o1.x != o2.x)
                    return Integer.compare(o1.x, o2.x);
                return Integer.compare(o1.type, o2.type);
            }
        });
        for (Event e : events) {
            //System.err.println(e.x + " " + e.lowY + " " + e.highY + " " + e.type);
            if (e.type == CELL) {
                st.put(e.lowY, e.x);
            } else {
                int min = st.get(e.lowY, e.highY);
                if (min >= e.oldX)
                    cnt[e.id]++;
            }
            //for (int i = 0; i < 10; i++)
              //  System.err.print(st.get(i, i) + " ");
            //System.err.println();
        }
        //System.err.println();
    }

    public void solve(int testNumber, FastScanner in, PrintWriter out) throws IOException {
        in.next();
        in.next();
        int k = in.nextInt();
        int q = in.nextInt();
        cnt = new int[q];
        //Arrays.fill(ok, true);
        x1 = new int[q];
        y1 = new int[q];
        x2 = new int[q];
        y2 = new int[q];
        x = new int[k];
        y = new int[k];
        for (int i = 0; i < k; i++) {
            x[i] = in.nextInt();
            y[i] = in.nextInt();
        }
        for (int i = 0; i < q; i++) {
            x1[i] = in.nextInt();
            y1[i] = in.nextInt();
            x2[i] = in.nextInt();
            y2[i] = in.nextInt();
        }
        run();
        swap(x, y);
        swap(x1, y1);
        swap(x2, y2);
        run();
        for (int i = 0; i < q; i++)
            out.println(cnt[i] > 0 ? "YES" : "NO");
    }

    void swap(int[] a, int[] b) {
        for (int i = 0; i < a.length; i++) {
            int t = a[i];
            a[i] = b[i];
            b[i] = t;
        }
    }

    public static void main(String[] args) throws IOException {
        FastScanner in = new FastScanner(System.in);
        PrintWriter out = new PrintWriter(System.out);
        int testsCount = 1;
        for (int i = 1; i <= testsCount; i++)
            new Task().solve(i, in, out);
        in.close();
        out.close();
    }
}

class FastScanner {
    private StringTokenizer tokenizer;
    private BufferedReader reader;

    public FastScanner(InputStream inputStream) {
        reader = new BufferedReader(new InputStreamReader(inputStream));
    }

    public String next() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            String line;
            try {
                line = reader.readLine();
            } catch (IOException e) {
                return null;
            }
            if (line == null)
                return null;
            tokenizer = new StringTokenizer(line);
        }
        return tokenizer.nextToken();
    }

    public String nextLine() {
        String line;
        try {
            line = reader.readLine();
        } catch (IOException e) {
            return null;
        }
        return line;
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }

    public long nextLong() {
        return Long.parseLong(next());
    }

    public double nextDouble() {
        return Double.parseDouble(next());
    }

    public void close() {
        try {
            reader.close();
        } catch (IOException e) {

        }
    }
}
import java.io.*;
import java.util.*;

import static java.lang.Math.*;

public class Main extends PrintWriter {
    final Random rand = new Random(31);
    final int inf = (int) 1e9;
    final long linf = (long) 1e18;

    final static String IO = "_std";

    class Item implements Comparable<Item> {
        int d, x, y;

        public Item(int d, int x, int y) {
            this.d = d;
            this.x = x;
            this.y = y;
        }


        @Override
        public int compareTo(Item o) {
            return Integer.compare(d, o.d);
        }
    }

    void solve() throws IOException {
        int n = nextInt();
        int m = nextInt();
        int p = nextInt();
        List<Integer>[] xs = createAdjacencyList(p + 1);
        List<Integer>[] ys = createAdjacencyList(p + 1);
        boolean f1 = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int x = nextInt();
                if (i == 0 && j == 0 && x == 1) {
                    f1 = true;
                }
                xs[x].add(i);
                ys[x].add(j);
            }
        }

        int[][] td = new int[n][m];
        for (int[] i : td) {
            Arrays.fill(i, inf);
        }
        td[0][0] = 0;
        xs[0].add(0);
        ys[0].add(0);

        int[] dx = new int[] {1, -1, 0, 0};
        int[] dy = new int[] {0, 0, 1, -1};
        int[][] d = new int[n][m];

        for (int t = 1; t <= p; t++) {
            if (t == 2 && !f1) {
                td[0][0] = inf;
            }
            if (xs[t - 1].size() <= n * 2) {
                for (int i = 0; i < xs[t].size(); i++) {
                    int vx = xs[t].get(i);
                    int vy = ys[t].get(i);
                    for (int j = 0; j < xs[t - 1].size(); j++) {
                        int x = xs[t - 1].get(j);
                        int y = ys[t - 1].get(j);
                        td[vx][vy] = min(td[vx][vy], td[x][y] + abs(x - vx) + abs(y - vy));
                    }
                }
            } else {
                for (int[] i : d) {
                    Arrays.fill(i, inf);
                }
                Item[] a = new Item[xs[t - 1].size()];
                for (int i = 0; i < xs[t - 1].size(); i++) {
                    int x = xs[t - 1].get(i);
                    int y = ys[t - 1].get(i);
                    a[i] = new Item(td[x][y], x, y);
                    d[x][y] = td[x][y];
                }

                Arrays.sort(a);
                Queue<Item> q = new ArrayDeque<>();
                int ca = 0;

                while (!q.isEmpty() || ca < a.length) {
                    Item v;
                    if (q.isEmpty() || (ca < a.length && a[ca].d < q.peek().d)) {
                        v = a[ca++];
                    } else {
                        v = q.poll();
                    }
                    for (int i = 0; i < 4; i++) {
                        int x = v.x + dx[i];
                        int y = v.y + dy[i];
                        if (x < 0 || x >= n || y < 0 || y >= m) {
                            continue;
                        }
                        if (d[x][y] > v.d + 1) {
                            d[x][y] = v.d + 1;
                            q.add(new Item(d[x][y], x, y));
                        }
                    }
                }

                for (int i = 0; i < xs[t].size(); i++) {
                    int x = xs[t].get(i);
                    int y = ys[t].get(i);
                    td[x][y] = d[x][y];
                }
            }
        }

        println(td[xs[p].get(0)][ys[p].get(0)]);
    }

    BufferedReader in;
    StringTokenizer stok;

    Main() {
        super(System.out);
        in = new BufferedReader(new InputStreamReader(System.in));
    }

    Main(String fileIn, String fileOut) throws IOException {
        super(fileOut);
        in = new BufferedReader(new FileReader(fileIn));
    }

    public static void main(String[] args) throws IOException {
        Main main;
        if ("_std".equals(IO)) {
            main = new Main();
        } else if ("_iotxt".equals(IO)) {
            main = new Main("input.txt", "output.txt");
        } else {
            main = new Main(IO + ".in", IO + ".out");
        }
        main.solve();
        main.close();
    }

    String next() throws IOException {
        while (stok == null || !stok.hasMoreTokens()) {
            String s = in.readLine();
            if (s == null) {
                return null;
            }
            stok = new StringTokenizer(s);
        }
        return stok.nextToken();
    }

    int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    long nextLong() throws IOException {
        return Long.parseLong(next());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }

    int[] nextIntArray(int len) throws IOException {
        int[] a = new int[len];
        for (int i = 0; i < len; i++) {
            a[i] = nextInt();
        }
        return a;
    }

    int[] nextIntArraySorted(int len) throws IOException {
        int[] a = nextIntArray(len);
        shuffle(a);
        Arrays.sort(a);
        return a;
    }

    void shuffle(int[] a) {
        for (int i = 1; i < a.length; i++) {
            int x = rand.nextInt(i + 1);
            int _ = a[i];
            a[i] = a[x];
            a[x] = _;
        }
    }

    void shuffleAndSort(int[] a) {
        shuffle(a);
        Arrays.sort(a);
    }

    boolean nextPermutation(int[] p) {
        for (int a = p.length - 2; a >= 0; --a) {
            if (p[a] < p[a + 1])
                for (int b = p.length - 1; ; --b)
                    if (p[b] > p[a]) {
                        int t = p[a];
                        p[a] = p[b];
                        p[b] = t;
                        for (++a, b = p.length - 1; a < b; ++a, --b) {
                            t = p[a];
                            p[a] = p[b];
                            p[b] = t;
                        }
                        return true;
                    }
        }
        return false;
    }

    <T> List<T>[] createAdjacencyList(int n) {
        List<T>[] res = new List[n];
        for (int i = 0; i < n; i++) {
            res[i] = new ArrayList<>();
        }
        return res;
    }

    void println(Object... a) {
        for (int i = 0; i < a.length; i++) {
            if (i != 0) {
                print(" ");
            }
            print(a[i]);
        }
        println();
    }
}
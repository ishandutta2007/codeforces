import java.io.*;
import java.util.*;

public class D_new {

    BufferedReader br;
    PrintWriter out;
    StringTokenizer st;
    boolean eof;

    int len = 0;

    class State {
        int[] x;
        int[] y;

        @Override
        public int hashCode() {
            int res = 0;
            for (int i = 0; i < len; i++)
                res = (res * 239 + x[i]) * 31 + y[i];
            return res;
        }

        @Override
        public boolean equals(Object obj) {
            State other = (State) obj;
            return Arrays.equals(x, other.x) && Arrays.equals(y, other.y);
        }

        public State() {
            x = new int[len];
            y = new int[len];
        }

    }

    char[][] f;
    int n, m;
    static final int[] dx = { -1, 0, 1, 0 };
    static final int[] dy = { 0, 1, 0, -1 };
    
    State getState(State from, int dir) {
        int headX = from.x[0] + dx[dir];
        int headY = from.y[0] + dy[dir];
        if (headX < 0 || headX >= n || headY < 0 || headY >= m || f[headX][headY] == '#')
            return null;
        for (int i = 0; i < len - 1; i++) {
            if (from.x[i] == headX && from.y[i] == headY)
                return null;
        }
        State res = new State();
        System.arraycopy(from.x, 0, res.x, 1, len - 1);
        System.arraycopy(from.y, 0, res.y, 1, len - 1);
        res.x[0] = headX;
        res.y[0] = headY;
        return res;
    }

    void solve() throws IOException {
        n = nextInt();
        m = nextInt();
        f = new char[n][];
        for (int i = 0; i < n; i++)
            f[i] = nextToken().toCharArray();

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (f[i][j] >= '0' && f[i][j] <= '9') {
                    len = Math.max(len, f[i][j] - '0');
                }

        State init = new State();
        int tx = -1;
        int ty = -1;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (f[i][j] >= '0' && f[i][j] <= '9') {
                    int cur = f[i][j] - '1';
                    init.x[cur] = i;
                    init.y[cur] = j;
                } else if (f[i][j] == '@') {
                    tx = i;
                    ty = j;
                }

        HashMap<State, Integer> d = new HashMap<State, Integer>();
        d.put(init, 0);
        ArrayDeque<State> q = new ArrayDeque<State>();
        q.add(init);
        while (!q.isEmpty()) {
            State from = q.poll();
            int dist = d.get(from);
            for (int move = 0; move < 4; move++) {
                State to = getState(from, move);
                if (to == null)
                    continue;
                if (d.containsKey(to))
                    continue;
                if (to.x[0] == tx && to.y[0] == ty) {
                    out.println(dist + 1);
                    return;
                }
                d.put(to, dist + 1);
                q.add(to);
            }
        }
        
        out.println(-1);
    }

    void inp() throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
        solve();
        out.close();
    }

    public static void main(String[] args) throws IOException {
        new D_new().inp();
    }

    String nextToken() {
        while (st == null || !st.hasMoreTokens()) {
            try {
                st = new StringTokenizer(br.readLine());
            } catch (Exception e) {
                eof = true;
                return null;
            }
        }
        return st.nextToken();
    }

    String nextString() {
        try {
            return br.readLine();
        } catch (IOException e) {
            eof = true;
            return null;
        }
    }

    int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }
}
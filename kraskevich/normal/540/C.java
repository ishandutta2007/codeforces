import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.util.StringTokenizer;
import java.io.InputStream;
import java.io.InputStreamReader;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Igor Kraskevich
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		FastScanner in = new FastScanner(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {
    int n;
    int m;
    char[][] s;
    boolean[][] used;
    int r2;
    int c2;
    int[] dx = {-1, 1, 0, 0};
    int[] dy = {0, 0, -1, 1};

    boolean inside(int x, int y) {
        return x >= 0 && x < n && y >= 0 && y < m;
    }

    void dfs(int x, int y) {
        used[x][y] = true;
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (inside(nx, ny) && (s[nx][ny] == '.' || nx == r2 && ny == c2) && !used[nx][ny])
                dfs(nx, ny);
        }
    }

    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        n = in.nextInt();
        m = in.nextInt();
        s = new char[n][];
        for (int i = 0; i < n; i++)
            s[i] = in.next().toCharArray();
        int r1 = in.nextInt() - 1;
        int c1 = in.nextInt() - 1;
        r2 = in.nextInt() - 1;
        c2 = in.nextInt() - 1;
        used = new boolean[n][m];
        dfs(r1, c1);
        if (!used[r2][c2]) {
            out.println("NO");
            return;
        }
        int cnt = 0;
        for (int d = 0; d < 4; d++) {
            int x = r2 + dx[d];
            int y = c2 + dy[d];
            if (inside(x, y) && (s[x][y] == '.' || x == r1 && y == c1))
                cnt++;
        }
        if (r1 == r2 && c1 == c2)
            cnt++;
        if ((r1 != r2 || c1 != c2) && s[r2][c2] == 'X')
            cnt += 2;
        out.println(cnt >= 2 ? "YES" : "NO");
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
            String line = null;
            try {
                line = reader.readLine();
            } catch (IOException e) {
                }
            if (line == null)
                return null;
            tokenizer = new StringTokenizer(line);
        }
        return tokenizer.nextToken();
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }

}
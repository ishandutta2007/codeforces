import java.util.ArrayDeque;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.util.Collection;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Queue;
import java.io.IOException;
import java.util.StringTokenizer;

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
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {

    char[][] field;
    int n;
    int m;

    final int[] dx = {0, 0, -1, -1, -1, 1, 1, 1};
    final int[] dy = {1, -1, -1, 0, 1, -1, 0, 1};

    boolean inside(int x, int y) {
        return x >= 0 && x < n && y >= 0 && y < m;
    }

    boolean isDot(int x, int y) {
        return inside(x, y) && field[x][y] == '.';
    }

    boolean isBad(int x, int y) {
        if (!inside(x, y))
            return false;
        if (field[x][y] != '*')
            return false;
        if (isDot(x, y - 1) && isDot(x - 1, y - 1) && isDot(x - 1, y))
            return true;
        if (isDot(x, y - 1) && isDot(x + 1, y - 1) && isDot(x + 1, y))
            return true;
        if (isDot(x + 1, y) && isDot(x + 1, y + 1) && isDot(x, y + 1))
            return true;
        return isDot(x, y + 1) && isDot(x - 1, y + 1) && isDot(x - 1, y);
    }

    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        n = in.nextInt();
        m = in.nextInt();
        field = new char[n][];
        for (int i = 0; i < n; i++)
            field[i] = in.next().toCharArray();
        boolean[][] inQueue = new boolean[n][m];
        Queue<Integer> x = new ArrayDeque<>();
        Queue<Integer> y = new ArrayDeque<>();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) 
                if (isBad(i, j)) {
                    inQueue[i][j] = true;
                    x.add(i);
                    y.add(j);
                }
        while (!x.isEmpty()) {
            int vx = x.poll();
            int vy = y.poll();
            field[vx][vy] = '.';
            for (int dir = 0; dir < dx.length; dir++) {
                int nx = vx + dx[dir];
                int ny = vy + dy[dir];
                if (isBad(nx, ny) && !inQueue[nx][ny]) {
                    x.add(nx);
                    y.add(ny);
                    inQueue[nx][ny] = true;
                }
            }
        }
        for (int i = 0; i < n; i++)
            out.println(new String(field[i]));
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
                // ignore
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
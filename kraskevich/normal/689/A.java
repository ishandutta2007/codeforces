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
		TaskA solver = new TaskA();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskA {

    boolean isValid(int x, int y) {
        if (x >= 0 && x <= 2)
            return y >= 0 && y <= 2;
        return x == 3 && y == 1;
    }

    final int[] posX = {3, 0, 0, 0, 1, 1, 1, 2, 2, 2};
    final int[] posY = {1, 0, 1, 2, 0, 1, 2, 0, 1, 2};

    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        int n = in.nextInt();
        char[] s = in.next().toCharArray();
        int[] dx = new int[n - 1];
        int[] dy = new int[n - 1];
        for (int i = 0; i < n - 1; i++) {
            dx[i] = posX[s[i + 1] - '0'] - posX[s[i] - '0'];
            dy[i] = posY[s[i + 1] - '0'] - posY[s[i] - '0'];
        }
        int ways = 0;
        for (int i = 0; i <= 9; i++) {
            int x = posX[i];
            int y = posY[i];
            boolean ok = true;
            for (int j = 0; j < n - 1 && ok; j++) {
                int nx = x + dx[j];
                int ny = y + dy[j];
                if (isValid(nx, ny)) {
                    x = nx;
                    y = ny;
                } else {
                    ok = false;
                }
            }
            if (ok)
                ways++;
        }
        out.println(ways == 1 ? "YES" : "NO");
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
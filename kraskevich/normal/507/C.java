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
    final int LEFT = 0;
    final int RIGHT = 1;

    long getSize(int height) {
        return (1L << (height + 1)) - 1;
    }

    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        int h = in.nextInt();
        long pos = in.nextLong();
        pos--;
        int currentDir = LEFT;
        long res = 0;
        long left = 0;
        long right = (1L << h) - 1;
        for (int i = h; i > 0; i--) {
            res++;
            long mid = (left + right) / 2;
            if (pos <= mid) {
                if (currentDir != LEFT)
                    res += getSize(i - 1);
                currentDir = RIGHT;
                right = mid;
            } else {
                if (currentDir != RIGHT)
                    res += getSize(i - 1);
                currentDir = LEFT;
                left = mid + 1;
            }
        }
        out.println(res);
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

    public long nextLong() {
        return Long.parseLong(next());
    }

}
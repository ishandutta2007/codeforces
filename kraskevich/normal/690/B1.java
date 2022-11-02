import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
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
		TaskB1 solver = new TaskB1();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskB1 {

    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        n = in.nextInt();
        int[][] a = new int[n][n];
        for (int i = 0; i < n; i++) {
            String s = in.next();
            for (int j = 0; j < n; j++)
                a[i][j] = s.charAt(j) - '0';
        }
        int low = n;
        int high = 0;
        int left = n;
        int right = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                if (a[i][j] != 0) {
                    low = Math.min(low, i);
                    high = Math.max(high, i);
                    left = Math.min(left, j);
                    right = Math.max(right, j);
                }
            }
        for (int mask = 0; mask < 16; mask++) {
            int li = low;
            int hi = high;
            int lj = left;
            int hj = right;
            if ((mask & 1) != 0)
                li++;
            if ((mask & 2) != 0)
                hi--;
            if ((mask & 4) != 0)
                lj++;
            if ((mask & 8) != 0)
                hj--;
            int[][] cur = calc(li, lj, hi, hj);
            if (equal(cur, a)) {
                out.println("Yes");
                return;
            }
        }
        out.println("No");
    }

    int n;

    boolean equal(int[][] a, int[][] b) {
        if (a == null || b == null)
            return false;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (a[i][j] != b[i][j])
                    return false;
        return true;
    }

    int[][] calc(int lowI, int lowJ, int highI, int highJ) {
        if (lowI > highI || lowJ > highJ)
            return null;
        int[][] res = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int typeI = 0;
                int typeJ = 0;
                if (lowI <= i && i <= highI)
                    typeI = 1;
                else if (Math.abs(i - lowI) == 1 || Math.abs(i - highI) == 1)
                    typeI = 2;
                if (lowJ <= j && j <= highJ)
                    typeJ = 1;
                else if (Math.abs(j - lowJ) == 1 || Math.abs(j - highJ) == 1)
                    typeJ = 2;
                if (typeI == 0 || typeJ == 0)
                    continue;
                if (typeI == 1 && typeJ == 1) {
                    res[i][j] = 4;
                    continue;
                }
                if (typeI == 2 & typeJ == 2) {
                    res[i][j] = 1;
                    continue;
                }
                res[i][j] = 2;
            }
        }
        return res;
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
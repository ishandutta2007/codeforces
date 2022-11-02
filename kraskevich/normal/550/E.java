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
		TaskE solver = new TaskE();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskE {
    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        int n = in.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++)
            a[i] = in.nextInt();
        if (n == 1) {
            if (a[0] == 0) {
                out.println("YES");
                out.println(0);
            } else {
                out.println("NO");
            }
            return;
        }
        if (n == 2) {
            if (a[0] == 1 && a[1] == 0) {
                out.println("YES");
                out.println("1->0");
            } else {
                out.println("NO");
            }
            return;
        }
        if (a[n - 1] == 1) {
            out.println("NO");
            return;
        }
        int firstZero = n - 1;
        for (int i = 0; i < n; i++)
            if (a[i] == 0)
                firstZero = Math.min(firstZero, i);
        if (firstZero == n - 1) {
            out.println("YES");
            for (int i = 0; i < n - 1; i++)
                out.print(a[i] + "->");
            out.println(0);
        } else if (firstZero != n - 2) {
            out.println("YES");
            for (int i = 0; i < n - 1; i++) {
                if (i == 0 || i == firstZero || i == firstZero + 1)
                    out.print("(");
                out.print(a[i]);
                if (i == n - 2 || i == firstZero - 1)
                    out.print(")");
                if (i == n - 2)
                    out.print(")");
                out.print("->");
            }
            out.println(0);
        } else {
            out.println("NO");
        }

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
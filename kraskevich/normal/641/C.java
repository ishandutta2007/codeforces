import java.util.Arrays;
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
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {

    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        int n = in.nextInt();
        int q = in.nextInt();
        int swaps = 0;
        long dEven = 0;
        long dOdd = 0;
        for (int i = 0; i < q; i++) {
            int t = in.nextInt();
            if (t == 1) {
                long x = -in.nextInt();
                x = (x + n) % n;
                if (x % 2 == 0) {
                    dEven += x / 2;
                    dOdd += x / 2;
                } else {
                    dEven += x / 2 + 1;
                    dOdd += x / 2;
                    swaps++;
                    long temp = dOdd;
                    dOdd = dEven;
                    dEven = temp;
                }
            } else {
                swaps++;
                long temp = dOdd;
                dOdd = dEven;
                dEven = temp;
            }
        }
        int[] res = new int[n];
        for (int i = 0; i < n / 2; i++) {
            res[2 * i] = (int) ((dEven + i) * 2 % n);
            res[2 * i + 1] = (int) (((dOdd + i) * 2 + 1) % n);
        }
        if (swaps % 2 == 1) {
            for (int i = 0; i < n; i++)
                if (i % 2 == 0)
                    res[i]++;
                else
                    res[i]--;
        }
        for (int i = 0; i < n; i++)
            out.print(res[i] + 1 + " ");
        out.println();
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
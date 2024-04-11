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

    final int N = 500_1000 + 10;
    long[] count = new long[N];
    int[] func = new int[N];

    long add(int val) {
        long res = 0;
        for (int d = 1; d * d <= val; d++) {
            if (val % d == 0) {
                res += func[d] * count[d];
                count[d]++;
                if (val / d != d) {
                    res += func[val / d] * count[val / d];
                    count[val / d]++;
                }
            }
        }
        return res;
    }

    long remove(int val) {
        long res = 0;
        for (int d = 1; d * d <= val; d++) {
            if (val % d == 0) {
                count[d]--;
                res += func[d] * count[d];
                if (val / d != d) {
                    count[val / d]--;
                    res += func[val / d] * count[val / d];
                }
            }
        }
        return res;
    }

    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        int n = in.nextInt();
        int q = in.nextInt();
        long cur = 0;
        int[] a = new int[n];
        boolean[] was = new boolean[N];
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt();
            was[a[i]] = true;
        }
        for (int i = 0; i < N; i++)
            func[i] = 1;
        boolean[] isPrime = new boolean[N];
        Arrays.fill(isPrime, true);
        for (int i = 2; i < N; i++)
            if (isPrime[i]) {
                func[i] = -1;
                for (int j = 2 * i; j < N; j += i) {
                    long k = i * i;
                    if (j % k == 0)
                        func[j] = 0;
                    else
                        func[j] *= -1;
                    isPrime[j] = false;
                }
            }
        boolean[] have = new boolean[n];
        for (int i = 0; i < q; i++) {
            int pos = in.nextInt() - 1;
            if (!have[pos]) {
                have[pos] = true;
                cur += add(a[pos]);
            }
            else {
                have[pos] = false;
                cur -= remove(a[pos]);
            }
            out.println(cur);
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
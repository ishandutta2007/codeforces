import java.io.InputStreamReader;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Constantine Sokol
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {
    final int MOD = 1000000007;
    int[] factorials;
    int[] inversedFactorials;
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int k = in.nextInt();
        String number = in.next();
        int[] a = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            a[i] = a[i - 1] + number.charAt(i - 1) - '0';
        }
        factorials = new int[n + 1];
        inversedFactorials = new int[n + 1];
        factorials[0] = inversedFactorials[0] = 1;
        for (int i = 1; i <= n; i++) {
            factorials[i] = multiply(factorials[i - 1], i);
            inversedFactorials[i] = multiply(inversedFactorials[i - 1], inv(i));
        }
        long answer = 0;
        for (int d = 0; d < n; d++) {
            int digit = number.charAt(n - d - 1) - '0';
            answer += multiply(digit, power(10, d), cnk(n - 1 - d, k));
            answer += multiply(a[n - 1 - d], power(10, d), cnk(n - 2 - d, k - 1));
            answer %= MOD;
        }
        out.println(answer);
    }

    int multiply(int... args) {
        long result = 1L;
        for (int arg : args) {
            result = (result * (arg % MOD)) % MOD;
        }
        return (int)result;
    }

    int cnk(int n, int k) {
        if (k < 0 || n < 0 || n < k) {
            return 0;
        }
        int value = multiply(factorials[n], inversedFactorials[k], inversedFactorials[n - k]);
        return value;
    }

    int inv(int x) {
        return power(x, MOD - 2);
    }

    int power(int a, int b) {
        int result = 1;
        while (b != 0) {
            if ((b & 1) > 0) {
                result = multiply(result, a);
            }
            a = multiply(a, a);
            b >>= 1;
        }
        return result;
    }
}

class InputReader {
    private final BufferedReader reader;
    private StringTokenizer tokenizer;

    public InputReader(InputStream in) {
        reader = new BufferedReader(new InputStreamReader(in));
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }

    public String next() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(readLine());
        }
        return tokenizer.nextToken();
    }

    public String readLine() {
        String line;
        try {
            line = reader.readLine();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        return line;
    }
}
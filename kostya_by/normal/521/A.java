import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
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
		TaskA solver = new TaskA();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskA {
    final int MOD = 1000000007;
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        String s = in.next();
        int[] a = new int[4];
        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            if (ch == 'A') {
                a[0] += 1;
            }
            if (ch == 'C') {
                a[1] += 1;
            }
            if (ch == 'G') {
                a[2] += 1;
            }
            if (ch == 'T') {
                a[3] += 1;
            }
        }
        Arrays.sort(a);
        int count = 1;
        if (a[0] == a[3]) {
            count += 1;
        }
        if (a[1] == a[3]) {
            count += 1;
        }
        if (a[2] == a[3]) {
            count += 1;
        }
        int answer = 1;
        for (int i = 0; i < s.length(); i++) {
            answer = (int)((answer * 1L * count) % MOD);
        }
        out.println(answer);
    }
}

class InputReader {
    private final BufferedReader reader;
    private StringTokenizer tokenizer;

    InputReader(InputStream in) {
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
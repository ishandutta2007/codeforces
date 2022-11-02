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
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		FastScanner in = new FastScanner(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskB {
        long a, c;
        int b, w, x;

        public void solve(int testNumber, FastScanner in, PrintWriter out) {
                a = in.nextLong();
                b = in.nextInt();
                w = in.nextInt();
                x = in.nextInt();
                c = in.nextLong();
                long[] delta = new long[w];
                Arrays.fill(delta, -1);
                int cur = b;
                while (true) {
                        if (delta[cur] != -1)
                                break;
                        delta[cur] = cur / x;
                        cur = get(cur);
                }
                boolean[] was = new boolean[w];
                int v = 0;
                cur = b;
                long all = 0;
                while (true) {
                        if (was[cur])  {
                                v = cur;
                                break;
                        }
                        all += delta[cur];
                        was[cur] = true;
                        cur = get(cur);
                }
                long cyc = 0;
                int len = 0;
                Arrays.fill(was, false);
                cur = v;
                while (true) {
                        if (was[cur])  {
                                break;
                        }
                        cyc += delta[cur];
                        len++;
                        was[cur] = true;
                        cur = get(cur);
                }
                all -= cyc;
                long toGo = c - a;
                long res = 0;
                if (all >= toGo) {
                        cur = b;
                        while (toGo > 0) {
                                if (toGo > delta[cur]) {
                                        toGo -= delta[cur];
                                        res += delta[cur] + 1;
                                } else {
                                        res += toGo;
                                        toGo = 0;
                                }
                                cur = get(cur);
                        }
                        out.println(res + toGo);
                        return;
                }
                cur = b;
                while (cur != v) {
                        toGo -= delta[cur];
                        res += delta[cur] + 1;
                        cur = get(cur);
                }
                long steps = Math.max(0L, toGo / cyc - 1);
                res += (cyc + len) * steps;
                toGo -= cyc * steps;
                while (toGo > 0) {
                        if (toGo > delta[cur]) {
                                toGo -= delta[cur];
                                res += delta[cur] + 1;
                        } else {
                                res += toGo;
                                toGo = 0;
                        }
                        cur = get(cur);
                }
                res += toGo;
                out.println(res + toGo);
        }

        int get(int y) {
                y %= x;
                y = w - (x - y);
                return y;
        }
}

class FastScanner {
        BufferedReader reader;
        StringTokenizer tokenizer;

        public FastScanner(InputStream inputStream)  {
                reader = new BufferedReader(new InputStreamReader(inputStream));
        }

        public String nextToken() {
                while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                        String line;
                        try {
                                line = reader.readLine();
                        } catch (IOException e) {
                                return null;
                        }
                        tokenizer = new StringTokenizer(line);
                }
                return tokenizer.nextToken();
        }

        public int nextInt() {
                return Integer.parseInt(nextToken());
        }

        public long nextLong() {
                return Long.parseLong(nextToken());
        }

        }
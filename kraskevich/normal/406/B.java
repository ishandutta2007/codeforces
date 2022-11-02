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
        final int N = 1_000_000;
        int[] ans = new int[N];
        int size = 0;

        int get(int i) {
                return N - i + 1;
        }

        public void solve(int testNumber, FastScanner in, PrintWriter out) {
                int n = in.nextInt();
                int[] a = ArrayUtils.readIntArray(in, n);
                boolean[] was = new boolean[N + 1];
                for (int val : a)
                        was[val] = true;
                int l = 1;
                for (int i = 1; i <= N; i++) {
                        if (!was[i])
                                continue;
                        int j = get(i);
                        if (was[j])
                                continue;
                        ans[size++] = j;
                }
                for (int i = 1; i <= N; i++) {
                        if (!was[i] || !was[get(i)] || i > get(i))
                                continue;
                        while (was[l] || was[get(l)])
                                l++;
                        ans[size++] = l;
                        ans[size++] = get(l);
                        l++;
                }
                out.println(size);
                for (int i = 0; i < size; i++)
                        out.print(ans[i] + " ");
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

        }

class ArrayUtils {

        public static int[] readIntArray(FastScanner in, int count) {
                int[] array = new int[count];
                for (int i = 0; i < count; i++)
                        array[i] = in.nextInt();
                return array;
        }


        }
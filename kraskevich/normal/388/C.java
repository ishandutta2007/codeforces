import java.util.List;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.ArrayList;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.util.Collections;
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
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {

        public void solve(int testNumber, FastScanner in, PrintWriter out) {
                int n = in.nextInt();
                long a = 0;
                long b = 0;
                ArrayList<Integer> mid = new ArrayList<>();
                for (int i = 0; i < n; i++) {
                        int k = in.nextInt();
                        int[] c = ArrayUtils.readIntArray(in, k);
                        for (int j = 0; j < c.length / 2; j++)
                                a += c[j];
                        for (int j = c.length / 2 + 1; j < c.length; j++)
                                b += c[j];
                        if (c.length % 2 == 0)
                                b += c[c.length / 2];
                        else
                                mid.add(c[c.length / 2]);
                }
                Collections.sort(mid);
                Collections.reverse(mid);
                for (int i = 0; i < mid.size(); i++)
                        if (i % 2 == 0)
                                a += mid.get(i);
                        else
                                b += mid.get(i);
                out.println(a + " " + b);
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
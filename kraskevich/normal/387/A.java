import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
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
		TaskA solver = new TaskA();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskA {
        final int TOTAL = 60 * 24;

        public void solve(int testNumber, FastScanner in, PrintWriter out) {
                int cur = readTime(in);
                int was = readTime(in);
                cur -= was;
                cur += TOTAL;
                cur %= TOTAL;
                out.format("%02d:%02d", cur / 60, cur % 60);
        }

        int readTime(FastScanner in) {
                String s = in.nextToken();
                String[] tokens = s.split(":");
                String hh = tokens[0];
                String mm = tokens[1];
                int h, m;
                if (hh.charAt(0) == '0')
                        h = hh.charAt(1) - '0';
                else
                        h = Integer.parseInt(hh);
                if (mm.charAt(0) == '0')
                        m = mm.charAt(1) - '0';
                else
                        m = Integer.parseInt(mm);
                return h * 60 + m;
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

        }
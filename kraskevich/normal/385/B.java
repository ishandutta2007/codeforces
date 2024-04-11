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
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskB {
        public void solve(int testNumber, FastScanner in, PrintWriter out) {
                String s = in.nextToken();
                int n = s.length();
                int res = 0;
                for (int i = 0; i < n; i++)   {
                        boolean was = false;
                        for (int j = i + 3; j < n; j++) {
                               if (s.charAt(j - 3) == 'b' && s.charAt(j - 2) == 'e' && 
                                       s.charAt(j - 1) == 'a' && s.charAt(j) == 'r')
                                       was = true;
                               if (was)
                                       res++;
                        }
                }
                out.println(res);
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
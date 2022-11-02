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
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {
        public void solve(int testNumber, FastScanner in, PrintWriter out) {
                String s = in.nextToken();
                int n = s.length();
                int res = 0;
                int i = 0;
                while (i < n) {
                        int start = i;
                        i++;
                        while (i < n && s.charAt(i) == '0')
                                i++;
                        int prefLen = start;
                        int curLen = i - start;
                        if (prefLen > curLen ||
                                prefLen == curLen && s.substring(0, start).compareTo(s.substring(start, i)) >= 0)
                                        res++;
                                else
                                        res = 1;
                        //out.print();
              
                }
                out.print(res);
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
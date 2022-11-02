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
        public void solve(int testNumber, FastScanner in, PrintWriter out) {
                String s = in.nextToken();
                String left = "";
                if (s.split("\\Q|\\E").length > 0)
                        left = s.split("\\Q|\\E")[0];
                String right = "";
                if (s.split("\\Q|\\E").length > 1)
                        right = s.split("\\Q|\\E")[1];
                String have = in.nextToken();
                for (int i = 0; i < have.length(); i++)
                        if (left.length() < right.length())
                                left += have.charAt(i);
                        else
                                right += have.charAt(i);
                if (left.length() == right.length())
                        out.println(left + "|" + right);
                else
                        out.println("Impossible");
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
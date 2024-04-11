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
                String a = in.nextToken();
                String b = in.nextToken();
                int d = 0;
                for (int i = 0; i < a.length(); i += 2) {
                        char c = a.charAt(i);
                        int f1;
                        if (c == '8')
                                f1 = 1;
                        else if (c == '(')
                                f1 = 0;
                        else
                                f1 = 2;
                        c = b.charAt(i);
                        int f2;
                        if (c == '8')
                                f2 = 1;
                        else if (c == '(')
                                f2 = 0;
                        else
                                f2 = 2;
                        if ((f2 + 1) % 3 == f1)
                                d--;
                        else  if ((f1 + 1) % 3 == f2)
                                d++;
                }
                if (d == 0)
                        out.println("TIE");
                else if (d > 0)
                        out.println("TEAM 1 WINS");
                else
                        out.println("TEAM 2 WINS");
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
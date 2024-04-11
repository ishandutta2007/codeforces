import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.util.StringTokenizer;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Igor Kraskevich
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

    String noLeadingZeros(String s) {
        int p = 0;
        while (p < s.length() && s.charAt(p) == '0')
            p++;
        return s.substring(p);
    }

    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        String s = in.next();
        if (!s.contains("."))
            s = s + ".";
        s = noLeadingZeros(s);
        if (s.startsWith(".")) {
            String frac = s.substring(1);
            String tail = noLeadingZeros(frac);
            if (tail.length() == 0) {
                out.print(0);
            } else {
                int pw = frac.length() - tail.length() + 1;
                out.print(tail.charAt(0));
                tail = tail.substring(1);
                int p = tail.length() - 1;
                while (p >= 0 && tail.charAt(p) == '0')
                    p--;
                tail = tail.substring(0, p + 1);
                if (tail.length() != 0) {
                    out.print("." + tail);
                }
                out.print("E" + (-pw));
            }
        } else {
            String[] parts = s.split("\\Q.\\E");
            String whole = noLeadingZeros(parts[0]);
            assert whole.length() != 0;
            String frac = (parts.length >= 2 ? parts[1] : "");
            out.print(whole.charAt(0));
            int pw = whole.length() - 1;
            String tail = whole.substring(1) + frac;
            int p = tail.length() - 1;
            while (p >= 0 && tail.charAt(p) == '0')
                p--;
            tail = tail.substring(0, p + 1);
            if (tail.length() > 0)
                out.print("." + tail);
            if (pw != 0)
                out.print("E" + pw);
        }
        out.println();
    }
}

class FastScanner {
    private StringTokenizer tokenizer;
    private BufferedReader reader;

    public FastScanner(InputStream inputStream) {
        reader = new BufferedReader(new InputStreamReader(inputStream));
    }

    public String next() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            String line = null;
            try {
                line = reader.readLine();
            } catch (IOException e) {
                }
            if (line == null)
                return null;
            tokenizer = new StringTokenizer(line);
        }
        return tokenizer.nextToken();
    }

}
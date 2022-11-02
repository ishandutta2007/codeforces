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
		TaskA solver = new TaskA();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskA {
    int getScore(char c) {
        c = Character.toLowerCase(c);
        switch (c) {
            case 'q': return 9;
            case 'r': return 5;
            case 'b': return 3;
            case 'n': return 3;
            case 'p': return 1;
        }
        return 0;
    }
    
    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        int n = 8;
        int cnt1 = 0;
        int cnt2 = 0;
        for (int i = 0; i < n; i++) {
            String s = in.next();
            for (int j = 0; j < n; j++)
                if (s.charAt(j) != '.') {
                    if (Character.isUpperCase(s.charAt(j)))
                        cnt1 += getScore(s.charAt(j));
                    else
                        cnt2 += getScore(s.charAt(j));
                }
        }
        String res = "Black";
        if (cnt1 > cnt2)
            res = "White";
        else if (cnt1 == cnt2)
            res = "Draw";
        out.println(res);
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
                // ignore
            }
            if (line == null)
                return null;
            tokenizer = new StringTokenizer(line);
        }
        return tokenizer.nextToken();
    }

}
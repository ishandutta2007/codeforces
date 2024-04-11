import java.util.ArrayList;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.List;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Collections;
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
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskB {

    final String I = "Impossible";

    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        long a00 = in.nextInt();
        long a01 = in.nextInt();
        long a10 = in.nextInt();
        long a11 = in.nextInt();
        if (a00 + a01 + a10 + a11 == 0) {
            out.println('0');
            return;
        }
        long cnt0 = 0;
        while (cnt0 * (cnt0 - 1) / 2 < a00)
            cnt0++;
        if (cnt0 * (cnt0 - 1) / 2 != a00) {
            out.println(I);
            return;
        }
        long cnt1 = 0;
        while (cnt1 * (cnt1 - 1) / 2 < a11)
            cnt1++;
        if (cnt1 * (cnt1 - 1) / 2 != a11) {
            out.println(I);
            return;
        }
        if (cnt1 == 0 && a01 + a10 != 0)
            cnt1++;
        if (cnt0 == 0 && a01 + a10 != 0)
            cnt0++;
        if (a00 == 0 && a10 == 0 && a01 == 0) {
            for (int i = 0; i < cnt1; i++) {
                out.print('1');
            }
            return;
        }
        if (a11 == 0 && a10 == 0 && a01 == 0) {
            for (int i = 0; i < cnt0; i++) {
                out.print('0');
            }
            return;
        }
        long n = cnt1 + cnt0;
        long total = n * (n - 1) / 2;
        if (a00 + a11 + a10 + a01 != total) {
            out.println(I);
            return;
        }
        ArrayList<Long> onesToRight = new ArrayList<>();
        for (int i = 0; i < cnt0; i++) {
            onesToRight.add(Math.min(a01, cnt1));
            a01 -= onesToRight.get(i);
        }
        if (a01 != 0) {
            out.println(I);
            return;
        }
        ArrayList<Long> res = new ArrayList<>();
        long curOnes = 0;
        for (long i = cnt0 - 1; i >= 0; i--) {
            while (curOnes < onesToRight.get((int)i)) {
                res.add(1L);
                curOnes++;
                cnt1--;
            }
            res.add(0L);
        }
        while (cnt1 > 0) {
            cnt1--;
            res.add(1L);
        }
        Collections.reverse(res);
        for (long x : res)
            out.print(x);
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

    public int nextInt() {
        return Integer.parseInt(next());
    }

}
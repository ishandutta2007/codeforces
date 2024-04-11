import java.util.ArrayList;
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
    final long INF = (long) 1e18;

    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        long m = in.nextLong();
        long h1 = in.nextLong();
        long a1 = in.nextLong();
        long x1 = in.nextLong();
        long y1 = in.nextLong();
        long h2 = in.nextLong();
        long a2 = in.nextLong();
        long x2 = in.nextLong();
        long y2 = in.nextLong();
        boolean[] was1 = new boolean[(int) m];
        boolean[] was2 = new boolean[(int) m];
        long cur = h1;
        ArrayList<Long> list1 = new ArrayList<>();
        for (;;) {
            was1[(int) cur] = true;
            list1.add(cur);
            cur = (x1 * cur + y1) % m;
            if (was1[(int) cur])
                break;
        }
        int st1 = 0;
        while (list1.get(st1) != cur)
            st1++;
        cur = h2;
        ArrayList<Long> list2 = new ArrayList<>();
        for (;;) {
            was2[(int) cur] = true;
            list2.add(cur);
            cur = (x2 * cur + y2) % m;
            if (was2[(int) cur])
                break;
        }
        int st2 = 0;
        while (list2.get(st2) != cur)
            st2++;
        if (!was1[(int) a1] || !was2[(int) a2]) {
            out.println(-1);
            return;
        }
        int index1 = list1.indexOf(a1);
        int index2 = list2.indexOf(a2);
        if (index1 == index2) {
            out.println(index1);
            return;
        }
        int len1 = list1.size() - st1;
        int len2 = list2.size() - st2;
        boolean on1 = index1 >= st1;
        boolean on2 = index2 >= st2;
        long res = INF;
        int limit = 2 * 1000 * 1000;
        if (on1) {
            for (long i = 0; i <= limit; i++)
                if (index1 + len1 * i == index2)
                    res = Math.min(res, index2);
        }
        if (on2) {
            for (long i = 0; i <= limit; i++)
                if (index2 + len2 * i == index1)
                    res = Math.min(res, index1);
        }
        if (on1 && on2) {
            for (long i = 0; i <= limit; i++) {
                long f1 = index1 + len1 * i;
                if (f1 >= index2 && (f1 - index2) % len2 == 0)
                    res = Math.min(res, f1);
            }
            for (long i = 0; i <= limit; i++) {
                long f2 = index2 + len2 * i;
                if (f2 >= index1 && (f2 - index1) % len1 == 0)
                    res = Math.min(res, f2);
            }
        }
        if (res == INF)
            res = -1;
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
                }
            if (line == null)
                return null;
            tokenizer = new StringTokenizer(line);
        }
        return tokenizer.nextToken();
    }

    public long nextLong() {
        return Long.parseLong(next());
    }

}
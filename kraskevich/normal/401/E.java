import java.util.List;
import java.io.IOException;
import java.io.InputStreamReader;
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
		TaskE solver = new TaskE();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskE {
        final int MAX_N = 101_000;
        @SuppressWarnings("uncheked")
        ArrayList<Integer>[] divs = new ArrayList[MAX_N];
        long modulo;

        public void solve(int testNumber, FastScanner in, PrintWriter out) {
                init();
                int n = in.nextInt();
                int m = in.nextInt();
                long L = in.nextInt();
                long R = in.nextInt();
                modulo = in.nextInt();
                long res = 0;
                for (long dx = 1; dx <= n; dx++) {
                        long low = L * L - dx * dx;
                        long high = R * R - dx * dx;
                        if (low < 0)
                                low = 0;
                        if (high < 0)
                                continue;
                        long left = (int)Math.sqrt(low);
                        long right = (int)Math.sqrt(high);
                        while (left > 0 && left * left + dx * dx >= L * L)
                                left--;
                        while (left * left + dx * dx < L * L)
                                left++;
                        left--;
                        while (right > 0 && right * right + dx * dx >= R * R)
                                right--;
                        while (right * right + dx * dx <= R * R)
                                right++;
                        right--;
                        if (left < 0)
                                left = 0;
                        if (right > m)
                                right = m;
                        if (left >= right)
                                continue;
                        long cntR = right - getCount((int)dx, (int)right);
                        long cntL = left - getCount((int)dx, (int)left);
                        long cnt = cntR - cntL;
                        cnt %= modulo;
                        cnt += modulo;
                        cnt %= modulo;
                        long sumR = right * (right + 1) / 2 - getSum((int)dx, (int)right);
                        long sumL = left * (left + 1) / 2 - getSum((int)dx, (int)left);
                        long sum = sumR - sumL;
                        sum = cnt * (m + 1) % modulo - sum;
                        sum %= modulo;
                        sum += modulo;
                        sum %= modulo;
                        res += (2 * sum * (n - dx + 1)) % modulo;
                        res %= modulo;
                }
                if (L <= 1)
                        res += (n + 1) * 1L * m + n * 1L * (m + 1);
                out.println(res % modulo);
        }

        void init() {
                for (int i = 1; i < MAX_N; i++) {
                        divs[i] = new ArrayList<>();
                        divs[i].add(1);
                }
                for (int i = 2; i < MAX_N; i++)
                        for (int j = i; j < MAX_N; j += i)
                                divs[j].add(i);
                for (int i = 1; i < MAX_N; i++)
                        Collections.reverse(divs[i]);
        }

        long getCount(int n, int R) {
                if (n == 1)
                        return 0L;
                if (R <= 1)
                        return 0L;
                int cnt = divs[n].size();
                int[] with = new int[cnt];
                long res = 0;
                for (int i = 0; i < cnt - 1; i++) {
                        int cur = divs[n].get(i);
                        with[i] += R / cur;
                        res += with[i];
                        for (int j = cnt - 1; j >= 0 && divs[n].get(j) < cur; j--)
                                if (cur % divs[n].get(j) == 0)
                                        with[j] -= with[i];
                }
                return res;
        }

        long getSum(int n, int R) {
                if (R <= 1)
                        return 0L;
                if (n == 1)
                        return 0L;
                int cnt = divs[n].size();
                long[] with = new long[cnt];
                long res = 0;
                for (int i = 0; i < cnt - 1; i++) {
                        int cur = divs[n].get(i);
                        with[i] += R / cur * 1L * (R / cur + 1) / 2 * cur;
                        res += with[i];
                        for (int j = cnt - 1; j >= 0 && divs[n].get(j) < cur; j--)
                                if (cur % divs[n].get(j) == 0)
                                        with[j] -= with[i];
                }
                return res;
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
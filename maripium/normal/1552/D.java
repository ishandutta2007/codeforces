import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        solve();
        pw.close();
    }

    static void solve() {
        int T = readInt();
        while (T-- > 0) {
            int N = readInt();
            int[] A = new int[N];
            for (int i = 0; i < N; ++i) A[i] = readInt();

            int[] S = new int[1 << N];
            for (int i = 0; i < (1 << N); ++i) {
                for (int j = 0; j < N; ++j) if ((i >> j & 1) > 0) S[i] += A[j];
            }
            Arrays.sort(S);
            
            boolean ok = false;
            for (int i = 1; i < (1 << N); ++i) if (S[i] == S[i - 1]) ok = true;
            pw.println(ok ? "YES" : "NO");
        }
    }

	static BufferedReader br;
	static PrintWriter pw;
	static StringTokenizer st;

    static String readString() {
        while (st == null || !st.hasMoreTokens()) {
            try {
            	st = new StringTokenizer(br.readLine());
            } catch (IOException e) {
            	throw new RuntimeException(e);
            }
        }
        return st.nextToken();
    }

    static int readInt() {
        return Integer.parseInt(readString());
    }

    static long readLong() {
        return Long.parseLong(readString());
    }
}
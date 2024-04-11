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
            char[] A = readString().toCharArray();
            char[] B = Arrays.copyOfRange(A, 0, N);
            Arrays.sort(B);
            int cnt = 0;
            for (int i = 0; i < N; ++i) if (A[i] != B[i]) cnt++;
            pw.println(cnt);
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
import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        solve();
        pw.close();
    }

    static int[][] A;

    static boolean win(int x, int y) {
        int cnt = 0;
        for (int i = 0; i < 5; ++i) if (A[x][i] < A[y][i]) cnt++;
        return (cnt >= 3);
    }

    static void solve() {
        int T = readInt();
        while (T-- > 0) {
            int N = readInt();
            A = new int[N][5];
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < 5; ++j) {
                    A[i][j] = readInt();
                }
            }
            int cnd = 0;
            for (int i = 1; i < N; ++i) if (win(i, cnd)) cnd = i;
            for (int i = 0; i < cnd; ++i) if (win(i, cnd)) {
                cnd = -2;
                break;
            }
            pw.println(cnd + 1);
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
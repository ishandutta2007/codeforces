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
            int K = readInt();
            
            boolean[] used = new boolean[2 * N];
            int[] X = new int[N];
            int[] Y = new int[N];
            for (int i = 0; i < K; ++i) {
                int x = readInt() - 1;
                int y = readInt() - 1;
                X[i] = Math.min(x, y);
                Y[i] = Math.max(x, y);
                used[X[i]] = used[Y[i]] = true;
            }

            int[] unused = new int[2 * (N - K)];
            int sz = 0;
            for (int i = 0; i < 2 * N; ++i) if (!used[i]) unused[sz++] = i;

            for (int i = 0; i < N - K; ++i) {
                X[i + K] = unused[i];
                Y[i + K] = unused[i + (N - K)];
            }

            int ans = 0;
            for (int i = 0; i < N; ++i) {
                for (int j = i + 1; j < N; ++j) {
                    boolean vx = (X[i] < X[j]) && (X[j] < Y[i]);
                    boolean vy = (X[i] < Y[j]) && (Y[j] < Y[i]);
                    if (vx != vy) ans ++;
                }
            }

            pw.println(ans);
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
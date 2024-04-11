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
        int N = readInt(), K = readInt();
        int[] cnts = new int[N];
        int[][] locs = new int[N][K];

        for (int i = 0; i < N * K; ++i) {
            int c = readInt() - 1;
            locs[c][cnts[c]++] = i;
        }

        int[] A = new int[N];
        int[] B = new int[N];
        Arrays.fill(A, 0, N, -1);
        for (int it = 0; it < N; ++it) {
            int j = it % (K - 1);
            int best = N * K;
            int col = -1;
            for (int i = 0; i < N; ++i) if (A[i] == -1) {
                if (locs[i][j + 1] < best) {
                    best = locs[i][j + 1];
                    col = i;
                }
            }
            A[col] = locs[col][j];
            B[col] = locs[col][j + 1];
        }

        for (int i = 0; i < N; ++i) {
            pw.println((A[i] + 1) + " " + (B[i] + 1));
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
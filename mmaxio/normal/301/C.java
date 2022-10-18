import java.io.*;
import java.util.*;

public class C {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		for (int i = 0; i <= 8; i++) {
			out.println(i + "??<>" + (i + 1));
		}
		out.println("9??>>??0");
		out.println("??<>1");
		for (int i = 0; i <= 9; i++) {
			out.println("?" + i + ">>" + i + "?");
		}
		for (int i = 0; i <= 9; i++) {
			out.println(i + "?>>" + i + "??");
		}
		for (int i = 0; i <= 9; i++) {
			out.println(i + ">>" + i + "?");
		}
	}

	C() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new C();
	}

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (Exception e) {
				eof = true;
				return null;
			}
		}
		return st.nextToken();
	}

	String nextString() {
		try {
			return br.readLine();
		} catch (IOException e) {
			eof = true;
			return null;
		}
	}

	int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}
}
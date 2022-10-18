import java.io.*;
import java.util.*;

public class C {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		int n = nextInt();
		ArrayList<String> path = new ArrayList<String>();
		for (int i = 0; i < n; i++) {
			String comm = nextToken();
			if (comm.equals("pwd")) {
				out.print("/");
				for (String dir : path)
					out.print(dir + "/");
				out.println();
			} else if (comm.equals("cd")) {
				String change = nextToken();
				if (change.charAt(0) == '/') {
					path.clear();
					change = change.substring(1);
				}
				if (!change.isEmpty()) {
					String[] a = change.split("/");
					for (String dir : a)
						if (dir.equals(".."))
							path.remove(path.size() - 1);
						else
							path.add(dir);
				}
			} else
				throw new AssertionError("Unknown command");
		}
	}

	void inp() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new C().inp();
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
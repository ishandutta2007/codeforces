import java.io.*;
import java.util.*;

public class B {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		String s;
		ArrayList<String> text = new ArrayList<String>();
		int maxLen = 0;
		while ((s = br.readLine()) != null) {
			text.add(s);
			maxLen = Math.max(maxLen, s.length());
		}

		for (int i = 0; i < maxLen + 2; i++)
			out.print('*');
		out.println();
		
		boolean alignLeft = false;
		
		for (int i = 0; i < text.size(); i++) {
			out.print('*');
			s = text.get(i);
			int space = maxLen - s.length();
			for (int j = 0; j < space / 2; j++)
				out.print(' ');
			if (space % 2 == 1) {
				if (alignLeft)
					out.print(' ');
			}
			out.print(s);
			for (int j = 0; j < space / 2; j++)
				out.print(' ');
			if (space % 2 == 1) {
				if (!alignLeft)
					out.print(' ');
				alignLeft = !alignLeft;
			}
			out.println('*');
		}
		for (int i = 0; i < maxLen + 2; i++)
			out.print('*');
		out.println();
	}

	void inp() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new B().inp();
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
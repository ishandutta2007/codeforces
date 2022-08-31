import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.NoSuchElementException;

public class Main {
	public static boolean[] checked;
	public static ArrayList<Integer>[] list;
	public static ArrayList<Integer> check;
	public static void main(String[] args) {
		FS r = new FS();
		int n = r.nextInt();
		int m = r.nextInt();
		int k = r.nextInt();
		int[] c = new int[n];
		int[] cs = new int[k];
		checked = new boolean[n];

		for(int i=0; i<n; i++) {
			c[i] = r.nextInt()-1;
		}

		list = new ArrayList[n];
		for(int i=0; i<n; i++) {
			list[i] = new ArrayList<Integer>();
		}
		for(int i=0; i<m; i++) {
			int a = r.nextInt()-1;
			int b = r.nextInt()-1;
			list[a].add(b);
			list[b].add(a);
		}

		int ans = 0;
		for(int i=0; i<n; i++) {
			if(checked[i] == false) {
				check = new ArrayList<Integer>();
				dfs(i);
				int maxCount = 0;
				for(int j : check) {
					cs[c[j]]++;
					maxCount = Math.max(maxCount, cs[c[j]]);
				}
				for(int j : check) {
					cs[c[j]] = 0;
				}
				ans += check.size()-maxCount;
			}
		}
		System.out.println(ans);
	}

	public static void dfs(int i) {
		if(checked[i]) return;
		check.add(i);
		checked[i] = true;
		for(int j : list[i]) {
			if(!checked[j]) dfs(j);
		}
	}

	// Read Class
	static class FS {
		private final InputStream in = System.in;
		private final byte[] buffer = new byte[1024];
		private int ptr = 0;
		private int buflen = 0;
		private boolean hasNextByte() {
			if (ptr < buflen) {
				return true;
			} else {
				ptr = 0;
				try {
					buflen = in.read(buffer);
				} catch (IOException e) {
					e.printStackTrace();
				}
				if (buflen <= 0) {
					return false;
				}
			}
			return true;
		}

		private int readByte() { return hasNextByte() ? buffer[ptr++] : -1;}
		private boolean isPrintableChar(int c) {return 33 <= c && c <= 126;}
		private void skipUnprintable() {while(hasNextByte() && !isPrintableChar(buffer[ptr])) ptr++;}

		public boolean hasNext() { skipUnprintable(); return hasNextByte();}
		public String next() {
			if (!hasNext()) throw new NoSuchElementException();
			StringBuilder sb = new StringBuilder();
			int b = readByte();
			while(isPrintableChar(b)) {
				sb.appendCodePoint(b);
				b = readByte();
			}
			return sb.toString();
		}
		public int nextInt() {
			return (int)nextLong();
		}
		public long nextLong() {
			if (!hasNext()) throw new NoSuchElementException();
			long n = 0;
			boolean minus = false;
			int b = readByte();
			if (b == '-') {
				minus = true;
				b = readByte();
			}
			if (b < '0' || '9' < b) {
				throw new NumberFormatException();
			}
			while(true) {
				if ('0' <= b && b <= '9') {
					n *= 10;
					n += b - '0';
				} else if(b == -1 || !isPrintableChar(b)) {
					return minus ? -n : n;
				} else {
					throw new NumberFormatException();
				}
				b = readByte();
			}
		}
	}
}
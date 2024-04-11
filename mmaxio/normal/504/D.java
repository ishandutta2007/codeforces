import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class D {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;
	
	static final int BS_SIZE = 32;
	static final int SIZE = 2000;

	void solve() throws IOException {
		int m = nextInt();
		
		long[][] haveBS = new long[m][SIZE];
		long[][] reprBS = new long[m][SIZE];
		int[] bit = new int[m];
		int haveCnt = 0;
		
		for (int i = 0; i < m; i++) {
			BigInteger x = new BigInteger(nextToken());
			long[] xBS = new long[BS_SIZE];
			for (int j = 0; j < SIZE; j++) {
				if (x.testBit(j)) {
					set(xBS, j);
				}
			}
			
			long[] curRepr = new long[BS_SIZE];
			
			for (int j = 0; j < haveCnt; j++) {
				if (test(xBS, bit[j])) {
					xor(xBS, haveBS[j]);
					xor(curRepr, reprBS[j]);
				}
			}
			
			int curBit = getBit(xBS);
			if (curBit == -1) {
				printRepr(curRepr);
				continue;
			}
			out.println(0);
			haveBS[haveCnt] = xBS;
			set(curRepr, i);
			reprBS[haveCnt] = curRepr;
			bit[haveCnt] = curBit;
			
			for (int j = 0; j < haveCnt; j++) {
				if (test(haveBS[j], curBit)) {
					xor(haveBS[j], xBS);
					xor(reprBS[j], curRepr);
				}
			}
			haveCnt++;
		}
	}
	
	void printRepr(long[] a) {
		List<Integer> outp = new ArrayList<>();
		for (int i = 0; i < BS_SIZE; i++) {
			long x = a[i];
			for (int j = 0; j < 64; j++) {
				if (((x >>> j) & 1) == 1) {
					outp.add((i << 6) + j);
				}
			}
		}
		out.print(outp.size() + " ");
		for (int x : outp) {
			out.print(x + " ");
		}
		out.println();
	}
	
	void set(long[] bs, int pos) {
		bs[pos >> 6] |= 1L << (pos & 63);
	}
	
	boolean test(long[] bs, int pos) {
		return ((bs[pos >> 6] >>> (pos & 63)) & 1) == 1;
	}
	
	void xor(long[] a, long[] b) {
		for (int i = 0; i < BS_SIZE; i++) {
			a[i] ^= b[i];
		}
	}
	
	int getBit(long[] a) {
		for (int i = 0; i < BS_SIZE; i++) {
			if (a[i] != 0) {
				return (i << 6) + Long.numberOfTrailingZeros(a[i]); 
			}
		}
		return -1;
	}

	D() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new D();
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
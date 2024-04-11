import java.util.*;
import java.io.*;

public class dwater {
	private static Reader		in;
	private static PrintWriter	out;
	
	public static void main (String [] args) throws IOException {
		in = new Reader ();
		out = new PrintWriter (System.out, true);
		int N = in.nextInt(), P = in.nextInt();
		int [] next = new int [N], cap = new int [N];
		Arrays.fill (next, -1);
		boolean [] prev = new boolean [N];
		for (int i = 0; i < P; i++) {
			int a = in.nextInt(), b = in.nextInt(), d = in.nextInt();
			a--; b--;
			next [a] = b;
			cap [a] = d;
			prev [b] = true;
		}
		ArrayList <Triplet> ans = new ArrayList <Triplet> ();
		for (int i = 0; i < N; i++) {
			if (!prev [i]) {
				if (next [i] == -1) continue;
				int cur = i, ccap = cap [i];
				while (next [cur] != -1 && next [cur] != i) {
					ccap = Math.min (ccap, cap [cur]);
					cur = next [cur];
				}
				if (next [cur] == i) continue;
				ans.add (new Triplet (i + 1, cur + 1, ccap));
			}
		}
		
		out.println (ans.size());
		for (Triplet t : ans)
			out.println (t);
		out.close();
		System.exit(0);
	}
	
	static class Triplet {
		public int a, b, c;
		public Triplet (int a, int b, int c) {
			this.a = a; this.b = b; this.c = c;
		}
		public String toString() {
			return String.format ("%d %d %d", a, b, c);
		}
	}
	
	static class Reader {
		final private int			BUFFER_SIZE	= 1 << 16;
		private DataInputStream	din;
		private byte []			buffer;
		private int					bufferPointer, bytesRead;
		
		public Reader () {
			din = new DataInputStream (System.in);
			buffer = new byte[BUFFER_SIZE];
			bufferPointer = bytesRead = 0;
		}
		
		public Reader (String file_name) throws IOException {
			din = new DataInputStream (new FileInputStream (file_name));
			buffer = new byte[BUFFER_SIZE];
			bufferPointer = bytesRead = 0;
		}
		
		public String readLine () throws IOException {
			byte [] buf = new byte[1024];
			int cnt = 0, c;
			while ((c = read ()) != -1) {
				if (c == '\n') break;
				buf[cnt++] = (byte) c;
			}
			return new String (buf, 0, cnt);
		}
		
		public int nextInt () throws IOException {
			int ret = 0;
			byte c = read ();
			while (c <= ' ')
				c = read ();
			boolean neg = (c == '-');
			if (neg) c = read ();
			do {
				ret = ret * 10 + c - '0';
			} while ((c = read ()) >= '0' && c <= '9');
			if (neg) return -ret;
			return ret;
		}
		
		public long nextLong () throws IOException {
			long ret = 0;
			byte c = read ();
			while (c <= ' ')
				c = read ();
			boolean neg = (c == '-');
			if (neg) c = read ();
			do {
				ret = ret * 10 + c - '0';
			} while ((c = read ()) >= '0' && c <= '9');
			if (neg) return -ret;
			return ret;
		}
		
		public double nextDouble () throws IOException {
			double ret = 0, div = 1;
			byte c = read ();
			while (c <= ' ')
				c = read ();
			boolean neg = (c == '-');
			if (neg) c = read ();
			do {
				ret = ret * 10 + c - '0';
			} while ((c = read ()) >= '0' && c <= '9');
			if (c == '.') while ((c = read ()) >= '0' && c <= '9')
				ret += (c - '0') / (div *= 10);
			if (neg) return -ret;
			return ret;
		}
		
		private void fillBuffer () throws IOException {
			bytesRead = din.read (buffer, bufferPointer = 0, BUFFER_SIZE);
			if (bytesRead == -1) buffer[0] = -1;
		}
		
		private byte read () throws IOException {
			if (bufferPointer == bytesRead) fillBuffer ();
			return buffer[bufferPointer++];
		}
		
		public void close () throws IOException {
			if (din == null) return;
			din.close ();
		}
	}
	
}

import java.util.*;
import java.io.*;

public class D158 {
	private static Reader in;
	private static PrintWriter out;
	
	private static int [] arr;
	private static int N;

	public static void main(String[] args) throws IOException {
		in = new Reader();
		out = new PrintWriter(System.out, true);
		
		N = in.nextInt();
		arr = new int [N];
		for (int i = 0; i < N; i++)
			arr [i] = in.nextInt();
		
		int sum = 0;
		for (int i = 0; i < N; i++)
			sum += arr [i];
		
		for (int i = 1; i * i <= N; i++) {
			if (N % i != 0) continue;
			if (N / i >= 3) {
				for (int j = 0; j < i; j++) {
					int tsum = calc (j, i);
					if (tsum > sum)
						sum = tsum;
				}
			}
			if (i >= 3) {
				for (int j = 0; j < N / i; j++) {
					int tsum = calc (j, N / i);
					if (tsum > sum)
						sum = tsum;
				}
			}
		}
		
		out.println (sum);
		out.close();
		System.exit(0);
	}
	
	private static int calc (int offset, int len) {
		int sum = 0;
		for (int k = offset; k < N; k += len)
			sum += arr [k];
		return sum;
	}

	static class Reader {
		final private int BUFFER_SIZE = 1 << 16;
		private DataInputStream din;
		private byte[] buffer;
		private int bufferPointer, bytesRead;

		public Reader() {
			din = new DataInputStream(System.in);
			buffer = new byte[BUFFER_SIZE];
			bufferPointer = bytesRead = 0;
		}

		public Reader(String file_name) throws IOException {
			din = new DataInputStream(new FileInputStream(file_name));
			buffer = new byte[BUFFER_SIZE];
			bufferPointer = bytesRead = 0;
		}

		public String readLine() throws IOException {
			byte[] buf = new byte[1024];
			int cnt = 0, c;
			while ((c = read()) != -1) {
				if (c == '\n')
					break;
				buf[cnt++] = (byte) c;
			}
			return new String(buf, 0, cnt);
		}

		public int nextInt() throws IOException {
			int ret = 0;
			byte c = read();
			while (c <= ' ')
				c = read();
			boolean neg = (c == '-');
			if (neg)
				c = read();
			do {
				ret = ret * 10 + c - '0';
			} while ((c = read()) >= '0' && c <= '9');
			if (neg)
				return -ret;
			return ret;
		}

		public long nextLong() throws IOException {
			long ret = 0;
			byte c = read();
			while (c <= ' ')
				c = read();
			boolean neg = (c == '-');
			if (neg)
				c = read();
			do {
				ret = ret * 10 + c - '0';
			} while ((c = read()) >= '0' && c <= '9');
			if (neg)
				return -ret;
			return ret;
		}

		public double nextDouble() throws IOException {
			double ret = 0, div = 1;
			byte c = read();
			while (c <= ' ')
				c = read();
			boolean neg = (c == '-');
			if (neg)
				c = read();
			do {
				ret = ret * 10 + c - '0';
			} while ((c = read()) >= '0' && c <= '9');
			if (c == '.')
				while ((c = read()) >= '0' && c <= '9')
					ret += (c - '0') / (div *= 10);
			if (neg)
				return -ret;
			return ret;
		}

		private void fillBuffer() throws IOException {
			bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE);
			if (bytesRead == -1)
				buffer[0] = -1;
		}

		private byte read() throws IOException {
			if (bufferPointer == bytesRead)
				fillBuffer();
			return buffer[bufferPointer++];
		}

		public void close() throws IOException {
			if (din == null)
				return;
			din.close();
		}
	}

}
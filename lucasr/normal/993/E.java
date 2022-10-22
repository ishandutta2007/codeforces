import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class EE {
	
	static int[] values;
	static long[] ans;
	static FFT fft;
	
	static void calc(int from, int to) {
		if (to - from < 50) {
			for (int i = from; i <= to; i++) {
				for (int j = i; j <= to; j++) {
					ans[values[j]-values[i-1]]++;
				}
			}
			return;
		}
		int med = (from + to) / 2;
		calc(from, med);
		calc(med + 1, to);
		int[] a = new int[values[to] - values[med] + 1];
		int idx = 0;
		for (int i = med+1; i <= to ; i++) {
			if (values[i] != values[i-1]) idx++;
			a[idx]++;
		}
		int[] b = new int[values[med] - values[from-1] + 1];
		idx = 0;
		for (int i = med; i >= from ; i--) {
			if (values[i] != values[i-1]) idx++;
			b[idx]++;
		}
		long[] prod = fft.multiply(a, b);
		for (int i = 0; i < prod.length; i++) {
			ans[i] += prod[i];
		}
	}
	
	public static void main(String[] args) throws IOException {
		MyScanner sc = new MyScanner();
		PrintWriter out = new PrintWriter(System.out);
		int n = sc.nextInt();
		int x = sc.nextInt();
		values = new int[n+1];
		for (int i = 1; i < values.length; i++) {
			values[i] = values[i-1] + (sc.nextInt() >= x ? 0 : 1);
		}
		ans = new long[n+1];
		
		int size = 1;
		while (size < n) size *= 2;
		size *= 2;
		fft = new FFT(size);
		calc(1, n);
		
		out.print(ans[0]);
		for (int i = 1; i < ans.length; i++) {
			out.print(" " + ans[i]);
		}
		out.println();
		
		out.flush();
	}
	
	static class FFT {
		double[] roots;
		int maxN;
		
		public FFT(int maxN) {
			this.maxN = maxN;
			initRoots();
		}
		
		long[] multiply(int[] a, int[] b) {
			int minSize = a.length + b.length - 1;
			int bits = 1;
			while (1 << bits < minSize) bits++;
			int N = 1<<bits;
			double[] aa = toComplex(a, N);
			double[] bb = toComplex(b, N);
			fftIterative(aa, false);
			fftIterative(bb, false);
			double[] c = new double[aa.length];
			for (int i = 0; i < N; i++) {
				c[2*i] = aa[2*i]*bb[2*i] - aa[2*i+1]*bb[2*i+1];
				c[2*i+1] = aa[2*i]*bb[2*i+1] + aa[2*i+1]*bb[2*i];
			}
			fftIterative(c, true);
			long[] ret = new long[minSize];
			for (int i = 0; i < ret.length; i++) {
				ret[i] = Math.round(c[2*i]);
			}
			return ret;
		}
		
		static double[] toComplex(int[] arr, int size) {
			double[] ret = new double[size * 2];
			for (int i = 0; i < arr.length; i++) {
				ret[2*i] = arr[i];
			}
			return ret;
		}
		
		void initRoots() {
			roots = new double[2 * (maxN + 1)];
			double ang = 2 * Math.PI / maxN;
			for (int i = 0; i <= maxN; i++) {
				roots[2 * i] = Math.cos(i * ang);
				roots[2 * i + 1] = Math.sin(i * ang);
			}
		}
		
		int bits(int N) {
			int ret = 0;
			while (1 << ret < N) ret++;
			if (1 << ret != N) throw new RuntimeException();
			return ret;
		}
		
		void fftIterative(double[] array, boolean inv) {
			int bits = bits(array.length / 2);
			int N = 1 << bits;
			for (int from = 0; from < N; from++) {
				int to = Integer.reverse(from) >>> (32 - bits);
				if (from < to) {
					double tmpR = array[2*from];
					double tmpI = array[2*from+1];
					array[2*from] = array[2*to];
					array[2*from+1] = array[2*to+1];
					array[2*to] = tmpR;
					array[2*to+1] = tmpI;
				}
			}
			for (int n = 2; n <= N; n *= 2) {
				int delta = 2 * maxN / n;
				for (int from = 0; from < N; from += n) {
					int rootIdx = inv ? 2 * maxN : 0;
					double tmpR, tmpI;
					for (int arrIdx = 2 * from; arrIdx < 2 * from + n; arrIdx += 2) {
						tmpR = array[arrIdx + n] * roots[rootIdx] - array[arrIdx + n + 1] * roots[rootIdx + 1];
						tmpI = array[arrIdx + n] * roots[rootIdx + 1] + array[arrIdx + n + 1] * roots[rootIdx];
						array[arrIdx + n] = array[arrIdx] - tmpR;
						array[arrIdx + n + 1] = array[arrIdx + 1] - tmpI;
						array[arrIdx] += tmpR;
						array[arrIdx + 1] += tmpI;
						rootIdx += (inv ? -delta : delta);
					}
				}
			}
			if (inv) {
				for (int i = 0; i < array.length; i++) {
					array[i] /= N;
				}
			}
		}
	}
	
	static class MyScanner {
		private BufferedReader br;
		private StringTokenizer tokenizer;
		
		public MyScanner() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}
		
		public String next() {
			while (tokenizer == null || !tokenizer.hasMoreTokens()) {
				try {
					tokenizer = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					throw new RuntimeException(e);
				}
			}
			return tokenizer.nextToken();
		}
		
		public int nextInt() {
			return Integer.parseInt(next());
		}
		
		public long nextLong() {
			return Long.parseLong(next());
		}
	}
}
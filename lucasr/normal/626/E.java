import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class E {
	static long[] acums;
	static int n;
	
	static long num(int idx, int cant) {
		return acums[idx + 1] - acums[idx - cant] + acums[n] - acums[n - cant];
	}
	
	static boolean grows(long n1, long d1, long n2, long d2) {
		return n2 * d1 > n1 * d2;
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		List<Long> valsTmp = new ArrayList<Long>(n);
		for (int i = 0; i < n; i++) {
			valsTmp.add(sc.nextLong());
		}
		Collections.sort(valsTmp);
		long[] vals = new long[n];
		for (int i = 0; i < vals.length; i++) {
			vals[i] = valsTmp.get(i);
		}
		acums = new long[n+1];
		acums[0] = 0;
		for (int i = 1; i < acums.length; i++) {
			acums[i] = acums[i-1] + vals[i-1];
		}
		long bestNum = -1, bestDen = 1;
		int bestIdx = -1, bestQty = 0;
		for (int i = 0; i < vals.length; i++) {
			int left = 0, right = Math.min(i, n - i - 1);
			while (left < right) {
				int med = (left + right) / 2;
				long num = num(i, med);
				long numN = num(i, med + 1);
				if (grows(num, 2*med+1, numN, 2*med + 3)) left = med + 1;
				else right = med;
			}
			long num = num(i, left) - vals[i] * (2*left + 1);
			if (grows(bestNum, bestDen, num, 2*left+1)) {
				bestIdx = i;
				bestQty = left;
				bestNum = num;
				bestDen = 2*left+1;
			}
		}
		StringBuilder sb = new StringBuilder();
		System.out.println(2*bestQty+1);
		for (int i = bestIdx - bestQty ;i <= bestIdx; i++) {
			sb.append(vals[i] + " ");
		}
		for (int i = n - bestQty ;i < n; i++) {
			sb.append(vals[i] + " ");
		}
		System.out.println(sb.toString());
	}
}
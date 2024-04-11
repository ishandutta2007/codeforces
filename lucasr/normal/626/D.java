import java.util.Arrays;
import java.util.Scanner;

public class D {
	static final int MAX = 5000;
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] vals = new int[n];
		for (int i = 0; i < vals.length; i++) {
			vals[i] = sc.nextInt();
		}
		Arrays.sort(vals);
		long[] difs = new long[MAX];
		for (int i = 0; i < vals.length; i++) {
			for (int j = i + 1; j < vals.length; j++) {
				difs[vals[j]-vals[i]]++;
			}
		}
		long[] difs2 = new long[2 * MAX];
		for (int i = 0; i < difs.length; i++) {
			for (int j = 0; j < difs.length; j++) {
				difs2[i+j] += difs[i] * difs[j]; 
			}
		}
		long ok = 0, notOk = 0;
		for (int i = 0; i < difs.length; i++) {
			for (int j = 0; j < difs2.length; j++) {
				if (i > j) ok += difs[i]*difs2[j];
				else notOk += difs[i]*difs2[j];
			}
		}
		System.out.println(String.format("%.10f", ok * 1.0 / (ok + notOk)));
	}
}
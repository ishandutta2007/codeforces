using System;

public class Solution {

	static int n, P1, P2, P3, T1, T2;
	static int[] l, r;
	
	static int calc(int n) {
		int res = 0;
		if(n <= T1) return n * P1;
		else {
			res += T1 * P1;
			n -= T1;
			if(n <= T2) return res + n * P2;
			else {
				res += T2 * P2;
				n -= T2;
				return res + n * P3;
			}
		}
	}
	
	public static void Main() {
		String[] tmp = Console.ReadLine().Split(' ');
		n = int.Parse(tmp[0]);
		P1 = int.Parse(tmp[1]);
		P2 = int.Parse(tmp[2]);
		P3 = int.Parse(tmp[3]);
		T1 = int.Parse(tmp[4]);
		T2 = int.Parse(tmp[5]);
		l = new int[n];
		r = new int[n];
		for(int i=0;i<n;++i) {
			tmp = Console.ReadLine().Split(' ');
			l[i] = int.Parse(tmp[0]);
			r[i] = int.Parse(tmp[1]);
		}
		int res = 0;
		for(int i=0;i<n;++i) {
			res += (r[i] - l[i]) * P1;
			if(i > 0) {
				res += calc( l[i] - r[i-1]);
			}
		}
		Console.WriteLine(res);
	}
}
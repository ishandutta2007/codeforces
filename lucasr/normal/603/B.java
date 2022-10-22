import java.util.Scanner;

public class B {
	static final long MOD = 1000000007L;
	
	static long pow(long b, long e) {
		long ans = 1;
		for (int i = 0; i < e; i++) {
			ans*=b;
			ans%=MOD;
		}
		return ans;
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long p = sc.nextLong();
		long k = sc.nextLong();
		long ans = 0;
		if (k == 0) {
			ans = pow(p, p - 1);
		} else if (k == 1){
			ans = pow(p, p);
		} else {
			int e = 1;
			long pow = k;
			while (pow != 1) {
				e++;
				pow*=k;
				pow%=p;
			}
			ans = pow(p, (p-1)/e);
		}
		System.out.println(ans);
	}
}
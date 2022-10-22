import java.util.Scanner;

public class A {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long s = sc.nextLong();
		long x = sc.nextLong();
		long dif = s - x;
		long ans = 0;
		if (dif % 2 == 0) {
			dif /= 2;
			if ((dif & x) == 0) {
				ans = 1L << Long.bitCount(x);
				if (dif == 0) ans -= 2;
			}
		}
		System.out.println(ans);
	}
}
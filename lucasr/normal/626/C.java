import java.util.Scanner;

public class C {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		int totn = 0, totm = 0, totBoth = 0;
		int ans = 0;
		for (int i = 2; i < 1000000000; i++) {
			if (i % 6 == 0) totBoth++;
			if (i % 2 == 0) totn++;
			if (i % 3 == 0) totm++;
			if (totn >= n && totm >= m && totn + totm - totBoth >= n + m) {
				ans = i;
				break;
			}
		}
		System.out.println(ans);
	}
}
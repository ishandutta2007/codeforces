import java.util.Scanner;

public class A {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		sc.nextInt();
		char[] vals = sc.next().toCharArray();
		int ans = 0;
		for (int i = 0; i < vals.length; i++) {
			for (int j = i; j < vals.length; j++) {
				int u = 0, l = 0;
				for (int k = i; k <= j; k++) {
					if (vals[k] == 'U') u++;
					else if (vals[k] == 'D') u--;
					else if (vals[k] == 'L') l++;
					else l--;
				}
				if (u == 0 && l == 0) ans++;
			}
		}
		System.out.println(ans);
	}
}
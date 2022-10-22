import java.util.Scanner;

public class A {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		sc.nextInt();
		char[] vals = sc.next().toCharArray();
		int ans = 1;
		for (int i = 1; i < vals.length; i++) {
			if (vals[i] != vals[i-1]) ans++;
		}
		System.out.println(ans + 2 <= vals.length ? ans + 2 : ans + 1 <= vals.length ? ans + 1 : ans);
	}
}
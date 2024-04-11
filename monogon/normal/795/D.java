import java.util.Scanner;

public class LieTruth {

	static int n, l, r, a[] = new int[100000], b[] = new int[100000];
	static int count[] = new int[100001];
	static Scanner s;
	
	public static void main(String[] args) {
		s = new Scanner(System.in);
		n = s.nextInt();
		l = s.nextInt();
		r = s.nextInt();
		for(int i = 0; i < n; i++) {
			a[i] = s.nextInt();
			if(i >= l - 1 && i <= r - 1) {
				count[a[i]]++;
			}
		}
		for(int i = 0; i < n; i++) {
			b[i] = s.nextInt();
			if(a[i] != b[i] && (i < l - 1 || i > r - 1)) {
				System.out.println("LIE");
				return;
			}
			if(i >= l - 1 && i <= r - 1) {
				count[b[i]]--;
			}
		}
		for(int i = 1; i <= n; i++) {
			if(count[i] != 0) {
				System.out.println("LIE");
				return;
			}
		}
		System.out.println("TRUTH");
	}
	
}
import java.util.Scanner;


public class Myclass {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int tc = sc.nextInt();
		for( ; tc > 0 ; tc --) {
			String s = sc.next();
			int n = s.length();
			boolean zero = false;
			boolean haseven = false;
			int sum = 0;
			for(int i = 0 ; i < n;i ++) {
				sum += s.charAt(i) - '0';
				if(s.charAt(i) == '0' && !zero) {
					zero = true;
					continue;
				}
				if((s.charAt(i) - '0') % 2 == 0) {
					haseven = true;
				}
			}
			if(zero && haseven && (sum % 3 == 0))
				System.out.println("red");
			else
				System.out.println("cyan");
		}
	}
}
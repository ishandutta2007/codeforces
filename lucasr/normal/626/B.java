import java.util.Scanner;

public class B {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		sc.nextInt();
		int B = 0, G = 0, R = 0;
		for (char c : sc.next().toCharArray()) {
			if (c == 'B') B++;
			else if (c == 'G') G++;
			else R++;
		}
		String ans = "";
		int moreThan1 = 0, zeroes = 0;
		if (B > 1) moreThan1++;
		if (G > 1) moreThan1++;
		if (R > 1) moreThan1++;
		if (B == 0) zeroes++;
		if (G == 0) zeroes++;
		if (R == 0) zeroes++;
		if (zeroes == 0 || moreThan1 > 1) ans = "BGR";
		else if (zeroes == 2) {
			if (B != 0) ans = "B"; 
			if (G != 0) ans = "G"; 
			if (R != 0) ans = "R"; 
		} else {
			if (moreThan1 == 0) {
				if (B == 0) ans = "B"; 
				if (G == 0) ans = "G"; 
				if (R == 0) ans = "R"; 
			} else {
				// moreThan1 == 1
				if (B > 1) ans = "GR"; 
				if (G > 1) ans = "BR"; 
				if (R > 1) ans = "BG"; 
			}
		}
		System.out.println(ans);
	}
}
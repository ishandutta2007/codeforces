import java.util.*;

public class _1730A {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int t = sc.nextInt();
		
		for(int i=1;i<=t;i++)
		{
			solve(sc);
		}
	}
	
	public static void solve(Scanner sc)
	{
		int n = sc.nextInt();
		int c = sc.nextInt();
		
		int input[] = new int[n+1];
		
		for(int i=0;i<n;i++)
			input[i] = sc.nextInt();
		
		int MX=100;
		
		int counter[] = new int[MX+1];
		
		for(int i=0;i<n;i++)
			counter[input[i]]++;
		
		int output=0;
		
		for(int i=0;i<=MX;i++)
			output+=Math.min(c, counter[i]);
		
		System.out.println(output);
	}

}
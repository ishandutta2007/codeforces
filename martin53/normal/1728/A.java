//package name;

import java.util.*;

public class _1728A {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		
		int t = in.nextInt();
		
		for(int i=1;i<=t;i++)
		{
			solve(in);
		}
	}

	public static void solve(Scanner in)
	{
		int n = in.nextInt();
		
		int[] input = new int[n+1];
		
		for(int i=0;i<n;i++)
			input[i] = in.nextInt();
		
		int MX=0;
		
		for(int i=0;i<n;i++)
			if(input[i] > input[MX])
				MX=i;
		
		System.out.println(MX+1);
	}
	
}
//package name;

import java.util.*;

public class _1729A {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		
		int t=sc.nextInt();
		
		for(int i=1;i<=t;i++)
		{
			solve(sc);
		}
	}
	
	public static void solve(Scanner sc)
	{
		int a=sc.nextInt();
		int b=sc.nextInt();
		int c=sc.nextInt();
		
		int one=a-1;
		int two=Math.abs(b-c)+c-1;
		
		int output;
		
		if(one<two)output=1;
		else if(one==two)output=3;
		else output=2;
		
		System.out.println(output);
	}

}
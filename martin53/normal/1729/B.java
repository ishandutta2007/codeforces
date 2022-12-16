//package name;

import java.util.*;

public class _1729B {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
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
		
		String input = in.next();

		
		char[] output = new char[n+1];
			
		int position_output=0;
		
		int i=n-1;
		
		while(i>=0)
		{
			int id=0;
			
			if(input.charAt(i)=='0')
			{
				id=(input.charAt(i-2)-'0')*10+input.charAt(i-1)-'0';
				
				i-=3;
			}
			else
			{
				id=(input.charAt(i)-'0');
				
				i--;
			}
			
			char out = (char) (id - 1 + 'a');
			
			output[position_output] = out;
			
			position_output++;
		}
		
		String out="";
		
		for(i=position_output-1;i>=0;i--)
			out=out+output[i];
		
		System.out.println(out);

	}
}
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Scanner;


public class Solution {
	

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);
		
		boolean firstLetter = false;
		boolean used[] = new boolean[11];
		int diffLetters = 0;
		for (int i = 0; i < 11; i++)
			used[i] = false;
		
		String s;
		s = in.next();
		int len = s.length();
		BigInteger ans = BigInteger.ONE;
		
		if (s.charAt(0) == '?')
			ans = BigInteger.valueOf(9);
		else
		{
			for (int i = 0; i < 10; i++)
				if (s.charAt(0) - 'A' == i)
				{
					firstLetter = true;
					used[i] = true;
				}
		}
		for (int i = 1; i < len; i++)
		{
			if (s.charAt(i) == '?')
			{
				ans = ans.multiply(BigInteger.TEN);
			}
			else
			{
				for (int j = 0; j < 10; j++)
					if (s.charAt(i) - 'A' == j)
					{
						if (used[j] == true)
							continue;
						diffLetters++;
						used[j] = true;
					}
			}
		}
		int rem = 10;
		if (firstLetter)
		{
			rem--;
			ans = ans.multiply(BigInteger.valueOf(9) );
		}
		for (int i = 0; i < diffLetters; i++)
		{
			ans = ans.multiply(BigInteger.valueOf(rem) );
			rem--;
		}
		out.println(ans);
		out.flush();

	}

}
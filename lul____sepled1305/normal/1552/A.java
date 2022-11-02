/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
public class Main
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		while(T != 0) {
			T--;
			int count = 0;
			int n = in.nextInt();
			String s = in.next();
			char[] c = s.toCharArray();
			Arrays.sort(c);
			for(int i=0;i<n;i++) {
				if(s.charAt(i) != c[i])
					count++;
			}
			System.out.println(count);
		}
	}
}
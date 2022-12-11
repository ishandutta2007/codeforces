//package test;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;
import javafx.util.Pair;

/**
 * Header
 */

public class test
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		String s = sc.nextLine(); s = sc.nextLine();
		ArrayList<Integer> ans = new ArrayList<Integer>();
		int c = 0;
		for (int i = 0; i < N; i++)
		{
			if (s.charAt(i) == 'B')
			{
				c++;
			}
			else
			{
				if (c != 0) ans.add(c);
				c = 0;
			}
		}
		if (c != 0) ans.add(c);
		System.out.println(ans.size());
		for (int i = 0; i < ans.size(); i++)
		{
			System.out.print(ans.get(i) + " ");
		}
		System.out.print('\n');
		System.exit(0);
	}
}
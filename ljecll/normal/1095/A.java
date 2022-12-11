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
//		System.out.println(s); System.exit(0);
		String ans = new String();
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (j * (j + 1) / 2 == i)
				{
					ans += s.charAt(i);
				}
			}
		}
		System.out.println(ans);
		System.exit(0);
	}
}
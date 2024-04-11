//package test;

import java.util.Scanner;

/**
 * Header
 */

public class test
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int TC = sc.nextInt();
		for (int tc = 0; tc < TC; tc++)
		{
			long a = sc.nextLong(), b = sc.nextLong(), c = sc.nextLong();
			System.out.println((a + b + c) >> 1);
		}
	}
}
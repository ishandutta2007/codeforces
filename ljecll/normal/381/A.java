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
		int N = sc.nextInt(); int[] arr = new int[1013];
		for (int i = 0; i < N; i++)
		{
			arr[i] = sc.nextInt();
		}
		int lt = 0, rt = N - 1, ans0 = 0, ans1 = 0;
		for (int i = 0; i < N; i++)
		{
			int cur;
			if (arr[lt] > arr[rt])
			{
				cur = arr[lt];
				lt++;
			}
			else
			{
				cur = arr[rt];
				rt--;
			}
			if (i % 2 == 1) ans1 += cur;
			else ans0 += cur;
		}
		System.out.println(ans0 + " " + ans1);
	}
}
//package test;

import java.util.Arrays;
import java.util.Scanner;

/**
 * Header
 */

public class test
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt(), T = sc.nextInt();
		long arr[] = new long[100013]; arr[0] = 0;
		for (int i = 1; i <= N; i++)
		{
			arr[i] = sc.nextInt();
		}
		for (int i = 1; i <= N; i++)
		{
			arr[i] += arr[i - 1];
//			System.out.println(arr[i]);
		}
		int lo = 0, hi = N;
		while(hi > lo)
		{
			int mid = (hi + lo + 1) >> 1;
			boolean ok = false;
			for (int i = 0; i <= N - mid; i++)
			{
				if (arr[i + mid] - arr[i] <= T) ok = true;
			}
			if (ok) lo = mid;
			else hi = mid - 1;
		}
		System.out.println(lo);
		System.exit(0);
	}
}
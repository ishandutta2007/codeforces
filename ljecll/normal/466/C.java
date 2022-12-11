/**
 * Header
 */

import java.util.Scanner;

public class test
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		long sum = 0, psum = 0, freq = 0, ans = 0;
		long arr[] = new long[500013];
		for (int i = 0; i < N; i++)
		{
			arr[i] = sc.nextInt();
			sum += arr[i];
		}
		if (sum % 3 != 0)
		{
			System.out.println("0\n");
			System.exit(0);
		}
		sum /= 3;
		for (int i = 0; i < N - 1; i++)
		{
			psum += arr[i];
			if (psum == 2 * sum) ans += freq;
			if (psum == sum) freq++;
		}
		System.out.println(ans);
		System.exit(0);
	}
}
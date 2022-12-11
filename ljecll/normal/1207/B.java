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
		int N = sc.nextInt(), M = sc.nextInt();
		int[][] goal = new int[50][50], grid = new int[50][50];
		ArrayList<Integer> ans = new ArrayList<Integer>();
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				goal[i][j] = sc.nextInt();
				grid[i][j] = 0;
			}
		}
		for (int i = 0; i < N - 1; i++)
		{
			for (int j = 0; j < M - 1; j++)
			{
				if (goal[i][j] == 1 && goal[i + 1][j] == 1 && goal[i][j + 1] == 1 && goal[i + 1][j + 1] == 1)
				{
					grid[i][j] = 1; grid[i + 1][j] = 1; grid[i][j + 1] = 1; grid[i + 1][j + 1] = 1;
					ans.add(i); ans.add(j);
				}
			}
		}
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (goal[i][j] != grid[i][j])
				{
					System.out.println("-1");
					System.exit(0);
				}
			}
		}
		System.out.println(ans.size() / 2);
		for (int i = 0; i < ans.size() / 2; i++)
		{
			System.out.println((ans.get(2 * i) + 1) + " " + (ans.get(2 * i + 1) + 1));
		}
		System.exit(0);
	}
}
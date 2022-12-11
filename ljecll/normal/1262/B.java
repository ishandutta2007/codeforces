import java.util.*;
import java.io.*;

public class cf1262b
{
	public static void main(String[] args) throws IOException
	{
		BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
		int TC = Integer.parseInt(f.readLine());
		for (int tc = 0; tc < TC; tc++)
		{
			int N = Integer.parseInt(f.readLine());
			int[] arr = new int[N];
			int[] ans = new int[N];
			boolean[] used = new boolean[N];
			for (int i = 0; i < N; i++)
			{
				used[i] = false;
			}
			int iter = 0;
			StringTokenizer st = new StringTokenizer(f.readLine());
			for (int i = 0; i < N; i++)
			{
				arr[i] = Integer.parseInt(st.nextToken());
				arr[i]--;
				if (i != 0 && arr[i] < arr[i - 1])
				{
					ans[0] = -1;
					break;
				}
				if (i == 0 || arr[i] != arr[i - 1])
				{
					used[arr[i]] = true;
					ans[i] = arr[i];
					continue;
				}
				while(used[iter]) iter++;
				if (iter > arr[i])
				{
					ans[0] = -1;
					break;
				}
				ans[i] = iter;
				used[ans[i]] = true;
			}
			if (ans[0] == -1)
			{
				out.println(-1);
				continue;
			}
			for (int i = 0; i < N; i++)
			{
				if (i > 0) out.print(' ');
				out.print(ans[i] + 1);
			}
			out.print('\n');
		}
		out.close();
	}
}
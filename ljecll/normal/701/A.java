import java.util.*;
import java.io.*;

public class cf701a
{
	public static void main(String[] args) throws IOException
	{
		BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter output = new PrintWriter(new BufferedOutputStream(System.out));
		boolean used[] = new boolean[113];
		int sum = 0, N = Integer.parseInt(input.readLine());
		int[] arr = new int[N];
		StringTokenizer st = new StringTokenizer(input.readLine());
		for (int i = 0; i < N; i++)
		{
			arr[i] = Integer.parseInt(st.nextToken());
			sum += arr[i];
		}
		sum *= 2; sum /= N;
		for (int i = 0; i < N; i++)
		{
			if (used[i]) continue;
			int x = i + 1;
			while(arr[x] != sum - arr[i] || used[x]) x++;
			used[i] = true;
			used[x] = true;
			output.println((i + 1) + " " + (x + 1));
		}
		output.close();
		System.exit(0);
	}
}
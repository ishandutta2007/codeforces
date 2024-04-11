import java.util.*;
import java.io.*;

public class cf1003a
{
	public static void main(String[] args) throws IOException
	{
		BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter output = new PrintWriter(new BufferedOutputStream(System.out));
		int N = Integer.parseInt(input.readLine());
		int[] freq = new int[113];
		StringTokenizer st = new StringTokenizer(input.readLine());
		for (int i = 0; i < N; i++)
		{
			int x = Integer.parseInt(st.nextToken());
			freq[x]++;
		}
		int ans = 0;
		for (int i = 0; i <= 100; i++)
		{
			if (ans < freq[i]) ans = freq[i];
		}
		output.println(ans);
		output.close();
		System.exit(0);
	}
}
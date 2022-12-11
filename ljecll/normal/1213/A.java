import java.util.*;
import java.io.*;

public class cf1213a
{
	public static void main(String[] args) throws IOException
	{
		BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter output = new PrintWriter(new BufferedOutputStream(System.out));
		int N = Integer.parseInt(input.readLine());
		int[] num = new int[2];
		StringTokenizer st = new StringTokenizer(input.readLine());
		for (int i = 0; i < N; i++)
		{
			int x = Integer.parseInt(st.nextToken());
			num[x & 1]++;
		}
		output.println(Math.min(num[0], num[1]));
		output.close();
		System.exit(0);
	}
}
import java.util.*;
import java.io.*;

public class cf1234a
{
	public static void main(String[] args) throws IOException
	{
		BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter output = new PrintWriter(new BufferedOutputStream(System.out));
		int Q = Integer.parseInt(input.readLine());
		while(Q-- > 0)
		{
			int N = Integer.parseInt(input.readLine());
			int sum = 0;
			StringTokenizer st = new StringTokenizer(input.readLine());
			for (int i = 0; i < N; i++)
			{
				int x = Integer.parseInt(st.nextToken());
				sum += x;
			}
			sum = (sum + N - 1) / N;
			output.println(sum);
		}
		output.close();
		System.exit(0);
	}
}
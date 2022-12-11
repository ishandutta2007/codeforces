import java.util.*;
import java.io.*;

public class cf1199a
{
	public static void main(String[] args) throws IOException
	{
		BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter output = new PrintWriter(new BufferedOutputStream(System.out));
		StringTokenizer st = new StringTokenizer(input.readLine());
		int N = Integer.parseInt(st.nextToken());
		int X = Integer.parseInt(st.nextToken());
		int Y = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(input.readLine());
		int[] arr = new int[N];
		for (int i = 0; i < N; i++)
		{
			arr[i] = Integer.parseInt(st.nextToken());
		}
		for (int i = 0; i < N; i++)
		{
			boolean ok = true;
			for (int j = 1; j <= X; j++)
			{
				if (i - j >= 0 && arr[i - j] < arr[i]) ok = false;
			}
			for (int j = 1; j <= Y; j++)
			{
				if (i + j < N && arr[i + j] < arr[i]) ok = false;
			}
			if (ok)
			{
				output.println(i + 1);
				break;
			}
		}
		output.close();
		System.exit(0);
	}
}
import java.util.*;
import java.io.*;

public class cf1167b
{
	public static BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
	public static PrintWriter output = new PrintWriter(new BufferedOutputStream(System.out));
	public static int ask(int a, int b) throws IOException
	{
		output.println("? " + a + ' ' + b);
		output.flush();
		int x = Integer.parseInt(input.readLine());
		return x;
	}
	public static void main(String[] args) throws IOException
	{
		int[] arr = {4, 8, 15, 16, 23, 42};
		int[] res = new int[6];
		for (int i = 2; i <= 5; i++)
		{
			res[i - 1] = ask(1, i);
		}
		while(true)
		{
			for (int i = 1; i <= 5; i++)
			{
				int idx = (int) (Math.random() * (i + 1));
				int was = arr[i];
				arr[i] = arr[idx];
				arr[idx] = was;
			}
			if (arr[0] * arr[1] == res[1] && arr[0] * arr[2] == res[2] && arr[0] * arr[3] == res[3] && arr[0] * arr[4] == res[4])
			{
				break;
			}
		}
		output.print("!");
		for (int i = 0; i <= 5; i++)
		{
			output.print(" " + arr[i]);
		}
		output.print("\n");
		output.close();
		System.exit(0);
	}
}
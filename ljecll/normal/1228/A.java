import java.util.*;
import java.io.*;

public class cf1228a
{
	public static boolean ok(int x)
	{
		ArrayList<Integer> digits = new ArrayList<Integer>();
		while(x > 0)
		{
			digits.add(x % 10);
			x /= 10;
		}
		Collections.sort(digits);
		for (int i = 1; i < digits.size(); i++)
		{
			if (digits.get(i).equals(digits.get(i - 1))) return false;
		}
		return true;
	}
	public static void main(String[] args) throws IOException
	{
		BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter output = new PrintWriter(new BufferedOutputStream(System.out));
		StringTokenizer st = new StringTokenizer(input.readLine());
		int A = Integer.parseInt(st.nextToken());
		int B = Integer.parseInt(st.nextToken());
		int ans = -1;
		for (int i = A; i <= B; i++)
		{
			if (ok(i))
			{
				ans = i;
				break;
			}
		}
		output.println(ans);
		output.close();
		System.exit(0);
	}
}
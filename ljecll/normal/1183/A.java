import java.util.*;
import java.io.*;

public class cf1183a
{
	public static boolean check(int x)
	{
		int sum = 0;
		while(x > 0)
		{
			sum += x % 10;
			x /= 10;
		}
		return (sum % 4 == 0);
	}
	public static void main(String[] args) throws IOException
	{
		BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter output = new PrintWriter(new BufferedOutputStream(System.out));
		int n = Integer.parseInt(input.readLine());
		while(!check(n)) n++;
		output.println(n);
		output.close();
		System.exit(0);
	}
}
import java.util.*;
import java.io.*;

public class cf1241a
{
	public static void main(String[] args) throws IOException
	{
		BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter output = new PrintWriter(new BufferedOutputStream(System.out));
		int Q = Integer.parseInt(input.readLine());
		while(Q-- > 0)
		{
			int x = Integer.parseInt(input.readLine());
			if (x < 4)
			{
				output.println(4 - x);
				continue;
			}
			output.println(x % 2);
		}
		output.close();
		System.exit(0);
	}
}
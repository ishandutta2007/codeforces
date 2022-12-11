import java.util.*;
import java.io.*;

public class cf1141a
{
	public static void main(String[] args) throws IOException
	{
		BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter output = new PrintWriter(new BufferedOutputStream(System.out));
		StringTokenizer st = new StringTokenizer(input.readLine());
		int A = Integer.parseInt(st.nextToken());
		int B = Integer.parseInt(st.nextToken());
		if (B % A > 0)
		{
			output.println("-1");
			output.close();
			System.exit(0);
		}
		B /= A;
		A = 0;
		while(B % 3 == 0)
		{
			B /= 3;
			A++;
		}
		while(B % 2 == 0)
		{
			B /= 2;
			A++;
		}
		if (B != 1)
		{
			output.println("-1");
			output.close();
			System.exit(0);
		}
		output.println(A);
		output.close();
		System.exit(0);
	}
}
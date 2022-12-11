import java.util.*;
import java.io.*;

public class cf1114a
{
	public static void main(String[] args) throws IOException
	{
		BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter output = new PrintWriter(new BufferedOutputStream(System.out));
		StringTokenizer st = new StringTokenizer(input.readLine());
		int X = Integer.parseInt(st.nextToken());
		int Y = Integer.parseInt(st.nextToken());
		int Z = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(input.readLine());
		int A = Integer.parseInt(st.nextToken());
		int B = Integer.parseInt(st.nextToken());
		int C = Integer.parseInt(st.nextToken());
		if (A < X)
		{
			output.println("NO");
			output.close();
			System.exit(0);
		}
		A -= X;
		if (A + B < Y)
		{
			output.println("NO");
			output.close();
			System.exit(0);
		}
		A -= Y;
		if (A + B + C < Z)
		{
			output.println("NO");
			output.close();
			System.exit(0);
		}
		output.println("YES");
		output.close();
		System.exit(0);
	}
}
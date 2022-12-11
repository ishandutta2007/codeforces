import java.util.*;
import java.io.*;

public class cf1186a
{
	public static void main(String[] args) throws IOException
	{
		BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter output = new PrintWriter(new BufferedOutputStream(System.out));
		StringTokenizer st = new StringTokenizer(input.readLine());
		int N = Integer.parseInt(st.nextToken()), M = Integer.parseInt(st.nextToken()), K = Integer.parseInt(st.nextToken());
		if (M >= N && K >= N)
		{
			output.println("YES");
		}
		else
		{
			output.println("NO");
		}
		output.close();
		System.exit(0);
	}
}
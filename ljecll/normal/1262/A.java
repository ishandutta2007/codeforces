import java.io.*;
import java.util.*;

public class test
{
	public static void main(String[] args) throws IOException
	{
		BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
		int TC = Integer.parseInt(f.readLine());
		for (int i = 0; i < TC; i++)
		{
			int N = Integer.parseInt(f.readLine());
			int lo = 1000000013, hi = 0;
			for (int j = 0; j < N; j++)
			{
				StringTokenizer st = new StringTokenizer(f.readLine());
				int a = Integer.parseInt(st.nextToken()), b = Integer.parseInt(st.nextToken());
				if (lo > b) lo = b;
				if (hi < a) hi = a;
			}
			out.println(Math.max(0, hi - lo));
		}
		out.close();
	}
}
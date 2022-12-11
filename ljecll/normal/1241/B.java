import java.util.*;
import java.io.*;

public class cf1241b
{
	public static void main(String[] args) throws IOException
	{
		BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter output = new PrintWriter(new BufferedOutputStream(System.out));
		int TC = Integer.parseInt(input.readLine());
		boolean[] sa = new boolean[26], sb = new boolean[26];
		while(TC-- > 0)
		{
			for (int i = 0; i < 26; i++)
			{
				sa[i] = false;
				sb[i] = false;
			}
			String s = input.readLine();
			for (int i = 0; i < s.length(); i++)
			{
				sa[s.charAt(i) - 'a'] = true;
			}
			s = input.readLine();
			for (int i = 0; i < s.length(); i++)
			{
				sb[s.charAt(i) - 'a'] = true;
			}
			boolean answer = false;
			for (int i = 0; i < 26; i++)
			{
				if (sa[i] & sb[i])
				{
					answer = true;
				}
			}
			output.println(answer ? "YES" : "NO");
		}
		output.close();
		System.exit(0);
	}
}
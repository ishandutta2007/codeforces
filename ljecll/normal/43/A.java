import java.util.*;
import java.io.*;

public class cf43a
{
	public static void main(String[] args) throws IOException
	{
		BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter output = new PrintWriter(new BufferedOutputStream(System.out));
		int N = Integer.parseInt(input.readLine());
		HashMap<String, Integer> mp = new HashMap<>();
		for (int i = 0; i < N; i++)
		{
			String s = input.readLine();
			int x = mp.getOrDefault(s, 0);
			mp.put(s, x + 1);
		}
		String ans = "";
		for (String key : mp.keySet())
		{
			int x = mp.get(key);
			if (ans.equals("") || x > mp.get(ans))
			{
				ans = key;
			}
		}
		output.println(ans);
		output.close();
		System.exit(0);
	}
}
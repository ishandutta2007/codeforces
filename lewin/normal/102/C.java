
import java.util.*;
import java.io.*;

public class homework {
	private static BufferedReader		in;
	private static PrintWriter	out;
	
	public static void main (String [] args) throws IOException {
		in = new BufferedReader (new InputStreamReader (System.in));
		out = new PrintWriter (System.out, true);
		
		String s = in.readLine();
		int k = Integer.parseInt(in.readLine());
		int [] count = new int [26];
		for (char c : s.toCharArray())
			count [(int)(c - 'a')]++;
		int [] sub = new int [26];
		while (k > 0) {
			int min = Integer.MAX_VALUE, idx = -1;
			for (int i = 0; i < 26; i++)
				if (count [i] < min && count [i] != 0) {
					min = count [i];
					idx = i;
				}
			if (idx == -1) break;
			sub [idx] = Math.min (k, min);
			count [idx] -= sub [idx];
			k -= min;
		}
		int p = 0;
		for (int i = 0; i < 26; i++)
			if (count [i] > 0)
				p++;
		out.println (p);
		for (char c : s.toCharArray()) {
			if (sub [(int)(c - 'a')] > 0) sub [(int)(c - 'a')]--;
			else out.print (c);
		}
		out.println();
		out.close();
		System.exit(0);
	}
}

import java.util.*;
import java.io.*;

public class sumdig {
	private static BufferedReader		in;
	private static PrintWriter	out;
	
	public static void main (String [] args) throws IOException {
		in = new BufferedReader (new InputStreamReader (System.in));
		out = new PrintWriter (System.out, true);
		
		String s = in.readLine();
		int count = 0;
		while (s.length() > 1) {
			s = reduce(s);
			count++;
		}
		out.println (count);
	}
	
	private static String reduce (String s) {
		int val = 0;
		for (char c : s.toCharArray())
			val += (int)(c - '0');
		return String.valueOf (val);
	}
}
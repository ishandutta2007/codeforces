
import java.util.*;
import java.io.*;

public class C158 {
	private static BufferedReader in;
	private static PrintWriter out;

	private static String [] dir;
	
	public static void main(String[] args) throws IOException {
		in = new BufferedReader(new InputStreamReader (System.in));
		out = new PrintWriter(System.out, true);
		
		dir = new String [100000];
		int back = 0;
		int T = Integer.parseInt (in.readLine ());
		StringTokenizer st;
		while (T-- > 0) {
			st = new StringTokenizer (in.readLine ());
			String cmd = st.nextToken ();
			if (cmd.equals ("pwd")) {
				for (int i = 0; i < back; i++)
					out.print ("/" + dir [i]);
				out.println("/");
			} else {
				String s = st.nextToken ();
				if (s.charAt(0) == '/') {
					back = 0;
					s = s.substring (1);
				}
				String [] cmds = s.split ("/");
				for (int i = 0; i < cmds.length; i++) {
					if (cmds [i].equals(".."))
						back--;
					else 
						dir[back++] = cmds [i];
				}
			}
		}
		
		out.close();
		System.exit(0);
	}
}
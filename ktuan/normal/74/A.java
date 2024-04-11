import java.io.*;
import java.util.*;
import java.math.*;

public class BaiA implements Runnable {
	
	public void run() {
		int n = nextInt();
		int best = -1000000000;
		String lead = "";
		for(int i=0;i<n;++i) {
			String name = nextStr();
			int pl = nextInt();
			int mi = nextInt();
			int total = 0;
			for(int j=0;j<5;++j)
				total += nextInt();
			total += 100 * pl;
			total -= 50 * mi;
			if(best < total) {
				best = total;
				lead = name;
			}
		}
		System.out.println(lead);
	}
	
	BufferedReader keyboard = new BufferedReader(new InputStreamReader(System.in));
	StringTokenizer strtok = null;
	
	String nextStr() {
		try {
			while(strtok == null || !strtok.hasMoreTokens())
				strtok = new StringTokenizer(keyboard.readLine());
			return strtok.nextToken();
		}
		catch(Exception ex) {
			System.out.println(ex.getMessage());
			ex.printStackTrace();
			return null;
		}
	}
	
	int nextInt() {
		return Integer.parseInt(nextStr());
	}
	
	long nextLong() {
		return Long.parseLong(nextStr());
	}
	
	double nextDouble() {
		return Double.parseDouble(nextStr());
	}
	
	public static void main(String[] args) {
		new BaiA().run();
	}
}
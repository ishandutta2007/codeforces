import java.io.*;
import java.util.*;
import java.math.*;

public class BaiA implements Runnable {
	
	boolean check(int i) {
		for(int j=2;j*j<=i;++j)
			if(i%j==0)return false;
		return true;
	}
	
	public void run() {
		int n = nextInt();
		int m = nextInt();
		for(int i=n+1;i<m;++i) if(check(i)) {
			System.out.println("NO");
			return;
		}
		if(!check(m)) System.out.println("NO");
		else System.out.println("YES");
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
import java.io.*;
import java.util.*;
import java.math.*;

public class BaiB implements Runnable {
	
	public void run() {
		int m = nextInt();
		int n = nextInt();
		int k = nextInt();
		int t = nextInt();
		int[] x = new int[k];
		int[] y = new int[k];
		for(int i=0;i<k;++i)
		{
			x[i] = nextInt() - 1;
			y[i] = nextInt() - 1;
		}
		String[] name = {"Carrots", "Kiwis", "Grapes"};
		for(int i=0;i<t;++i) {
			int u = nextInt() - 1;
			int v = nextInt() - 1;
			boolean found = false;
			int nh = 0;
			for(int j=0;j<k;++j) {
				if(u == x[j] && v == y[j]) {
					found = true;
				}
				else if(x[j] < u || (u == x[j] && y[j] < v))
					++nh;
			}
			if(found)
				System.out.println("Waste");
			else {
				int z = u * n + v;
				// System.out.println(z + " " + nh);
				z -= nh;
				System.out.println(name[z % 3]);
			}
		}
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
		new BaiB().run();
	}
}
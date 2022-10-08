import java.io.*;
import java.util.*;
import java.math.*;

public class BaiB implements Runnable {
	
	int n, m, k;
	int d;
	char[] a;
	int[][][][] F;
	boolean[][][][] dt;
	
	int solve(int pos, int sto, int con, int dir) {
		if(pos == a.length) return a.length;
		if(dt[pos][sto][con][dir+1])
			return F[pos][sto][con][dir+1];
		dt[pos][sto][con][dir+1] = true;
		int res = -1;
		if(a[pos] == '0') { // move
			for(int z=-1;z<=1;++z) {
				if(0 <= sto + z && sto + z < n) {
					int nsto = sto + z;
					int ncon = con;
					int ndir = dir;
					if(nsto == ncon) res = Math.max(res, pos);
					else {
						if(ncon + ndir < 0 || ncon + ndir >= n) {
							ndir = -ndir;
						}
						ncon += ndir;
						if(nsto == ncon) res = Math.max(res, pos);
						else res = Math.max( res, solve(pos + 1, nsto, ncon, ndir));
					}
				}
			}
		}
		else { // idle
			for(int nsto = 0; nsto < n; ++nsto) {
				int ncon = con;
				int ndir = dir;
				if(ncon + ndir < 0 || ncon + ndir >= n) {
					ndir = -ndir;
				}
				ncon += ndir;
				if(nsto == ncon) res = Math.max( res, pos);
				else res = Math.max( res, solve(pos + 1, nsto, ncon, ndir));
			}
		}
		F[pos][sto][con][dir+1] = res;
		return res;
	}
	
	public void run() {
		n = nextInt();
		m = nextInt();
		k = nextInt();
		String s = nextStr();
		s = nextStr();
		if(s.equals("head")) d = -1;
		else d = 1;
		a = nextStr().toCharArray();
		F = new int[a.length][n][n][3];
		dt = new boolean[a.length][n][n][3];
		int res = solve(0, m-1, k-1, d);
		if(res == a.length)
			System.out.println("Stowaway");
		else
			System.out.println("Controller " + (res + 1));
		
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
import java.io.*;
import java.util.*;

public class D_fast {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;
	
	int n, main, neigh;
	
	int[] curAdd;
	int[] bestAdd;
	int bestAddVal = Integer.MAX_VALUE;
	int curAddVal = 0;
	int[] hp;
	
	void go(int cnt) {
		if (cnt == n - 1) {
			if (hp[n - 2] < 0 && curAddVal < bestAddVal) {
				bestAddVal = curAddVal;
				bestAdd = curAdd.clone();
			}
			return;
		}
		
		int initHPPrev = hp[cnt - 1];
		int initHP = hp[cnt];
		int initHPNext = hp[cnt + 1];
		int initAddVal = curAddVal;
		
		if (cnt != 1 && hp[cnt - 1] >= 0)
			curAdd[cnt] = hp[cnt - 1] / neigh + 1;
		
		
		curAddVal += curAdd[cnt];
		hp[cnt] -= curAdd[cnt] * main;
		hp[cnt + 1] -= curAdd[cnt] * neigh;
		
		while (true) {
			go(cnt + 1);
			if (hp[cnt] < 0 && (cnt == n - 2 || hp[cnt + 1] < 0))
				break;
			hp[cnt] -= main;
			hp[cnt + 1] -= neigh;
			curAdd[cnt]++;
			curAddVal++;
		}
		
		hp[cnt - 1] = initHPPrev;
		hp[cnt] = initHP;
		hp[cnt + 1] = initHPNext;
		curAdd[cnt] = 0;
		curAddVal = initAddVal;
	}

	void solve() throws IOException {
		n = nextInt();
		main = nextInt();
		neigh = nextInt();
		
		hp = new int[n];
		for (int i = 0; i < n; i++)
			hp[i] = nextInt();
		
		int[] ans = new int[n];
		
		int cnt = hp[0] / neigh + 1;
		ans[1] += cnt;
		hp[0] -= cnt * neigh;
		hp[1] -= cnt * main;
		hp[2] -= cnt * neigh;
		
		if (hp[n - 1] >= 0) {
			cnt = hp[n - 1] / neigh + 1;
			ans[n - 2] += cnt;
			hp[n - 3] -= cnt * neigh;
			hp[n - 2] -= cnt * main;
			hp[n - 1] -= cnt * neigh;
		}
		
		curAdd = new int[n - 1];
		go(1);
		for (int i = 1; i < n - 1; i++)
			ans[i] += bestAdd[i];
		
		int res = 0;
		for (int i = 1; i < n - 1; i++)
			res += ans[i];
		out.println(res);
		for (int i = 1; i < n - 1; i++) {
			for (int j = 0; j < ans[i]; j++)
				out.print((i + 1) + " ");
		}
		out.println();
	}

	void inp() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new D_fast().inp();
	}

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (Exception e) {
				eof = true;
				return null;
			}
		}
		return st.nextToken();
	}

	String nextString() {
		try {
			return br.readLine();
		} catch (IOException e) {
			eof = true;
			return null;
		}
	}

	int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}
}
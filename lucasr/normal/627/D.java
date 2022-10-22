import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class D {
	static int[][] children;
	static int[] vals, min, tot;
	
	static void fill(int from, int node, List<List<Integer>> adj) {
		List<Integer> vec = adj.get(node);
		children[node] = new int[vec.size() - (from == -1 ? 0 : 1)];
		min[node] = vals[node];
		tot[node] = 1;
		int idx = 0;
		for (Integer nei : vec) {
			if (nei != from) {
				children[node][idx++] = nei;
				fill(node, nei, adj);
				min[node] = Math.min(min[node], min[nei]);
				tot[node] += tot[nei];
			}
		}
	}
	
	static int[][] best;
	static int minVal;
	static int maxElems(int node, int mustHaveRoot) {
		if (best[node][mustHaveRoot] != -1) return best[node][mustHaveRoot];
		int ret = 0;
		int[] cc = children[node];
		if (mustHaveRoot == 1) {
			if (vals[node] >= minVal) {
				ret = 1;
				int maxOther = 0;
				for (int i = 0; i < cc.length; i++) {
					if (min[cc[i]] >= minVal) ret += tot[cc[i]];
					else maxOther = Math.max(maxOther, maxElems(cc[i], 1));
				}
				ret += maxOther;
			}
		} else {
			if (mustHaveRoot == 0) {
				for (int i = 0; i < cc.length; i++) {
					ret = Math.max(ret, maxElems(cc[i], 0));
				}
			}
			if (vals[node] >= minVal) {
				int ret2 = 1;
				int maxOtherA = 0, maxOtherB = 0;
				int maxAIdx = -1, totBad = 0;
				for (int i = 0; i < cc.length; i++) {
					if (min[cc[i]] >= minVal) ret2 += tot[cc[i]];
					else {
						totBad++;
						int val = maxElems(cc[i], 1);
						if (val > maxOtherA) {
							maxOtherB = maxOtherA;
							maxOtherA = val;
							maxAIdx = i;
						} else if (val > maxOtherB) {
							maxOtherB = val;
						}
					}
				}
				if (totBad == 1 && maxAIdx != -1) {
					ret2 += maxElems(cc[maxAIdx], 2);
				} else {
					ret2 += maxOtherA + maxOtherB;
				}
				ret = Math.max(ret, ret2);
			}
		}
		
		return best[node][mustHaveRoot] = ret;
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int k = sc.nextInt();
		List<List<Integer>> adj = new ArrayList<List<Integer>>(n);
		for (int i = 0; i < n; i++) {
			adj.add(new ArrayList<Integer>());
		}
		vals = new int[n];
		for (int i = 0; i < vals.length; i++) {
			vals[i] = sc.nextInt();
		} 
		for (int i = 0; i < n-1; i++) {
			int a = sc.nextInt() - 1;
			int b = sc.nextInt() - 1;
			adj.get(a).add(b);
			adj.get(b).add(a);
		}
		children = new int[n][];
		min = new int[n];
		tot = new int[n];
		fill(-1, 0, adj);
		
		List<Integer> vals2 = new ArrayList<Integer>(n);
		for (int i = 0; i < vals.length; i++) {
			vals2.add(vals[i]);
		}
		Collections.sort(vals2);
		best = new int[n][3];
		int left = 0, right = n;
		while (left + 1 < right) {
			int med = (left + right) / 2;
			minVal = vals2.get(med);
			for (int i = 0; i < best.length; i++) {
				best[i][0] = best[i][1] = best[i][2] = -1 ;
			}
			if (maxElems(0, 0) >= k) left = med;
			else right = med;
		}
		System.out.println(vals2.get(left));
	}
}
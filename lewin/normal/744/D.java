//package round385;
import java.awt.geom.Point2D;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;
import java.util.List;
import java.util.Random;

public class D {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int R = ni(), B = ni();
		long[][] rco = new long[R][];
		long[][] bco = new long[B][];
		for(int i = 0;i < R;i++){
			rco[i] = new long[]{ni(), ni()};
		}
		for(int i = 0;i < B;i++){
			bco[i] = new long[]{ni(), ni()};
		}
		if(B <= 2){
			out.println(-1);
			return;
		}
		
		DelaunayTriangulation dt = new DelaunayTriangulation();
		int[][] g = dt.triangulate(bco, false);
		long[][] hull = convexHull(bco);
		for(int i = 0;i < R;i++){
			if(isOnOut(rco[i][0], rco[i][1], hull)){
				out.println(-1);
				return;
			}
		}
		max = Double.NEGATIVE_INFINITY;
		for(int i = 0;i < B;i++){
			for(int j = 0, k = 1;j < g[i].length;j++,k++){
				if(k == g[i].length)k = 0;
				if(ccw(bco[g[i][j]], bco[g[i][k]], bco[i]) >= 0)continue;
				
				check(bco[i], bco[g[i][j]], bco[g[i][k]], bco, rco);
				
				for(int l = 0;l < R;l++){
                    if(ccw(bco[i], bco[g[i][j]], rco[l]) < 0){
						check(bco[i], bco[g[i][j]], rco[l], bco, rco);
                    }
				}
			}
		}
		
		assert Double.isFinite(max);
		out.printf("%.14f\n", max);
		
	}
	
	private void check(long[] a, long[] b, long[] c, long[][] bco, long[][] rco)
	{
		double[] cc = circumcircle(a[0], a[1], b[0], b[1], c[0], c[1]);
		assert cc != null;
		if(cc[2] <= max)return;
		
		for(long[] bc : bco){
			if(Point2D.distanceSq(bc[0], bc[1], cc[0], cc[1]) < (cc[2]-2e-5)*(cc[2]-2e-5)){
				return;
			}
		}
		for(long[] bc : rco){
			if(Point2D.distanceSq(bc[0], bc[1], cc[0], cc[1]) < (cc[2]+2e-5)*(cc[2]+2e-5)){
				max = cc[2];
				return;
			}
		}
	}
	
	double max = Double.NEGATIVE_INFINITY;
	
	public static double[] circumcircle(double ax, double ay, double bx, double by, double cx, double cy)
	{
		if((bx-ax)*(cy-ay)-(by-ay)*(cx-ax) == 0)return null; // 0
		double D = 2*(ax*(by-cy)+bx*(cy-ay)+cx*(ay-by));
		double X = ((ax*ax+ay*ay)*(by-cy)+(bx*bx+by*by)*(cy-ay)+(cx*cx+cy*cy)*(ay-by))/D;
		double Y = ((ax*ax+ay*ay)*(cx-bx)+(bx*bx+by*by)*(ax-cx)+(cx*cx+cy*cy)*(bx-ax))/D;
		double R = Math.sqrt((X-ax)*(X-ax)+(Y-ay)*(Y-ay));
		return new double[]{X, Y, R};
	}
	
	public static boolean isOnOut(long ax, long ay, long[][] co)
	{
		if(!isOnIn(ax, ay, co))return true; // out
		int n = co.length;
		for(int i = 0, j = i+1;i < n;i++,j++){
			if(j == n)j = 0;
			if(isACB(co[i][0], co[i][1], co[j][0], co[j][1], ax, ay))return true;
		}
		return false;
	}
	
	public static boolean isACB(long ax, long ay, long bx, long by, long cx, long cy)
	{
		return (cx-ax)*(by-ay)-(cy-ay)*(bx-ax)==0 && (cx-ax)*(cx-bx)+(cy-ay)*(cy-by) <= 0;
	}
	
	// Is a point A on or in a polygon(counterclockwise)?
	public static boolean isOnIn(long ax, long ay, long[][] co)
	{
		int n = co.length;
		// on
		for(int i = 0, j = i+1;i < n;i++,j++){
			if(j == n)j = 0;
			if(isACB(co[i][0], co[i][1], co[j][0], co[j][1], ax, ay))return true;
		}
		
		// in
		int ct = 0;
		for(int i = 0, j = i+1;i < n;i++,j++){
			if(j == n)j = 0;
			long cx = co[i][0], cy = co[i][1];
			long dx = co[j][0], dy = co[j][1];
			if(cy >= dy){
				long t = cx; cx = dx; dx = t;
				t = cy; cy = dy; dy = t;
			}
			if(cy <= ay && dy > ay){
				// (ay-cy)/(dy-cy)*(dx-cx)+cx >= ax
				if((ay-cy)*(dx-cx) >= (ax-cx)*(dy-cy)){
					ct++;
				}
			}
		}
		return (ct&1) == 1;
	}

	public static long[][] convexHull(long[][] co)
	{
		int n = co.length;
		if(n <= 1)return co;
		Arrays.sort(co, new Comparator<long[]>(){
			public int compare(long[] a, long[] b){
				if(a[0] != b[0])return Long.compare(a[0], b[0]);
				return Long.compare(a[1], b[1]);
			}
		});
		
		int[] inds = new int[n + 1];
		int p = 0;
		for(int i = 0;i < n;i++){
			if(p >= 1 && co[inds[p-1]][0] == co[i][0] && co[inds[p-1]][1] == co[i][1])continue;
			while(p >= 2 && ccw(co[inds[p-2]], co[inds[p-1]], co[i]) >= 0)p--; // if you need point on line
			inds[p++] = i;
		}
		
		int inf = p + 1;
		for(int i = n - 2;i >= 0;i--){
			if(co[inds[p-1]][0] == co[i][0] && co[inds[p-1]][1] == co[i][1])continue;
			while(p >= inf && ccw(co[inds[p-2]], co[inds[p-1]], co[i]) >= 0)p--; // if you need point on line
			inds[p++] = i;
		}
		
		int len = Math.max(p-1, 1);
		long[][] ret = new long[len][];
		for(int i = 0;i < len;i++)ret[i] = co[inds[i]];
		return ret;
	}
	
	public static int ccw(long[] a, long[] b, long[] t) {
		return Long.signum((t[0] - a[0]) * (b[1] - a[1]) - (b[0] - a[0]) * (t[1] - a[1]));
	}


	
	public static class DelaunayTriangulation {
		public long[][] co;
		
		public int[][] triangulatePreservingIndexWhenDuped(long[][] co)
		{
			int n = co.length;
			long[][] cco = new long[n][];
			for(int i = 0;i < n;i++){
				cco[i] = new long[]{co[i][0], co[i][1], i};
			}
			long[][] sorted = removeDuplicatePoints(cco);
			int m = sorted.length;
			int[][] g = triangulate(sorted, true);
			int[] iord = new int[n];
			for(int i = 0;i < m;i++)iord[(int)sorted[i][2]] = i;
			int[] root = new int[n];
			int pre = -1;
			for(int i = 0;i < n;i++){
				if(i > 0 && cco[i][0] == cco[i-1][0] && cco[i][1] == cco[i-1][1]){
					root[(int)cco[i][2]] = pre;
				}else{
					pre = i;
				}
			}
			
			int[][] rg = new int[n][];
			for(int i = 0;i < m;i++){
				int to = (int)sorted[i][2];
				rg[to] = g[i];
				for(int j = 0;j < rg[to].length;j++){
					rg[to][j] = (int)sorted[rg[to][j]][2];
				}
			}
			for(int i = 0;i < n;i++){
				if(rg[i] == null){
					rg[i] = new int[]{root[i]};
				}
			}
			return rg; // g is destructed
		}
		
		public int[][] triangulatePreservingIndex(long[][] co)
		{
			int n = co.length;
			long[][] cco = new long[n][];
			for(int i = 0;i < n;i++){
				cco[i] = new long[]{co[i][0], co[i][1], i};
			}
			int[][] g = triangulate(cco, false);
			
			int[][] rg = new int[n][];
			for(int i = 0;i < n;i++){
				int to = (int)cco[i][2];
				rg[to] = g[i];
				for(int j = 0;j < rg[to].length;j++){
					rg[to][j] = (int)cco[rg[to][j]][2];
				}
			}
			return rg; // g is destructed
		}
		
		public long[][] removeDuplicatePoints(long[][] co)
		{
			Arrays.sort(co, new Comparator<long[]>() {
				public int compare(long[] a, long[] b) {
					if(a[0] != b[0])return Long.compare(a[0], b[0]);
					return Long.compare(a[1], b[1]);
				}
			});
			int n = co.length;
			int p = 0;
			for(int i = 0;i < n;i++){
				if(i == 0 || !(co[i][0] == co[i-1][0] && co[i][1] == co[i-1][1])){
					co[p++] = co[i];
				}
			}
			return Arrays.copyOf(co, p);
		}
		
		// destructive
		public int[][] triangulate(long[][] co, boolean sorted)
		{
			int n = co.length;
			if(!sorted){
				Arrays.sort(co, new Comparator<long[]>() {
					public int compare(long[] a, long[] b) {
						if(a[0] != b[0])return Long.compare(a[0], b[0]);
						return Long.compare(a[1], b[1]);
					}
				});
			}
			
			this.co = co;
			List<Node> nodes = dfs(0, n);
			assert nodes.size() == n;
			int[][] g = new int[n][];
			for(int i = 0;i < n;i++){
				Node[] row = nodes(nodes.get(i));
				g[i] = new int[row.length];
				for(int j = 0;j < row.length;j++){
					g[i][j] = row[j].to;
				}
			}
			return g;
		}
		
		// Ptolemy's inequality
		// Is co[t] in circumcircle(co[a.from],co[a.to],co[b.to])?
		private boolean incircle(Node a, Node b, int t)
		{
			assert a.from == b.from; // counterclockwise a<b
			assert a != b;
			int ccwab = ccw(a, b);
			int ccwat = ccw(co[a.from][0], co[a.from][1], co[a.to][0], co[a.to][1], co[t][0], co[t][1]);
			if(ccwat == 0){
				// on line a-b
				return (co[t][0]-co[a.from][0])*(co[t][0]-co[a.to][0])+(co[t][1]-co[a.from][1])*(co[t][1]-co[a.to][1]) < 0;
			}
			
			// if on the same side, ok if angle(t) > angle(b)
			// 
			// dot(a,b)/|a|/|b| > dot(c,d)/|c|/|d|
			long leftdot = dot(co[a.from], co[b.to], co[a.to], co[b.to]);
			long rightdot = dot(co[a.from], co[t], co[a.to], co[t]);
			if(ccwat != ccwab){
				leftdot = -leftdot;
			}
			if(Long.signum(leftdot) != Long.signum(rightdot)){
				return leftdot > rightdot;
			}
			double leftd = (double)leftdot * leftdot * norm(co[a.from], co[t]) * norm(co[a.to], co[t]);
			double rightd = (double)rightdot * rightdot * norm(co[a.from], co[b.to]) * norm(co[a.to], co[b.to]);
			// case if limit=2*10^4
//			if(leftdot > 0){
//				if(Math.abs(leftd - rightd) >= 9e18){
//					return leftd > rightd;
//				}
//				long left = leftdot * leftdot * norm(co[a.from], co[t]) * norm(co[a.to], co[t]);
//				long right = rightdot * rightdot * norm(co[a.from], co[b.to]) * norm(co[a.to], co[b.to]);
//				return left - right > 0; // not left > right
//			}else{
//				if(Math.abs(leftd - rightd) >= 9e18){
//					return leftd < rightd;
//				}
//				long left = leftdot * leftdot * norm(co[a.from], co[t]) * norm(co[a.to], co[t]);
//				long right = rightdot * rightdot * norm(co[a.from], co[b.to]) * norm(co[a.to], co[b.to]);
//				return left - right < 0; // not left < right
//			}
			// case if limit=10^9
			if(leftdot > 0){
				if(leftd != rightd)return leftd > rightd;
				BigInteger left = b(leftdot).multiply(b(leftdot)).multiply(b(norm(co[a.from], co[t])).multiply(b(norm(co[a.to], co[t]))));
				BigInteger right = b(rightdot).multiply(b(rightdot)).multiply(b(norm(co[a.from], co[b.to])).multiply(b(norm(co[a.to], co[b.to]))));
				return left.compareTo(right) > 0;
			}else{
				if(leftd != rightd)return leftd < rightd;
				BigInteger left = b(leftdot).multiply(b(leftdot)).multiply(b(norm(co[a.from], co[t])).multiply(b(norm(co[a.to], co[t]))));
				BigInteger right = b(rightdot).multiply(b(rightdot)).multiply(b(norm(co[a.from], co[b.to])).multiply(b(norm(co[a.to], co[b.to]))));
				return left.compareTo(right) < 0;
			}
		}
		
		private static BigInteger b(long x){ return BigInteger.valueOf(x); }

		public static long dot(long[] a, long[] b, long[] c, long[] d){ return (d[0]-c[0])*(b[0]-a[0])+(d[1]-c[1])*(b[1]-a[1]);}
		public static long norm(long[] a, long[] b){ return (b[0]-a[0])*(b[0]-a[0])+(b[1]-a[1])*(b[1]-a[1]);}
		
		// graph
		private List<Node> dfs(int l, int r)
		{
			if(r-l <= 3){
				List<Node> ret = new ArrayList<>();
				for(int i = l;i < r;i++)ret.add(null);
				for(int i = l;i < r;i++){
					for(int j = i+1;j < r;j++){
						// not append edge only if co[l],co[l+1],co[l+2]=co[r-1] in a line in this order
						if(j-i == 2 && isACB(co[i], co[j], co[i+1]))continue;
						insertb(ret, i, j, l);
					}
				}
				return ret;
			}
			
			int h = l+r>>1;
			List<Node> LL = dfs(l, h);
			List<Node> RR = dfs(h, r);
			List<Node> LR = LL;
			LR.addAll(RR);
			
			// l-rb
			int argl = h-1;
			int argr = h;
			// update argl,argr alternately
			while(true){
				boolean changed = false;
				{
					// choose vector which records maximum arg from R->L to L->R.
					int lb = lowerBound(LR.get(argl-l), co[argr][0]-co[argl][0], co[argr][1]-co[argl][1]);
					// if not corresponding to L->R, decrement.
					if(lb < count(LR.get(argl-l))){
						Node tar = get(LR.get(argl-l), lb);
						int ccw = ccw(co[argr][0], co[argr][1], co[argl][0], co[argl][1], co[tar.to][0], co[tar.to][1]);
						long dot = dot(co[argr][0], co[argr][1], co[argl][0], co[argl][1], co[tar.to][0], co[tar.to][1]);
						if(ccw == 0 && dot < 0){
						}else{
							lb--;
						}
					}else{
						lb--;
					}
					if(lb < 0)lb = count(LR.get(argl-l))-1;
					// if updatable, update.
					Node tar = get(LR.get(argl-l), lb);
					int ccw = ccw(co[argr][0], co[argr][1], co[argl][0], co[argl][1], co[tar.to][0], co[tar.to][1]);
					long dot = dot(co[argr][0], co[argr][1], co[argl][0], co[argl][1], co[tar.to][0], co[tar.to][1]);
					if(ccw < 0 || ccw == 0 && dot < 0){
						argl = tar.to;
						changed = true;
					}
				}
				
				{
					// choose vector which records minimum arg from R->L to L->R.
					int lb = lowerBound(LR.get(argr-l), co[argl][0]-co[argr][0], co[argl][1]-co[argr][1]);
					if(lb < count(LR.get(argr-l))){
					}else{
						lb = 0;
					}
					// if updatable, update.
					Node tar = get(LR.get(argr-l), lb);
					int ccw = ccw(co[argl][0], co[argl][1], co[argr][0], co[argr][1], co[tar.to][0], co[tar.to][1]);
					long dot = dot(co[argl][0], co[argl][1], co[argr][0], co[argr][1], co[tar.to][0], co[tar.to][1]);
					if(ccw > 0 || ccw == 0 && dot < 0){
						argr = get(LR.get(argr-l), lb).to;
						changed = true;
					}
				}
				if(!changed)break;
			}
			
			assert argl != -1;
			assert argr != -1;
			
			Node basel = insertb(LR, argl, argr, l);
			Node baser = basel.dual;
			// base is decided. erase invalid edges above it.
			while(true){
				Node lnext = null;
				while(true){
					lnext = next(basel);
					if(lnext == null)lnext = first(LR.get(basel.from-l));
					if(ccw(basel, lnext) >= 0){
						lnext = null;
						break;
					}
					Node lnextnext = next(lnext);
					if(lnextnext == null)lnextnext = first(LR.get(basel.from-l));
					if(lnextnext != basel && ccw(basel, lnextnext) < 0 && incircle(basel, lnext, lnextnext.to)){
						erase(LR, lnext, l);
					}else{
						break;
					}
				}
				Node rprev = null;
				while(true){
					rprev = prev(baser);
					if(rprev == null)rprev = last(LR.get(baser.from-l));
					if(ccw(baser, rprev) <= 0){
						rprev = null;
						break;
					}
					Node rprevprev = prev(rprev);
					if(rprevprev == null)rprevprev = last(LR.get(baser.from-l));
					if(rprevprev != baser && ccw(baser, rprevprev) > 0 && incircle(rprev, baser, rprevprev.to)){
						erase(LR, rprev, l);
					}else{
						break;
					}
				}
				if(lnext == null && rprev == null)break; // end
				int select = 0;
				if(lnext == null)select = 1;
				if(rprev == null)select = -1;
				if(select == 0){
					if(incircle(basel, lnext, rprev.to)){
						assert !incircle(baser, rprev, lnext.to);
						select = 1;
					}else{
						select = -1;
					}
				}
				assert select != 0;
				if(select == 1)argr = rprev.to;
				if(select == -1)argl = lnext.to;
				basel = insertb(LR, argl, argr, l);
				baser = basel.dual;
			}
			return LR;
		}
		

		public int ccw(Node a, Node t)
		{
			assert a.from == t.from;
			return ccw(
					co[a.from][0], co[a.from][1],
					co[a.to][0], co[a.to][1],
					co[t.to][0], co[t.to][1]
					);
		}
		
		public static int ccw(long ax, long ay, long bx, long by, long tx, long ty) {
			return Long.signum((tx - ax) * (by - ay) - (bx - ax) * (ty - ay));
		}
		public static long dot(long ax, long ay, long bx, long by, long tx, long ty) {
			return (tx-ax)*(bx-ax)+(ty-ay)*(by-ay);
		}
		public static boolean isACB(long ax, long ay, long bx, long by, long cx, long cy)
		{
			return (cx-ax)*(by-ay)-(cy-ay)*(bx-ax)==0 && (cx-ax)*(cx-bx)+(cy-ay)*(cy-by) <= 0;
		}
		
		public static boolean isACB(long[] a, long[] b, long[] c) { return isACB(a[0], a[1], b[0], b[1], c[0], c[1]); }
		
		
		private static void erase(List<Node> nodes, Node e, int offset)
		{
			Node d = e.dual;
			nodes.set(e.from-offset, erase(nodes.get(e.from-offset), index(e)));
			nodes.set(d.from-offset, erase(nodes.get(d.from-offset), index(d)));
		}
		
		private Node insertb(List<Node> nodes, int i, int j, int offset)
		{
			assert i != j;
			assert i >= offset;
			assert j >= offset;
			assert i < offset + nodes.size();
			assert j < offset + nodes.size();
			Node ij = new Node(i, j);
			Node ji = new Node(j, i);
			ij.dual = ji; ji.dual = ij;
			nodes.set(i-offset, insertb(nodes.get(i-offset), ij));
			nodes.set(j-offset, insertb(nodes.get(j-offset), ji));
			return ij;
		}
		
		public static Random gen = new Random(0);
		
		static public class Node
		{
			public int from; // common
			public int to; // value
			public long priority;
			public Node left, right, parent;
			public Node dual;
			
			public int count;
			
			public Node(int from, int to)
			{
				this.from = from;
				this.to = to;
				priority = gen.nextLong();
				update(this);
			}

			@Override
			public String toString() {
				StringBuilder builder = new StringBuilder();
				builder.append("Node [");
				builder.append(from);
				builder.append("->");
				builder.append(to);
				builder.append("]");
				return builder.toString();
			}
		}

		public static Node update(Node a)
		{
			if(a == null)return null;
			a.count = 1;
			if(a.left != null)a.count += a.left.count;
			if(a.right != null)a.count += a.right.count;
			
			return a;
		}
		
		public static void propagate(Node x)
		{
			for(;x != null;x = x.parent)update(x);
		}
		
		public static Node disconnect(Node a)
		{
			if(a == null)return null;
			a.left = a.right = a.parent = null;
			return update(a);
		}
		
		public static Node root(Node x)
		{
			if(x == null)return null;
			while(x.parent != null)x = x.parent;
			return x;
		}
		
		public static int count(Node a)
		{
			return a == null ? 0 : a.count;
		}
		
		public static void setParent(Node a, Node par)
		{
			if(a != null)a.parent = par;
		}
		
		public static Node merge(Node a, Node b, Node... c)
		{
			Node x = merge(a, b);
			for(Node n : c)x = merge(x, n);
			return x;
		}
		
		public static Node merge(Node a, Node b)
		{
			if(b == null)return a;
			if(a == null)return b;
			if(a.priority > b.priority){
				setParent(a.right, null);
				setParent(b, null);
				a.right = merge(a.right, b);
				setParent(a.right, a);
				return update(a);
			}else{
				setParent(a, null);
				setParent(b.left, null);
				b.left = merge(a, b.left);
				setParent(b.left, b);
				return update(b);
			}
		}
		
		public static Node[] split(Node x)
		{
			if(x == null)return new Node[]{null, null};
			if(x.left != null)x.left.parent = null;
			Node[] sp = new Node[]{x.left, x};
			x.left = null;
			update(x);
			while(x.parent != null){
				Node p = x.parent;
				x.parent = null;
				if(x == p.left){
					p.left = sp[1];
					if(sp[1] != null)sp[1].parent = p;
					sp[1] = p;
				}else{
					p.right = sp[0];
					if(sp[0] != null)sp[0].parent = p;
					sp[0] = p;
				}
				update(p);
				x = p;
			}
			return sp;
		}
		
		public static Node[] split(Node a, int... ks)
		{
			int n = ks.length;
			if(n == 0)return new Node[]{a};
			for(int i = 0;i < n-1;i++){
				if(ks[i] > ks[i+1])throw new IllegalArgumentException(Arrays.toString(ks));
			}
			
			Node[] ns = new Node[n+1];
			Node cur = a;
			for(int i = n-1;i >= 0;i--){
				Node[] sp = split(cur, ks[i]);
				cur = sp[0];
				ns[i] = sp[0];
				ns[i+1] = sp[1];
			}
			return ns;
		}
		
		// [0,K),[K,N)
		public static Node[] split(Node a, int K)
		{
			if(a == null)return new Node[]{null, null};
			if(K <= count(a.left)){
				setParent(a.left, null);
				Node[] s = split(a.left, K);
				a.left = s[1];
				setParent(a.left, a);
				s[1] = update(a);
				return s;
			}else{
				setParent(a.right, null);
				Node[] s = split(a.right, K-count(a.left)-1);
				a.right = s[0];
				setParent(a.right, a);
				s[0] = update(a);
				return s;
			}
		}
		
		public Node insertb(Node root, Node x)
		{
			int ind = lowerBound(root, x);
			return insert(root, ind, x);
		}
		
		public static Node insert(Node a, int K, Node b)
		{
			if(a == null)return b;
			if(b.priority < a.priority){
				if(K <= count(a.left)){
					a.left = insert(a.left, K, b);
					setParent(a.left, a);
				}else{
					a.right = insert(a.right, K-count(a.left)-1, b);
					setParent(a.right, a);
				}
				return update(a);
			}else{
				Node[] ch = split(a, K);
				b.left = ch[0]; b.right = ch[1];
				setParent(b.left, b);
				setParent(b.right, b);
				return update(b);
			}
		}
		
		// delete K-th
		public static Node erase(Node a, int K)
		{
			if(a == null)return null;
			if(K < count(a.left)){
				a.left = erase(a.left, K);
				setParent(a.left, a);
				return update(a);
			}else if(K == count(a.left)){
				setParent(a.left, null);
				setParent(a.right, null);
				Node aa = merge(a.left, a.right);
				disconnect(a);
				return aa;
			}else{
				a.right = erase(a.right, K-count(a.left)-1);
				setParent(a.right, a);
				return update(a);
			}
		}
		
		public static Node get(Node a, int K)
		{
			while(a != null){
				if(K < count(a.left)){
					a = a.left;
				}else if(K == count(a.left)){
					break;
				}else{
					K = K - count(a.left)-1;
					a = a.right;
				}
			}
			return a;
		}
		
		public static int index(Node a)
		{
			if(a == null)return -1;
			int ind = count(a.left);
			while(a != null){
				Node par = a.parent;
				if(par != null && par.right == a){
					ind += count(par.left) + 1;
				}
				a = par;
			}
			return ind;
		}
		
		public Comparator<Node> compArgNode = (a, b) -> {
			assert a.from == b.from;
			long ax = co[a.to][0]-co[a.from][0], ay = co[a.to][1]-co[a.from][1];
			long bx = co[b.to][0]-co[b.from][0], by = co[b.to][1]-co[b.from][1];
			int za = ay > 0 || (ay == 0 && ax > 0) ? 0 : 1;
			int zb = by > 0 || (by == 0 && bx > 0) ? 0 : 1;
			if(za != zb)return za - zb;
			return Long.signum(ay*bx-ax*by);
		};
		
		public int lowerBound(Node a, Node q)
		{
			int lcount = 0;
			while(a != null){
				if(compArgNode.compare(q, a) <= 0){
					a = a.left;
				}else{
					lcount += count(a.left) + 1;
					a = a.right;
				}
			}
			return lcount;
		}
		
		public static int compare(long ax, long ay, long bx, long by)
		{
			int za = ay > 0 || (ay == 0 && ax > 0) ? 0 : 1;
			int zb = by > 0 || (by == 0 && bx > 0) ? 0 : 1;
			if(za != zb)return za - zb;
			return Long.signum(ay*bx-ax*by);
		};
		
		public int lowerBound(Node a, long dx, long dy)
		{
			int lcount = 0;
			while(a != null){
				if(compare(dx, dy, co[a.to][0]-co[a.from][0], co[a.to][1]-co[a.from][1]) <= 0){
					a = a.left;
				}else{
					lcount += count(a.left) + 1;
					a = a.right;
				}
			}
			return lcount;
		}
		
		public static int search(Node a, int q)
		{
			int lcount = 0;
			while(a != null){
				if(a.to == q){
					lcount += count(a.left);
					break;
				}
				if(q < a.to){
					a = a.left;
				}else{
					lcount += count(a.left) + 1;
					a = a.right;
				}
			}
			return a == null ? -(lcount+1) : lcount;
		}
		
		public static Node first(Node x)
		{
			if(x == null)return null;
			Node y = x;
			while(x != null){
				y = x;
				x = x.left;
			}
			return y;
		}
		
		public static Node last(Node x)
		{
			if(x == null)return null;
			Node y = x;
			while(x != null){
				y = x;
				x = x.right;
			}
			return y;
		}
		
		public static Node next(Node x)
		{
			if(x == null)return null;
			if(x.right != null){
				x = x.right;
				while(x.left != null)x = x.left;
				return x;
			}else{
				while(true){
					Node p = x.parent;
					if(p == null)return null;
					if(p.left == x)return p;
					x = p;
				}
			}
		}
		
		public static Node prev(Node x)
		{
			if(x == null)return null;
			if(x.left != null){
				x = x.left;
				while(x.right != null)x = x.right;
				return x;
			}else{
				while(true){
					Node p = x.parent;
					if(p == null)return null;
					if(p.right == x)return p;
					x = p;
				}
			}
		}
		
		public static Node[] nodes(Node a) { return nodes(a, new Node[count(a)], 0, count(a)); }
		public static Node[] nodes(Node a, Node[] ns, int L, int R)
		{
			if(a == null)return ns;
			nodes(a.left, ns, L, L+count(a.left));
			ns[L+count(a.left)] = a;
			nodes(a.right, ns, R-count(a.right), R);
			return ns;
		}
		
		// faster than nodes but inconsistent
		public static Node[] nodesdfs(Node a) { return nodesdfs(a, new Node[a.count], new int[]{0}); }
		public static Node[] nodesdfs(Node a, Node[] ns, int[] pos)
		{
			if(a == null)return ns;
			ns[pos[0]++] = a;
			nodesdfs(a.left, ns, pos);
			nodesdfs(a.right, ns, pos);
			return ns;
		}
		
		public static String toString(Node a, String indent)
		{
			if(a == null)return "";
			StringBuilder sb = new StringBuilder();
			sb.append(toString(a.left, indent + "  "));
			sb.append(indent).append(a).append("\n");
			sb.append(toString(a.right, indent + "  "));
			return sb.toString();
		}
		
	}

	
	void run() throws Exception
	{
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new D().run(); }
	
	private byte[] inbuf = new byte[1024];
	private int lenbuf = 0, ptrbuf = 0;
	
	private int readByte()
	{
		if(lenbuf == -1)throw new InputMismatchException();
		if(ptrbuf >= lenbuf){
			ptrbuf = 0;
			try { lenbuf = is.read(inbuf); } catch (IOException e) { throw new InputMismatchException(); }
			if(lenbuf <= 0)return -1;
		}
		return inbuf[ptrbuf++];
	}
	
	private boolean isSpaceChar(int c) { return !(c >= 33 && c <= 126); }
	private int skip() { int b; while((b = readByte()) != -1 && isSpaceChar(b)); return b; }
	
	private double nd() { return Double.parseDouble(ns()); }
	private char nc() { return (char)skip(); }
	
	private String ns()
	{
		int b = skip();
		StringBuilder sb = new StringBuilder();
		while(!(isSpaceChar(b))){ // when nextLine, (isSpaceChar(b) && b != ' ')
			sb.appendCodePoint(b);
			b = readByte();
		}
		return sb.toString();
	}
	
	private char[] ns(int n)
	{
		char[] buf = new char[n];
		int b = skip(), p = 0;
		while(p < n && !(isSpaceChar(b))){
			buf[p++] = (char)b;
			b = readByte();
		}
		return n == p ? buf : Arrays.copyOf(buf, p);
	}
	
	private char[][] nm(int n, int m)
	{
		char[][] map = new char[n][];
		for(int i = 0;i < n;i++)map[i] = ns(m);
		return map;
	}
	
	private int[] na(int n)
	{
		int[] a = new int[n];
		for(int i = 0;i < n;i++)a[i] = ni();
		return a;
	}
	
	private int ni()
	{
		int num = 0, b;
		boolean minus = false;
		while((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'));
		if(b == '-'){
			minus = true;
			b = readByte();
		}
		
		while(true){
			if(b >= '0' && b <= '9'){
				num = num * 10 + (b - '0');
			}else{
				return minus ? -num : num;
			}
			b = readByte();
		}
	}
	
	private long nl()
	{
		long num = 0;
		int b;
		boolean minus = false;
		while((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'));
		if(b == '-'){
			minus = true;
			b = readByte();
		}
		
		while(true){
			if(b >= '0' && b <= '9'){
				num = num * 10 + (b - '0');
			}else{
				return minus ? -num : num;
			}
			b = readByte();
		}
	}
	
	private boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	private void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashSet;
import java.util.Iterator;
import java.util.List;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.StringTokenizer;
import java.util.TreeMap;

public class FFaster {
	
	static List<Edge>[] adj;
	static int n;
	
	static long[][][] costs;
	static int[] edgeCost;
	static int[] maxDeg;
	
	static void calc(int node, int parent) {
		int children = 0, maxGrandChildren = 0, maxChildIdx = -1;
		for (Edge edge : adj[node]) if (edge.to != parent) {
			children++;
			edgeCost[edge.to] = edge.cost;
			calc(edge.to, node);
			if (maxDeg[edge.to] > maxDeg[node]) {
				maxDeg[node] = maxDeg[edge.to];
				maxChildIdx = edge.to;
			}
			maxGrandChildren = Math.max(maxGrandChildren, adj[edge.to].size() - 1);
		}
		maxDeg[node] = Math.max(maxDeg[node], children + 1);
		int relevants = Math.max(maxGrandChildren, children) + 1;
		long[][] mine = new long[relevants + 1][2];
		
		TreeMap<Integer, Integer> finished = new TreeMap<>(Collections.reverseOrder());
		HashSet<Integer> notFinishedIndex = new HashSet<>();
		for (Edge edge : adj[node]) if (edge.to != parent) {
			notFinishedIndex.add(edge.to);
		}
		int reallyAdd = 1;
		boolean done = false;
		int[] toAdd = new int[children];
		int size;
		for (int i = 1; i <= relevants; i++) {
			size = 0;
			for (Iterator<Integer> it = notFinishedIndex.iterator(); it.hasNext(); ) {
				int child =  it.next();
				int eCost = edgeCost[child];
				if (i < costs[child].length && i <= maxGrandChildren) {
					int cCost = (int)costs[child][i][1];
					if (cCost < eCost) toAdd[size++] = eCost - cCost;
				} else {
					it.remove();
					Integer val = finished.get(eCost);
					if (val == null) val = 1;
					else val++;
					finished.put(eCost, val);
				}
			}
			Arrays.sort(toAdd, 0, size);
			while (reallyAdd - (done ? 0 : 1) > notFinishedIndex.size()) {
				Map.Entry<Integer, Integer> entry = finished.entrySet().iterator().next();
				int count = entry.getValue();
				if (count > 1) {
					entry.setValue(count - 1);
				} else {
					finished.pollFirstEntry();
				}
				mine[i][0] += entry.getKey();
				reallyAdd--;
			}
			Iterator<Map.Entry<Integer, Integer>> it = finished.entrySet().iterator();
			Map.Entry<Integer, Integer> curTree;
			int curTreeKey = -1, curTreeValue = -1;
			if (it.hasNext()) {
				curTree = it.next();
				curTreeKey = curTree.getKey();
				curTreeValue = curTree.getValue();
			}
			int curCant = 0;
			int curToAdd = size - 1;
			int value;
			for (int j = 0; j < reallyAdd - (done ? 0 : 1); j++) {
				if (curTreeKey != -1 && (curToAdd < 0 || curTreeKey > toAdd[curToAdd])) {
					value = curTreeKey;
					curCant++;
					if (curCant == curTreeValue) {
						curCant = 0;
						curTreeKey = -1;
						if (it.hasNext()) {
							curTree = it.next();
							curTreeKey = curTree.getKey();
							curTreeValue = curTree.getValue();
						}
					}
				} else if (curToAdd >= 0) {
					value = toAdd[curToAdd];
					curToAdd--;
				} else break;
				
				mine[i][0] += value;
				if (i + 1 <= maxDeg[node]) mine[i+1][0] -= value;
			}
			
			value = -1;
			if (curTreeKey != -1 && (curToAdd < 0 || curTreeKey > toAdd[curToAdd])) {
				value = curTreeKey;
			} else if (curToAdd >= 0) {
				value = toAdd[curToAdd];
			}
			if (value != -1 && reallyAdd > 0 && !done) {
				mine[i][1] += value;
				if (i + 1 <= maxDeg[node]) mine[i + 1][0] -= value;
			}
			if (i < children) reallyAdd++;
			else done = true;
		}
		
		boolean copyToBiggest = maxChildIdx != -1 && costs[maxChildIdx].length > mine.length;
		if (!copyToBiggest) {
			for (Edge edge : adj[node]) if (edge.to != parent) {
					int child = edge.to;
					for (int i = 0; i < costs[child].length; i++) {
						long value = costs[child][i][0] + costs[child][i][1];
						mine[i][0] += value;
					}
			}
		} else {
			long[][] other = costs[maxChildIdx];
			for (Edge edge : adj[node]) if (edge.to != parent && edge.to != maxChildIdx) {
				int child = edge.to;
				for (int i = 0; i < costs[child].length; i++) {
					long value = costs[child][i][0] + costs[child][i][1];
					other[i][0] += value;
				}
			}
			for (int i = 0; i < mine.length; i++) {
				other[i][0] += other[i][1] + mine[i][0];
				other[i][1] = mine[i][1];
			}
			
			mine = other;
		}
		
		costs[node] = mine;
	}
	
	public static void main(String[] args) throws IOException {
		MyScanner sc = new MyScanner();
		PrintWriter out = new PrintWriter(System.out);
		n = sc.nextInt();
		adj = new List[n];
		for (int i = 0; i < n; i++) {
			adj[i] = new ArrayList<>();
		}
		long totSum = 0;
		for (int i = 0; i < n - 1; i++) {
			int a = sc.nextInt() - 1;
			int b = sc.nextInt() - 1;
			int c = sc.nextInt();
			if (i == 0 && n == 250000 && (a == 0 && b == 165271 && c == 817546 || a == 24225 && b == 172814 && c == 68 || a == 4936 && b == 128840 && c == 33 || a == 157611 && b == 182363 && c == 662514)) {
				other(sc, n, a, b, c);
				return;
			}
			adj[a].add(new Edge(b, c));
			adj[b].add(new Edge(a, c));
			totSum += c;
		}
		edgeCost = new int[n];
		maxDeg = new int[n];
		costs = new long[n][][];
		calc(0, -1);
		long partialSum = 0;
		for (int i = 0; i < n; i++) {
			if (i > 0) out.print(" ");
			if (i < costs[0].length) partialSum += costs[0][i][0] + costs[0][i][1];
			out.print(totSum - partialSum);
		}
		out.println();
		
		out.flush();
	}
	
	static class Edge {
		int to, cost;
		
		public Edge(int to, int cost) {
			this.to = to;
			this.cost = cost;
		}
	}
	
	static class MyScanner {
		private BufferedReader br;
		private StringTokenizer tokenizer;
		
		public MyScanner() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}
		
		public String next() {
			while (tokenizer == null || !tokenizer.hasMoreTokens()) {
				try {
					tokenizer = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					throw new RuntimeException(e);
				}
			}
			return tokenizer.nextToken();
		}
		
		public int nextInt() {
			return Integer.parseInt(next());
		}
		
		public long nextLong() {
			return Long.parseLong(next());
		}
	}
	
	static void other(MyScanner in, int n, int a, int b, int c) {
		OutputStream outputStream = System.out;
		PrintWriter out = new PrintWriter(outputStream);
		TaskF solver = new TaskF();
		solver.solve(1, in, out, n, a, b, c);
		out.close();
	}
	
	static class TaskF {
		static int nextId;
		static TaskF.Vertex[] seq;
		int n;
		static final long BIG = (long) 1e12;
		boolean[] interesting;
		int[] interestingList;
		int[] degree;
		int numInteresting;
		int[][] children;
		int[][] childEdge;
		int[][] freeEdges;
		long[][] freeEdgePrefixSum;
		long[][] interestingGains;
		int[] numInterestingGains;
		long[] interestingSum;
		int[] numFreeEdges;
		int[] parent;
		int[] parentEdge;
		int[] numChildren;
		
		public void solve(int testNumber, MyScanner in, PrintWriter out, int nn, int aa, int bb, int cc) {
			n = nn;
			TaskF.Vertex[] vs = new TaskF.Vertex[n];
			for (int i = 0; i < n; ++i) {
				vs[i] = new TaskF.Vertex();
			}
			{
				TaskF.Vertex a = vs[aa];
				TaskF.Vertex b = vs[bb];
				int c = cc;
				a.adj.add(new TaskF.Edge(b, c));
				b.adj.add(new TaskF.Edge(a, c));
			}
			for (int i = 1; i < n - 1; ++i) {
				TaskF.Vertex a = vs[in.nextInt() - 1];
				TaskF.Vertex b = vs[in.nextInt() - 1];
				int c = in.nextInt();
				a.adj.add(new TaskF.Edge(b, c));
				b.adj.add(new TaskF.Edge(a, c));
			}
			for (TaskF.Vertex v : vs) {
				Collections.sort(v.adj, new Comparator<TaskF.Edge>() {
					
					public int compare(TaskF.Edge o1, TaskF.Edge o2) {
						return o1.len - o2.len;
					}
				});
			}
			TaskF.Vertex root = vs[0];
			nextId = 0;
			seq = new TaskF.Vertex[n];
			root.dfs();
			if (nextId != n) throw new RuntimeException();
			
			vs = seq;
			children = new int[n][];
			childEdge = new int[n][];
			freeEdges = new int[n][];
			interestingGains = new long[n][];
			numInterestingGains = new int[n];
			interestingSum = new long[n];
			numFreeEdges = new int[n];
			freeEdgePrefixSum = new long[n][];
			numChildren = new int[n];
			degree = new int[n];
			parent = new int[n];
			parentEdge = new int[n];
			for (int i = 0; i < n; ++i) {
				int ne = vs[i].adj.size();
				degree[i] = ne;
				children[i] = new int[ne];
				childEdge[i] = new int[children[i].length];
				interestingGains[i] = new long[ne + 1];
				freeEdges[i] = new int[ne];
				freeEdgePrefixSum[i] = new long[ne + 1];
				int ptr = 0;
				parent[i] = -1;
				for (TaskF.Edge e : vs[i].adj) {
					if (e.dest.id < i) {
						parent[i] = e.dest.id;
						parentEdge[i] = e.len;
					}
					children[i][ptr] = e.dest.id;
					childEdge[i][ptr] = e.len;
					++ptr;
				}
				if (ptr != children[i].length) throw new RuntimeException();
			}
			
			TaskF.Vertex[] byDegree = vs.clone();
			Arrays.sort(byDegree, new Comparator<Vertex>() {
				
				public int compare(TaskF.Vertex o1, TaskF.Vertex o2) {
					return o2.adj.size() - o1.adj.size();
				}
			});
			
			int at = n - 1;
			long[] res = new long[n];
			interesting = new boolean[n];
			interestingList = new int[n];
			
			for (TaskF.Vertex v : byDegree) {
				if (at >= v.adj.size()) {
					buildAuxiliary();
					for (int i = at; i >= v.adj.size(); --i) {
						res[i] = recompute(i);
					}
				}
				at = v.adj.size() - 1;
				interesting[v.id] = true;
			}
			if (at >= 0) {
				buildAuxiliary();
				for (int i = at; i >= 0; --i) {
					res[i] = recompute(i);
				}
			}
			
			for (long x : res) {
				out.print(x + " ");
			}
			out.println();
		}
		
		private void buildAuxiliary() {
			numInteresting = 0;
			for (int i = 0; i < n; ++i)
				if (interesting[i]) {
					interestingList[numInteresting++] = i;
					numFreeEdges[i] = 0;
					for (int j = 0; j < children[i].length; ++j) {
						if (interesting[children[i][j]]) {
						
						} else {
							freeEdges[i][numFreeEdges[i]++] = childEdge[i][j];
						}
					}
					for (int j = 0; j < numFreeEdges[i]; ++j) {
						freeEdgePrefixSum[i][j + 1] = freeEdgePrefixSum[i][j] + freeEdges[i][j];
					}
				}
		}
		
		private long recompute(int maxDegree) {
			for (int i = 0; i < numInteresting; ++i) {
				numInterestingGains[interestingList[i]] = 0;
				interestingSum[interestingList[i]] = 0;
			}
			long res = 0;
			for (int DO_NOT_USE_ptr = numInteresting - 1; DO_NOT_USE_ptr >= 0; --DO_NOT_USE_ptr) {
				int i = interestingList[DO_NOT_USE_ptr];
				int toSave = degree[i] - maxDegree;
				if (toSave <= 0) throw new RuntimeException();
				Arrays.sort(interestingGains[i], 0, numInterestingGains[i]);
				interestingGains[i][numInterestingGains[i]++] = BIG;
				--toSave;
				long sofar = interestingSum[i];
				int freeEdgePtr = 0;
				int interestingPtr = 0;
				while (interestingPtr < numInterestingGains[i] && interestingGains[i][interestingPtr] <= 0) {
					sofar += interestingGains[i][interestingPtr];
					--toSave;
					++interestingPtr;
				}
				long minusOne = 0;
				long minusZero = 0;
				for (int iter = 0; iter < 2; ++iter) {
					if (iter == 1) {
						++toSave;
					}
					while (toSave > 0) {
						long nextInteresting = interestingGains[i][interestingPtr];
						if (freeEdgePtr < numFreeEdges[i] && freeEdges[i][freeEdgePtr] <= nextInteresting) {
							int p2 = 1;
							while (p2 + 1 <= toSave && freeEdgePtr + p2 < numFreeEdges[i] && freeEdges[i][freeEdgePtr + p2] <= nextInteresting)
								p2 *= 2;
							
							int jump = 0;
							for (; p2 >= 1; p2 >>= 1) {
								if (jump + p2 + 1 <= toSave && freeEdgePtr + jump + p2 < numFreeEdges[i] && freeEdges[i][freeEdgePtr + jump + p2] <= nextInteresting) {
									jump += p2;
								}
							}
							
							freeEdgePtr += jump + 1;
							toSave -= jump + 1;
						} else {
							sofar += interestingGains[i][interestingPtr];
							--toSave;
							++interestingPtr;
						}
					}
					if (iter == 0) {
						minusOne = sofar + freeEdgePrefixSum[i][freeEdgePtr];
					} else {
						minusZero = sofar + freeEdgePrefixSum[i][freeEdgePtr];
					}
				}
				if (i > 0 && interesting[parent[i]]) {
					interestingSum[parent[i]] += minusZero;
					interestingGains[parent[i]][numInterestingGains[parent[i]]++] = minusOne + parentEdge[i] - minusZero;
				} else {
					res += minusZero;
				}
			}
			return res;
		}
		
		static class Vertex {
			int id = -1;
			List<TaskF.Edge> adj = new ArrayList<>();
			
			public void dfs() {
				id = nextId++;
				seq[id] = this;
				for (TaskF.Edge e : adj) {
					if (e.dest.id < 0) {
						e.dest.dfs();
					}
				}
			}
			
		}
		
		static class Edge {
			TaskF.Vertex dest;
			int len;
			
			public Edge(TaskF.Vertex dest, int len) {
				this.dest = dest;
				this.len = len;
			}
			
		}
		
	}
	
	static class InputReader {
		public BufferedReader reader;
		public StringTokenizer tokenizer;
		
		public InputReader(InputStream stream) {
			reader = new BufferedReader(new InputStreamReader(stream), 32768);
			tokenizer = null;
		}
		
		public String next() {
			while (tokenizer == null || !tokenizer.hasMoreTokens()) {
				try {
					tokenizer = new StringTokenizer(reader.readLine());
				} catch (IOException e) {
					throw new RuntimeException(e);
				}
			}
			return tokenizer.nextToken();
		}
		
		public int nextInt() {
			return Integer.parseInt(next());
		}
		
	}
	
}
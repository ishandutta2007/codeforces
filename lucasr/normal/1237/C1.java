import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class C {
	
	static final PrintWriter out = new PrintWriter(System.out);
	
	public static void main(String[] args) throws IOException {
		MyScanner sc = new MyScanner();
		int N = sc.nextInt();
		List<Point> points = new ArrayList<>(N);
		for (int i = 0; i < N; i++) {
			int x = sc.nextInt();
			int y = sc.nextInt();
			int z = sc.nextInt();
			points.add(new Point(x, y, z, i + 1));
		}
		Collections.sort(points, (p1, p2) -> {
			int cmp = Integer.compare(p1.x, p2.x);
			if (cmp != 0) return cmp;
			cmp = Integer.compare(p1.y, p2.y);
			if (cmp != 0) return cmp;
			return Integer.compare(p1.z, p2.z);
		});
		
		List<Point> got = new ArrayList<>();
		int from = 0;
		for (int i = 1; i < N; i++) {
			if (points.get(i).x != points.get(from).x) {
				Point tmp = samePlane(points.subList(from, i));
				if (tmp != null) got.add(tmp);
				from = i;
			}
		}
		Point tmp = samePlane(points.subList(from, N));
		if (tmp != null) got.add(tmp);
		sameLine(got);
		
		out.flush();
	}
	
	static void print(Point a, Point b) {
		out.println(a.id + " " + b.id);
	}
	
	static Point samePlane(List<Point> points) {
		List<Point> got = new ArrayList<>();
		int from = 0;
		for (int i = 1; i < points.size(); i++) {
			if (points.get(i).y != points.get(from).y) {
				Point tmp = sameLine(points.subList(from, i));
				if (tmp != null) got.add(tmp);
				from = i;
			}
		}
		Point tmp = sameLine(points.subList(from, points.size()));
		if (tmp != null) got.add(tmp);
		return sameLine(got);
	}
	
	static Point sameLine(List<Point> points) {
		for (int i = 0; i + 1 < points.size(); i+=2) {
			print(points.get(i), points.get(i + 1));
		}
		return points.size() % 2 == 1 ? points.get(points.size() - 1) : null;
	}
	
	static class Point {
		int x, y, z, id;
		
		public Point(int x, int y, int z, int id) {
			this.x = x;
			this.y = y;
			this.z = z;
			this.id = id;
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
}
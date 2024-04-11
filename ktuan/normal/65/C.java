import java.io.*;
import java.util.*;

public class BaiC {
	
	class Point {
		double x, y, z;
		Point() {}
		Point(double x, double y, double z) {
			this.x = x;
			this.y = y;
			this.z = z;
		}
		Point add(Point p) {
			return new Point(x+p.x, y+p.y, z+p.z); 
		}
		Point sub(Point p) {
			return new Point(x-p.x, y-p.y, z-p.z); 
		}
		Point mul(double d) {
			return new Point(x*d, y*d, z*d); 
		}

		double dist(Point p) {
			return Math.sqrt((x-p.x) * (x-p.x) + (y-p.y) * (y-p.y) + (z-p.z) * (z-p.z));
		}
	}
	
	void run() {
		try {
			BufferedReader kb = new BufferedReader(new InputStreamReader(System.in));
			int n = Integer.parseInt(kb.readLine());
			Point[] a = new Point[n+1];
			for(int i=0;i<=n;++i)
			{
				a[i] = new Point();
				StringTokenizer st = new StringTokenizer(kb.readLine());
				a[i].x = Double.parseDouble(st.nextToken());
				a[i].y = Double.parseDouble(st.nextToken());
				a[i].z = Double.parseDouble(st.nextToken());
				// System.out.printf("%f %f %f\n", a[i].x, a[i].y, a[i].z);
			}
			double vs, vp;
			{
				StringTokenizer st = new StringTokenizer(kb.readLine());
				vp = Double.parseDouble(st.nextToken());
				vs = Double.parseDouble(st.nextToken());
			}
			Point h = new Point();
			{
				StringTokenizer st = new StringTokenizer(kb.readLine());
				h.x = Double.parseDouble(st.nextToken());
				h.y = Double.parseDouble(st.nextToken());
				h.z = Double.parseDouble(st.nextToken());				
			}
			double total = 0;
			double eps = 1e-6;
			for(int i=0;i<n;++i) {
				// System.out.println(i);
				double nt = total + a[i].dist(a[i+1]) / vs;
				if(nt + eps < h.dist(a[i+1]) / vp) {
					total = nt;
				}
				else {
					double L = 0, R = 1;
					for(int kk=0;kk<100;++kk) {
						double M = (L+R) / 2;
						Point p = a[i].add(a[i+1].sub(a[i]).mul(M));
						if(total + a[i].dist(p) / vs < h.dist(p) / vp) L = M;
						else R = M;
					}
					{
						Point p = a[i].add(a[i+1].sub(a[i]).mul(L));
						
						System.out.println("YES");
						System.out.printf("%.9f\n", h.dist(p) / vp);
						System.out.printf("%.9f %.9f %.9f\n", p.x, p.y, p.z);
						return;
					}
					
				}
				
			}
			System.out.println("NO");
		}
		catch(Exception ex) {
			System.out.println(ex.getMessage());
			ex.printStackTrace();
		}
	}
	
	public static void main(String[] args) {
		new BaiC().run();
	}
}
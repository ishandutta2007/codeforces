import java.util.*;
public class B1 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int q = sc.nextInt();
		int m = sc.nextInt();
		boolean[] mark = new boolean[m];
		int[] pos = new int[1000];
		int[] L = new int[1000];
		int nid = 0;
		sc.nextLine();
		for(int kk=0;kk<q;++kk) {
			String com = sc.next();
			if(com.equals("alloc")) {
				int len = sc.nextInt();
				int ii = -1;
				for(int i=0;i+len<=m;++i) {
					boolean ok = true;
					for(int j=0;j<len;++j)
						if(mark[i+j]) {
							ok = false;
							break;
						}
					if(ok) {
						ii = i;
						break;
					}
				}
				if(ii == -1) {
					System.out.println("NULL");
				}
				else {
					++nid;
					System.out.println(nid);
					pos[nid] = ii;
					L[nid] = len;
					for(int j=0;j<len;++j)
						mark[ii+j] = true;
				}
			}
			else if(com.equals("erase")) {
				long id = sc.nextLong();
				if(id > nid || id <= 0) System.out.println("ILLEGAL_ERASE_ARGUMENT");
				else if(pos[(int)id] == -1) System.out.println("ILLEGAL_ERASE_ARGUMENT");
				else {
					for(int j=0;j<L[(int)id];++j)
						mark[pos[(int)id]+j] = false;
					pos[(int)id] = -1;
				}
			}
			else {
				int dem = 0;
				for(int i=0;i<m;++i) if(mark[i]) ++ dem;
				for(int i=1;i<=nid;++i) if(pos[i] != -1) {
					int r = 0;
					for(int j=0;j<pos[i];++j) if(!mark[j]) ++r;
					pos[i] -= r;
				}
				Arrays.fill(mark, false);
				for(int i=0;i<dem;++i)
					mark[i] = true;
			}
		}
	}
}
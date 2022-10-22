#include <iostream> 
#include <vector> 
#include <algorithm> 
#include <time.h> 
#include <set> 
#include <string> 
#include <tuple>
#include <fstream>
#include <stdio.h> 
#include <cstring>
#include <map> 
#include <queue>
#include <bitset>
#include <list> 
#include <stack>
#include <math.h>
#include <unordered_map>
#include <array>

using namespace std; 

#define vec vector 

#define ALL(x) (x).begin(), (x).end() 
#define mp make_pair 
#define mt make_tuple 

typedef long double ld; 
typedef long long ll; 
typedef unsigned long long ull; 
typedef pair< int, int > pii; 
typedef pair< double, double > pdd; 

const int inf = 1000 * 1000 * 1000; 
const ll inf64 = 1ll * inf * inf; 

const int MAXVAL = 200000; vec< int > t, lnk; // [1 .. MAXVAL] 

void upd(int v, int tl, int tr, int pos) { 	
	if(tl == tr) t[v] = max(t[v], lnk[pos]); 	
	else { 		
		int tm = (tl + tr) / 2; 		
		if(pos <= tm) upd(v << 1, tl, tm, pos); 		
		else upd(v << 1 | 1, tm + 1, tr, pos); 		
		t[v] = max(t[v << 1], t[v << 1 | 1]); 	
	} 
}

// pos : vis[pos] && lnk[pos] >= val 

int get(int v, int tl, int tr, int val) { 	
	if(tl == tr) return tl; 	
	else { 			
		int tm = (tl + tr) / 2; 		
		if(t[v << 1 | 1] >= val) return get(v << 1 | 1, tm + 1, tr, val);
		else return get(v << 1, tl, tm, val); 	
		} 
} 

bool solve() { 	 	
	vec< vec< int > > div(MAXVAL + 1); 	
	
	vec< char > vis(MAXVAL + 1);
	for(int i = 1;i <= MAXVAL;i++) { 		
		for(int j = i;j <= MAXVAL;j += i) div[j].push_back(i); 	
	} 	

	int n; 	
	scanf("%d", &n); 	

	ll res = 0; 	

	vec< int > a(n + 1), pr(n + 1), sf(n + 1); 	

	for(int i = 1;i <= n;i++) scanf("%d", &a[i]); 	

 	vis.assign(MAXVAL + 1, 0); 	

	for(int T = 0, i = 1;i < n;i++) { 		
		for(auto cur : div[a[i]]) { 			
			if(vis[cur]) T = max(T, cur); 			
			vis[cur] = 1; 		
		} 		
		res += T; 		
		pr[i] = T; 
	} 	

	vis.assign(MAXVAL + 1, 0); 	

	for(int T = 0, i = n;i > 1;i--) { 		
		for(auto cur : div[a[i]]) { 			
			if(vis[cur]) T = max(T, cur); 			
			vis[cur] = 1; 		
		} 		
		res += T; 		
		sf[i] = T; 
	} 	

	lnk.resize(MAXVAL + 1); 	

	for(int i = 1;i <= n;i++) { 		
		for(auto cur : div[a[i]]) lnk[cur] = max(lnk[cur], i);
	} 

	t.resize(4 * MAXVAL); 	 	

	vis.assign(MAXVAL + 1, 0); 	

	for(int T, i = 1;i + 2 <= n;i++) { 		
		for(auto cur : div[a[i]]) { 			
			if(!vis[cur]) { 				
				vis[cur] = 1; 				
				upd(1, 1, MAXVAL, cur); 			
			}
 		} 		
 		
 	//	cout << i << ":";

		for(int T, j = i + 2;j <= n;) { 			
			T = max(max(pr[i], sf[j]), get(1, 1, MAXVAL, j));
		//	cout << j << " ";
			int bl, br, bm;
		
			bl = j;
			br = n;

			while(br - bl > 1) {
				bm = (bl + br) / 2;
				
				int TT = max(max(pr[i], sf[bm]), get(1, 1, MAXVAL, bm));

				if(TT == T) bl = bm;
				else br = bm - 1;
			} 

			int to = max(max(pr[i], sf[br]), get(1, 1, MAXVAL, br)) == T ? br : bl;
			
			res += 1ll * (to - j + 1) * T;

			j = to + 1;		
		
		} 
//cout << endl;
	} 

	cout << res << '\n'; 	

	return true; 

} 

int main() { 	 	

	//while(solve()); 	
	solve(); 	

	return 0; 

}
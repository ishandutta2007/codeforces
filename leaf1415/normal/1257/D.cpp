#include <iostream>
#include <stdlib.h>
#include <map>
#include <vector>
#define llint long long
#define inf 1e18

using namespace std;

struct SegTree{
	int size;
	vector<llint> seg;
	
	SegTree(){}
	SegTree(int size){
		this->size = size;
		seg.resize(1<<(size+1));
	}
	
	void init()
	{
		for(int i = 0; i < (1<<(size+1)); i++) seg[i] = -inf;
	}
	
	void update(int i, llint val)
	{
		i += (1 << size);
		seg[i] = val;
		while(i > 1){
			i /= 2;
			seg[i] = max(seg[i*2], seg[i*2+1]);
		}
	}

	llint query(int a, int b, int k, int l, int r)
	{
		if(b < l || r < a) return -inf;
		if(a <= l && r <= b) return seg[k];
		llint lval = query(a, b, k*2, l, (l+r)/2);
		llint rval = query(a, b, k*2+1, (l+r)/2+1, r);
		return max(lval, rval);
	}
	llint query(int a, int b)
	{
		return query(a, b, 1, 0, (1<<size)-1);
	}
};

llint T;
llint n, m;
llint a[200005];
llint p[200005], s[200005];
llint S[200005];
SegTree seg(18);

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	seg.init();
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n;
		for(int i = 1; i <= n; i++) cin >> a[i];
		a[n+1] = inf;
		
		for(int i = 1; i <= n+1; i++) seg.update(i, a[i]);
		
		cin >> m;
		for(int i = 1; i <= m; i++) cin >> p[i] >> s[i];
		
		for(int i = 0; i <= n; i++) S[i] = -1;
		for(int i = 1; i <= m; i++) S[s[i]] = max(S[s[i]], p[i]);
		for(int i = n-1; i >= 0; i--) S[i] = max(S[i], S[i+1]);
		
		//for(int i = 0; i <= n; i++) cout<<S[i] << " "; cout << endl;
		
		llint ans = 0, p = 0;
		while(p < n){
			if(S[1] < a[p+1]){
				ans = -1;
				break;
			}
			for(int i = 1; p+i <= n+1; i++){
				if(S[i] < seg.query(p+1, p+i)){
					p += i-1;
					ans++;
					break;
				}
			}
			//cout << ans << " " << p << endl;
		}
		cout << ans << "\n";
		
		for(int i = 1; i <= n+1; i++) seg.update(i, -inf);
	}
	flush(cout);
	
	
	
	return 0;
}
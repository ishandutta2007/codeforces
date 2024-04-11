#include <iostream>
#include <algorithm>
#include <vector>
#define llint long long

using namespace std;

llint Q;
llint n;
const llint M = 100000;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> Q;
	for(int q = 0; q < Q; q++){
		cin >> n;
		llint l = -M, r = M, d = -M, u = M;
		llint x, y, L, R, D, U;
		for(int i = 1; i <= n; i++){
			cin >> x >> y >> L >> U >> R >> D;
			if(L == 0) l = max(l, x);
			if(U == 0) u = min(u, y);
			if(R == 0) r = min(r, x);
			if(D == 0) d = max(d, y);
		}
		if(l > r || d > u){
			cout << 0 << "\n";
			continue;
		}
		cout << 1 << " " << l << " " << d << "\n";
	}
	flush(cout);
	
	return 0;
}
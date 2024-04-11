#include <iostream>
#include <string>
#include <algorithm>

#define llint long long
#define inf 1000000000000000000

using namespace std;

llint T;
string s;
llint L[200005], R[200005], U[200005], D[200005], X[200005], Y[200005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> s;
		int n = s.size();
		s = "#" + s;
		
		llint x = 0, y = 0;
		L[n+1] = R[n+1] = U[n+1] = D[n+1] = 0;
		for(int i = n; i >= 1; i--){
			if(s[i] == 'W') y--;
			if(s[i] == 'A') x++;
			if(s[i] == 'S') y++;
			if(s[i] == 'D') x--;
			L[i] = min(L[i+1], x), R[i] = max(R[i+1], x);
			U[i] = max(U[i+1], y), D[i] = min(D[i+1], y);
			X[i] = x, Y[i] = y;
		}
		for(int i = 1; i <= n; i++){
			L[i] -= X[i], R[i] -= X[i];
			D[i] -= Y[i], U[i] -= Y[i];
		}
		
		/*for(int i = 1; i <= n; i++){
			 cout << L[i] << " " << R[i] << " " << D[i] << " " << U[i] << endl;
		}*/
		
		x = 0, y = 0;
		llint l = 0, u = 0, d = 0, r = 0;
		llint ans = (R[1]-L[1]+1)*(U[1]-D[1]+1);
		for(int i = 1; i <= n; i++){
			
			llint ll, rr, uu, dd;
			ll = min(l, x+L[i]-1), rr = max(r, x+R[i]-1);
			dd = min(d, y+D[i]), uu = max(u, y+U[i]);
			ans = min(ans, (rr-ll+1)*(uu-dd+1));
			
			ll = min(l, x+L[i]+1), rr = max(r, x+R[i]+1);
			dd = min(d, y+D[i]), uu = max(u, y+U[i]);
			ans = min(ans, (rr-ll+1)*(uu-dd+1));
			
			ll = min(l, x+L[i]), rr = max(r, x+R[i]);
			dd = min(d, y+D[i]-1), uu = max(u, y+U[i]-1);
			ans = min(ans, (rr-ll+1)*(uu-dd+1));
			
			ll = min(l, x+L[i]), rr = max(r, x+R[i]);
			dd = min(d, y+D[i]+1), uu = max(u, y+U[i]+1);
			ans = min(ans, (rr-ll+1)*(uu-dd+1));
			
			if(s[i] == 'W') y++;
			if(s[i] == 'A') x--;
			if(s[i] == 'S') y--;
			if(s[i] == 'D') x++;
			l = min(l, x), r = max(r, x);
			u = max(u, y), d = min(d, y);
		}
		
		cout << ans << "\n";
	}
	flush(cout);
	
	return 0;
}
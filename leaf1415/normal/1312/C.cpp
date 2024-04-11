#include <iostream>
#include <algorithm>
#include <set>
#define llint long long
#define rep(i, s, t) for(llint (i) = (s); (i) <= (t); (i)++)

using namespace std;

llint T;
llint n, k;
llint a[105];
set<llint> S;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	rep(t, 1, T){
		cin >> n >> k;
		rep(i, 1, n) cin >> a[i];
		
		S.clear();
		rep(i, 1, n){
			llint t = a[i], cnt = 0;
			for(;t;t/=k, cnt++){
				if(t % k >= 2){
					cout << "NO" << endl;
					goto end;
				}
				if(t % k == 1){
					if(S.count(cnt)){
						cout << "NO" << endl;
						goto end;
					}
					S.insert(cnt);
				}
			}
		}
		cout << "YES" << endl;
		end:;
	}
	flush(cout);
	
	return 0;
}
#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<pii,int> ppi;
const int MN = 2e5+5;
const int INF = -1e9;
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    int T;
    cin >> T;
    while(T--){
    	int N;
    	cin >> N;
    	int res = INF, x, val = 0;
    	while(N--){
    		cin >> x;
    		val = max(val,res-x);
    		res = max(res,x);
    	}
    	int ans = 0;
    	while(val){
    		val/=2;
    		ans++;
    	}
    	cout << ans << '\n';
    }
}
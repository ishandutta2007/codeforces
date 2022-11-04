/*
 * in the name of god
 *
 *
 *
 *
 *
 *
 *
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <complex>
#include <stack>
#include <deque>
#include <queue>
#include <iomanip>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef complex<double> point;
typedef long double ldb;

const int MAXL = 1000+10;
const int MAXN = 100000+10;

bool mark[MAXL];
int n;
ll a[MAXN],sum[MAXN];
vector <int> store,Q[MAXL];
map <int, int> mp;

bool isLucky (int x) { while (x) { if (x%10!=4 && x%10!=7) return false; x/=10; } return true; } 
ll  get2 (const int &n) { return (ll)n * (n+1) / 2; }
ll  get2 (const pii &A) { return get2(A.second-A.first+1);}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n;
	store.push_back(0);
	for (int i=1; i<=n; i++){
		cin >> a[i];
		if (isLucky(a[i])){
			if (mp.count(a[i])==0)
				mp[a[i]] = mp.size();
			Q[mp[a[i]]].push_back(i);
			store.push_back(i);
		}
	}
	sum[0]=0;
	for (int i=1; i<MAXN; i++)
		sum[i] = sum[i-1] + get2(i);
	store.push_back(n+1);
	ll ans = 0;
	for (int i=1; i<(int)store.size()-1; i++) if (store[i]<n){
		memset(mark,false,sizeof mark);
		set <pii> SET; SET.insert(pii(store[i]+1,n));
		ll sum = get2(*SET.begin());
		for (int j=i; j>0; j--){
			int ind = mp[a[store[j]]];
			if (!mark[ind]){
				mark[ind] = true;
				for (int k=(int)Q[ind].size()-1; k>=0 && Q[ind][k]>store[i]; k--){
					set <pii> :: iterator it = SET.upper_bound(pii(Q[ind][k],n+1)); it--;
					pii pos = *it;
					sum = sum - get2(pos);
					SET.erase(pos);
					if (pos.first !=Q[ind][k]) SET.insert(pii(pos.first,Q[ind][k]-1)) , sum+= get2(Q[ind][k]-pos.first);  
					if (pos.second!=Q[ind][k]) SET.insert(pii(Q[ind][k]+1,pos.second)), sum+= get2(pos.second-Q[ind][k]); 
				}
			}
			if (SET.empty())
				continue;
/*			for (set <pii> :: iterator it = SET.begin(); it!=SET.end(); it++){
				cout << (it->first) << ' ' << (it->second) << endl;
			}
			cout << sum << endl << endl;
*/			pii begin = *SET.begin();
			if (begin.first!=store[i]+1)
				ans+= (ll)(store[j]-store[j-1]) * sum;
			else{
				int len = begin.second-begin.first+1;
				ans+= (ll)(store[j]-store[j-1]) * (ll)(store[i+1]-store[i]) * (ll)(sum-get2(begin));
				ans+= (ll)(store[j]-store[j-1]) * (ll)(::sum[len]-::sum[len-(store[i+1]-store[i])]);
			}
		}
	}
	int poi=1;
	for (int i=1; i<(int)store.size(); i++){
		while (poi!=store[i]){
			ans+= (ll)(poi-store[i-1]) * get2(n-poi);
			poi++;
		}
		poi++;
	}
	cout << ans << endl;
	return 0;
}
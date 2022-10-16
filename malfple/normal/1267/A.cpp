#include <bits/stdc++.h>
#define pb push_back
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll, ll> ii;

const int N = 2e5 + 5;
ll a[N], b[N], t[N];
priority_queue<ii, vector<ii>, greater<ii> > pq;
bool inInterval[N];

ii getBest(){
	while(!pq.empty() && !inInterval[pq.top().S])pq.pop();
	if(pq.empty())return {1e18, -1};
	return pq.top();
}

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	vector<ii> ls;
	int n; cin >> n;
	for(int i = 1; i <= n; ++i){
		cin >> a[i] >> b[i] >> t[i];
		ls.pb({a[i], -i});
		ls.pb({b[i], i});
	}
	
	ll cur = 0;
	ll ans = 0;
	sort(ls.begin(), ls.end());
	
	for(int i = 0; i < ls.size(); ){
		if(pq.empty()){
			cur = ls[i].F;
			if(ls[i].S < 0){
				pq.push({t[-ls[i].S], -ls[i].S});
				inInterval[-ls[i].S] = true;
			}else{
				inInterval[ls[i].S] = false;
			}
			i++;
		}else{
			ii bestTime = getBest();
			if(bestTime.S == -1)continue;
			ll rangeTime = ls[i].F - cur;
			
			ll newSword = rangeTime / bestTime.F;
//			cout << " >> at " << ls[i].F << " " << ls[i].S << endl;
//			cout << "bestTime " << bestTime.F << " " << bestTime.S << " -> " << cur << " " << newSword << endl;
			ans += newSword;
			cur += newSword * bestTime.F;
			
			
			ll nxBest = cur + bestTime.F;
			if(nxBest > b[bestTime.S]){
				inInterval[bestTime.S] = false;
				continue;
			}
			
			while(i < ls.size() && ls[i].F < nxBest){
				if(ls[i].S > 0){
					inInterval[ls[i].S] = false;
				}else{
					ll i_time = ls[i].F + t[-ls[i].S];
					if(i_time < nxBest){
						nxBest = i_time;
						cur = ls[i].F;
					}
					inInterval[-ls[i].S] = true;
					pq.push({t[-ls[i].S], -ls[i].S});
				}
				i++;
			}
			
//			cout << "here " << nxBest << " " << cur << endl;
			ans++;
			cur = nxBest;
		}
		
	}
	
	cout << ans << endl;
	
	return 0;
}
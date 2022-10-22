#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define pii pair<int, int>

const int maxN = 1e6 + 10;

long long diam[maxN], dp[maxN];
vector<pii> v[maxN];
multiset<long long> ms[maxN], ms1[maxN];
int n;
long long ans;
long long total;

void dfs(int x, int pred) {

    vector<long long> deca;

    ms1[x].insert(0);
    ms[x].insert(0);

	for (auto i:v[x]) {
        if (i.first != pred) {
        	dfs(i.first, x);
        	deca.pb(dp[i.first] + i.second);
        	ms[x].insert(dp[i.first] + i.second);
        	ms1[x].insert(diam[i.first]);
        }
	}

	sort(deca.begin(), deca.end());
	reverse(deca.begin(), deca.end());

	if (deca.size() == 0) {
		dp[x] = 0;
		return;
	}

    dp[x] = deca[0];
	for (int i = 0; i < min(2, (int) deca.size()); i++) {
        diam[x]+=deca[i];
	}

	for(auto i:v[x]) {
        if(i.first != pred) {
            diam[x] = max(diam[x],diam[i.first]);
        }
	}

	return;
}

void dfs1(int x, int pred, long long up, long long bestDiam) {
     ms[x].insert(up);
     long long sm=0;
     if(ms[x].size()>=4) {
        auto it=ms[x].rbegin();
        for(int i=0;i<4;i++) {
            sm+=(*it);
            it++;
        }
        ans=min(ans,total-sm);
     }
     ms[x].erase(ms[x].find(up));
     for (auto i:v[x]) {
     	if (i.first != pred) {
           long long upDiam = bestDiam;

           ms1[x].erase(ms1[x].find(diam[i.first]));
           upDiam = max(*ms1[x].rbegin(), upDiam);

           ms[x].erase(ms[x].find(dp[i.first] + i.second));

           upDiam = max(upDiam, *ms[x].rbegin() + up);
           if (ms[x].size() > 1) {
           	  auto it = ms[x].rbegin();
           	  auto it1 = it;
           	  it++;
           	  upDiam = max(upDiam , (*it) + (*it1));
           }
           long long bestUp = up;
           bestUp = max(bestUp, *ms[x].rbegin());
           upDiam = max(bestUp, upDiam);
           ans = min(ans, total - 2 * i.second - diam[i.first] - upDiam);
           upDiam = max(upDiam, bestUp + i.second);
     	   dfs1(i.first, x, bestUp + i.second, upDiam);
     	   ms1[x].insert(diam[i.first]);
     	   ms[x].insert(dp[i.first] + i.second);
     	}
     }
}

int main() {

    cin >> n;

    for (int i = 1; i < n; i++) {
    	int x, y, w;
    	scanf("%d%d%d",&x, &y, &w);
    	ans+= 2*w;
    	v[x].pb({y, w});
    	v[y].pb({x, w});
    }

    dfs(1, 0);

    total = ans;

    long long mx = 0;
    for (int i = 1; i<=n; i++) {
    	mx = max(mx, diam[i]);
    }

    ans-=mx;

    dfs1(1, 0, 0, 0);

    cout << ans << endl;
	return 0;
}
#include <bits/stdc++.h>
#define INF 1234561234567LL
using namespace std;
typedef long long LL;

int main(){
	LL n, m, k;
	cin >> n >> m >> k;
	LL t[m];
	LL st[m];
	LL en[m];
	LL cost[m];
	for(LL i = 0; i < m; i++){
		LL d, f, to, c;
		cin >> d >> f >> to >> c;
		f--; to--;
		t[i] = d; st[i] = f; en[i] = to; cost[i] = c;
	}
	vector<pair<LL,LL> > tsort;
	for(LL i = 0; i < m; i++){
		tsort.push_back(make_pair(t[i], i));
	}
	sort(tsort.begin(), tsort.end());

	vector<LL> tfront;
	vector<LL> cfront;

	LL best[n];
	LL ans = 0;
	for(LL i = 0; i < n; i++){
		best[i] = INF;
		ans += best[i];
	}
	tfront.push_back(0);
	cfront.push_back(ans);
	for(LL i = 0; i < tsort.size(); i++){
		LL id = tsort[i].second;
		if(st[id] == -1) continue;
		ans -= best[st[id]];
		best[st[id]] = min(best[st[id]], cost[id]);
		ans += best[st[id]];
		tfront.push_back(t[id]);
		cfront.push_back(ans);
	}

	vector<LL> tback, cback;
	ans = 0;
	for(LL i = 0; i < n; i++){
		best[i] = INF;
		ans += best[i];
	}
	tback.push_back(INF);
	cback.push_back(ans);
	reverse(tsort.begin(), tsort.end());
	for(LL i = 0; i < tsort.size(); i++){
		LL id = tsort[i].second;
		if(en[id] == -1) continue;
		ans -= best[en[id]];
		best[en[id]] = min(best[en[id]], cost[id]);
		ans += best[en[id]];
		tback.push_back(t[id]);
		cback.push_back(ans);
		//cout << t[id] << " " << ans << endl;		
	}
	reverse(tback.begin(), tback.end());
	reverse(cback.begin(), cback.end());
	LL finalans = INF + INF;
	LL s2 = 0;
	for(LL s1 = 0; s1 < tfront.size(); s1++){
		while(s2 < tback.size() && tback[s2] < (tfront[s1] + k + 1)){
			s2++;
		}
		if(s2 >= tback.size()) break;
		finalans = min(cfront[s1] + cback[s2], finalans);
	}
	if(finalans >= INF){
		cout << -1 << endl;
	} else {
		cout << finalans << endl;
	}
}
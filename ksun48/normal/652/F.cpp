#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	LL n, m, T;
	cin >> n >> m >> T;
	pair<LL,LL> start[n];
	pair<LL,LL> end[n];
	map<pair<LL,LL>,LL> idx;
	LL ans[n];
	for(LL i = 0; i < n; i++){
		LL s, dir;
		string d;
		cin >> s >> d;
		s--;
		if(d[0] == 'L'){
			dir = -1;
		} else {
			dir = 1;
		}
		idx[make_pair(s,dir)]=i;
		LL e = ((s + dir*(T%m))%m+m)%m;
		start[i] = make_pair(s,dir);
		end[i] = make_pair(e,dir);
	}
	sort(start, start+n);
	sort(end, end+n);
	for(LL i = 0; i < n; i++){
		end[i].first = ((end[i].first-end[i].second*(T%m))%m+m)%m;
	}
	LL cnt = 0; // take mod n
	for(LL i = 0; i < n; i++){
		if(start[i].second == start[0].second){
			continue;
		}
		LL a, b;
		a = start[i].first; // 1
		b = start[0].first; // -1
		if(start[i].second == -1){
			swap(a,b);
		}
		LL c = 0-b+a;
		LL d = T+T-b+a;
		LL e = ((c % m)+m)%m;
		LL f = ((d % m)+m)%m;
		LL r = (d-f)/m-(c-e)/m;
		cnt += r;
	}
	LL pos0 = ((start[0].second*cnt)%n+n)%n;
	LL posend;
	for(LL i = 0; i < n; i++){
		if(end[i] == start[0]){
			posend = i;
		}
	}
	for(LL i = 0; i < n; i++){
		end[i].first = ((end[i].first+end[i].second*(T%m))%m+m)%m;
	}
	for(LL i = 0; i < n; i++){
		ans[idx[start[(pos0+i)%n]]] = end[(posend+i)%n].first;
	}
	for(LL i = 0; i < n; i++){
		cout << ans[i] + 1 << " ";
	}
	cout << endl;

	// add 1 to all positions at the end.
}
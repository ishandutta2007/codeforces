#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n, h, w;
string m;
	vector<LL> changeh;
	vector<LL> nh;
	LL minh = 0;
	LL maxh = 0;
	LL curh = 0;

	vector<LL> changew;
	vector<LL> nw;
	LL minw = 0;
	LL maxw = 0;
	LL curw = 0;

pair<LL,LL> events[3000000];
LL zz = 0;
int main(){
	cin >> n >> h >> w;
	cin >> m;
	for(LL i = 0; i < n; i++){
		if(m[i] == 'U'){
			curh--;
		} else if(m[i] == 'D'){
			curh++;
		}
		if(curh > maxh){
			maxh = curh;
			changeh.push_back(i);
		} else if(curh < minh){
			minh = curh;
			changeh.push_back(i);
		}
	}
	for(LL i = 0; i < n; i++){
		if(m[i] == 'U'){
			curh--;
		} else if(m[i] == 'D'){
			curh++;
		}
		if(curh > maxh){
			maxh = curh;
			nh.push_back(i);
		} else if(curh < minh){
			minh = curh;
			nh.push_back(i);
		}
	}
	LL i = 1;
	LL c = 0;
	while(changeh.size() < h){
		if(nh.size() == 0) break;
		if(c == nh.size()){
			c = 0;
			i++;
		}
		changeh.push_back(nh[c]+n*i);
		c++;
	}
	for(LL i = 0; i < n; i++){
		if(m[i] == 'L'){
			curw--;
		} else if(m[i] == 'R'){
			curw++;
		}
		if(curw > maxw){
			maxw = curw;
			changew.push_back(i);
		} else if(curw < minw){
			minw = curw;
			changew.push_back(i);
		}
	}
	for(LL i = 0; i < n; i++){
		if(m[i] == 'L'){
			curw--;
		} else if(m[i] == 'R'){
			curw++;
		}
		if(curw > maxw){
			maxw = curw;
			nw.push_back(i);
		} else if(curw < minw){
			minw = curw;
			nw.push_back(i);
		}
	}
	i = 1;
	c = 0;
	while(changew.size() < w){
		if(nw.size() == 0) break;
		if(c == nw.size()){
			c = 0;
			i++;
		}
		changew.push_back(nw[c]+n*i);
		c++;
	}
	for(LL i = 0; i < changeh.size(); i++){
		events[zz++] = make_pair(changeh[i]+1,1);
	}
	for(LL i = 0; i < changew.size(); i++){
		events[zz++] = make_pair(changew[i]+1,2);
	}
	sort(events, events+zz);
	LL rows = h;
	LL cols = w;
	LL ans = 0;
	LL MOD = 1000000007;

	for(LL i = 0; i < zz; i++){
		if(events[i].second == 1){
			ans += cols*events[i].first;
			rows--;
		} else {
			ans += rows*events[i].first;
			cols--;
		}
		ans %= MOD;
		if(rows == 0 || cols == 0) break;
	}
	if(rows == 0 || cols == 0){
		cout << (ans % MOD) << endl;

	} else {
		cout << -1 << endl;
	}
}
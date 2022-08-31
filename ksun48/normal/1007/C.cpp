#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

struct polygon {
	pair<LL,LL> corner;
	vector<pair<LL,LL> > r;
};

polygon flip(polygon a){
	swap(a.corner.first, a.corner.second);
	for(pair<LL,LL>& x : a.r){
		swap(x.first, x.second);
	}
	return a;
}

polygon organize(polygon a){
	for(pair<LL,LL> & x : a.r){
		x.first = max(x.first, a.corner.first);
		x.second = max(x.second, a.corner.second);
	}
	sort(a.r.begin(), a.r.end());
	vector<pair<LL,LL> > newr;
	for(pair<LL,LL> x : a.r){
		if(newr.size() > 0 && x.second >= newr[newr.size() - 1].second){
			continue;
		}
		newr.push_back(x);
	}
	a.r = newr;
	return a;
}

polygon cutx(polygon a, LL v){
	a.corner.first = max(a.corner.first, v);
	return a;
}
polygon cuty(polygon a, LL v){
	return flip(cutx(flip(a), v));
}

polygon cutz(polygon a, pair<LL,LL> pt){
	a.r.push_back(pt);
	return a;
}

double area(polygon a){
	a = organize(a);
	LL xsum = 0;
	double totalarea = 0.0;
	for(int j = 0; j + 1 < a.r.size(); j++){
		LL dx = a.r[j+1].first - a.r[j].first;
		LL dy = a.r[j].second - a.r[j+1].second;
		xsum += dx;
		totalarea += (double)(xsum) * (double)(dy);
	}
	return totalarea;
}

LL thirdx(polygon a){
	LL s = 0;
	LL e = 1100000000000000000LL;
	while(s + 1 < e){
		LL m = (s + e) / 2;
		if(area(cutx(a,m)) > (area(a) * 2.0 + 0.5) / 3.0){
			s = m;
		} else {
			e = m;
		}
	}
	return s;
}

LL thirdy(polygon a){
	return thirdx(flip(a));
}

void solve(){
	LL n;
	cin >> n;
	polygon cur;
	cur.corner = {1, 1};
	cur.r.push_back({1,n+1});
	cur.r.push_back({n+1,1});
	while(1){
		LL x = thirdx(cur);
		LL y = thirdy(cur);
		cout << x << " " << y << '\n';
		fflush(stdout);
		LL ans;
		cin >> ans;
		if(ans == 0){
			break;
		} else if(ans == 1){
			cur = cutx(cur, x + 1);
		} else if(ans == 2){
			cur = cuty(cur, y + 1);
		} else if(ans == 3){
			cur = cutz(cur, {x,y});
		}
	}
}
int main(){
	solve();
}
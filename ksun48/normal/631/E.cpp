#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n;
LL a[210000];
LL need[210000];
LL curmax;
LL orig = 0;
LL maxdiff = 0;
void solve(){
	curmax = -10000000;
	for(LL i = n; i >= 1; i--){
		if(a[i] > curmax){
			curmax = a[i];
			need[i] = 1;
		} else {
			need[i] = 0;
		}
	}
	deque<pair<LL,LL> > points;
	LL sum = 0;
	points.push_back(make_pair(0,sum));
	for(LL i = 1; i < n; i++){
		sum += a[i];
		points.push_back(make_pair(i,sum));
		while(points.size() > 2){
			LL c = points.size();
			LL x2 = points[c-1].first-points[c-2].first;
			LL x1 = points[c-2].first-points[c-3].first;
			LL y2 = points[c-1].second-points[c-2].second;
			LL y1 = points[c-2].second-points[c-3].second;
			if(y2*x1 >= x2*y1){
				pair<LL,LL> z = points[c-1];
				points.pop_back();
				points.pop_back();
				points.push_back(z);
			} else {
				break;
			}
		}
	}
	sum = 0;
	for(LL i = 1; i < n; i++){
		sum += a[i];
		if(need[i+1]){
			LL r = i*a[i+1]-sum;
			while(points.size() > 1 && points[1].first <= i){
				LL v0 = points[0].second-points[0].first*a[i+1];
				LL v1 = points[1].second-points[1].first*a[i+1];
				//cout << v0 + r << " " << v1 + r << endl;
				if(v0 > v1) break;
				points.pop_front();
			}
			//cout << points[0].first << " " << points[0].second << endl;
			maxdiff = max(maxdiff, r+points[0].second-points[0].first*a[i+1]);
		}
	}
}
int main(){
	cin >> n;
	for(LL i = 0; i < n; i++){
		cin >> a[i+1];
		orig += (i+1)*a[i+1];
	}
	for(LL i = 1; i < n+1-i; i++) swap(a[i],a[n+1-i]);
	solve();
	for(LL i = 1; i <= n; i++) a[i] *= -1;
	for(LL i = 1; i < n+1-i; i++) swap(a[i],a[n+1-i]);
	solve();
	cout << maxdiff + orig << endl;
}
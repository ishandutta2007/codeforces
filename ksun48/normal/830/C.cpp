#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	LL n, k;
	cin >> n >> k;
	LL a[n];
	for(LL i = 0; i < n; i++) cin >> a[i];
	LL best = 0;
	vector<LL> td;
	for(LL d = 1; d <= 500000; d++) td.push_back(d);

	vector<LL> cd;
	for(LL i = 0; i < n; i++){
		for(LL c = 1; c <= 2000; c++){
			cd.push_back(a[i]/c);
		}
	}
	cd.push_back(500000);
	for(LL i = 0; i < cd.size(); i++){
		LL d = cd[i];
		if(d <= 0) continue;
		td.push_back(d);
		LL ksum = 0;
		LL asum = 0;
		for(LL f = 0; f < n; f++){
			ksum += (a[f]+d-1)/d;
			asum += a[f];
		}
		td.push_back((k+asum)/ksum);
	}

	for(LL tt = 0; tt < td.size(); tt++){
		LL d = td[tt];
		if(d <= 0LL) continue;
		LL cur = 0;
		for(LL i = 0; i < n; i++){
			cur += (d-a[i]%d)%d;
		}
		if(cur <= k){
			best = max(d,best);
		}
	}	

	cout << best << endl;
}
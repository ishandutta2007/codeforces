#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	LL n, C;
	cin >> n >> C;
	LL s[n];
	LL d[n];
	d[0] = 0;

	for(int i = 0; i < n; i++){
		cin >> s[i];
		s[i] = min(C, s[i]);
		if(i < n-1) cin >> d[i];
	}
	d[n-1] = 0;

	LL a[n];

	multiset<LL> best;
	best.insert(0);
	LL z = 0;


	int cur = 0;
	LL curnsum = 0;

	LL ntotal = 0;
	LL atotal = 0;
	vector<LL> bestv, atot;
	bestv.push_back(0);
	atot.push_back(0);
	for(int i = 0; i < n; i++){
		a[i] = 0;
		ntotal += s[i];
		if(i > 0) ntotal += d[i-1];
		curnsum += s[i];
		if(i > 0) curnsum += d[i-1];
		while(curnsum > C){
			best.erase(best.find(bestv[cur]));
			curnsum -= s[cur];
			curnsum -= d[cur];
			cur++;
		}
		//cout << curnsum << " " << cur << endl;
		//try cur - 1 anyway
		if(cur > 0){
			a[i] = max(a[i], C - atot[i] + atot[cur-1]);
		}

		//cout << "total " << ntotal << " " << atotal << endl;
		if(!best.empty()){
			//cout << -*best.begin() << endl;
			a[i] = max(a[i], -*best.begin()+ntotal-atotal);
		}

		z -= s[i];
		z -= d[i];
		z += a[i];
		best.insert(-z);
		bestv.push_back(-z);
		atotal += a[i];
		//cout << a[i] << endl;
		atot.push_back(atotal);
	}
	cout << atotal << endl;
}
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
pair<LL,LL> pts[500000];
LL r = 0;
int main(){
	LL n;
	cin >> n;
	LL p[n];
	LL t[n];
	for(LL i = 0; i < n; i++){
		cin >> p[i];
	}
	LL T = 0;
	for(LL i = 0; i < n; i++){
		cin >> t[i];
		T += t[i];
	}
	pair<double,pair<LL,LL> > x[n];
	LL newp[n];
	LL newt[n];
	for(LL i = 0; i < n; i++){
		x[i].first = -((double)p[i])/((double)t[i]);
		x[i].second.first = -p[i];
		x[i].second.second = -t[i];
	}
	sort(x,x+n);
	for(LL i = 0; i < n; i++){
		newp[i] = x[i].second.first * -1;
		newt[i] = x[i].second.second * -1;
		//	cout << newp[i] << " " << newt[i] << endl;
	}
	LL s = 0;
	LL totaltime = 0;
	while(s < n){
		LL e=s;
		LL mintime = totaltime;
		LL maxtime = mintime + newt[e];
		while(e < n-1 && newp[e]*newt[e+1] == newp[e+1]*newt[e]){
			e++;
			maxtime += newt[e];
		}
		for(LL i = s; i <= e; i++){
			pts[r++] = make_pair(newp[i],-(mintime+newt[i]));
			pts[r++] = make_pair(newp[i],-maxtime);
		}
		s = e+1;
		totaltime = maxtime;
	}
	sort(pts,pts+r);
	double c = 1;
	for(LL i = 0; i < r; i++){
		pts[i].second *= -1;
		//cout << pts[i].first << " " << pts[i].second << endl;
	}
	for(LL i = 0; i < r-1; i++){
		if(pts[i].first < pts[i+1].first){
			double z = (double)T;
			z *= (double)(pts[i+1].first - pts[i].first);
			double den = (double)(pts[i+1].first*pts[i+1].second - pts[i].first*pts[i].second);
			if(den < 0) continue;
			c = min(c,z/den);
		}
	}
	printf("%.11lf\n",c);
}
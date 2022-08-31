#include<bits/stdc++.h>
#define EPS 0.0000001
#define PI 3.14159265358979
using namespace std;
typedef long long LL;
typedef double ld;
int n;
ld a;
pair<ld,ld> stuff[100001];
pair<ld,int> pts[200001];
int sz = 0;
int main(){
	cin >> n >> a;
	for(int i = 0; i < n; i++) cin >> stuff[i].first >> stuff[i].second;
	ld s = 0;
	ld e = a;
	for(int tt = 0; tt < 100; tt++){	
		ld qb = (s+e)/2;
		ld l = sqrt(a*a-qb*qb);
		sz = 0;
		//cout << qb << " " << l << " OK" << endl;
		//cout << endl << "NEW" << " " << qb << " " << l << endl;
		for(int i = 0; i < n; i++){
			ld x1 = qb/stuff[i].first*stuff[i].second/l;
			ld y1 = qb/stuff[i].first;
			if(isnan(x1)) x1 = 0;
			if(x1*x1 + y1*y1 < 1.0) continue;
			//cout << x1 << " " << y1 << endl;
			ld c = atan2(l,stuff[i].second)+acos(1.0/sqrt(x1*x1+y1*y1));
			ld d = atan2(l,stuff[i].second)-acos(1.0/sqrt(x1*x1+y1*y1));
			if(l*y1 < -EPS){
				c += PI;
				d += PI;
			}
			if(c < 0) c += 2*PI;
			if(d < 0) d += 2*PI;
			if(c > 2*PI) c -= 2*PI;
			if(d > 2*PI) d -= 2*PI;
			//cout << stuff[i].first << " " << stuff[i].second << " " << x1 << " " << y1 << " " << c << " " << d << endl;
			pts[sz++] = make_pair(c,i);
			pts[sz++] = make_pair(d,i);
		}
		sort(pts, pts+sz);
		vector<int> r;
		for(int i = 0; i < sz; i++){
			r.push_back(pts[i].second);
			if(r.size() >= 2 && r[r.size()-1] == r[r.size()-2]){
				r.pop_back();
				r.pop_back();
			}
		}
		if(r.empty()) s = qb;
		else e = qb;
	}
	printf("%.11lf\n", 2.0*e);

}
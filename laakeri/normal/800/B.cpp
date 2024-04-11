#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef complex<ld> co;

ld pointLineDistance(co p, co a, co b) {
	return abs(((p-a)/(b-a)).Y)*abs(b-a);
}

co p[1010];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	for (int i=0;i<n;i++){
		int x,y;
		cin>>x>>y;
		p[i]={(ld)x, (ld)y};
	}
	ld v=1e18;
	for (int i=0;i<n;i++){
		co tp=p[i];
		co ep=p[(i+n-1)%n];
		co np=p[(i+1)%n];
		v=min(v, pointLineDistance(tp, ep, np)/(ld)2);
	}
	cout<<setprecision(15)<<v<<endl;
}
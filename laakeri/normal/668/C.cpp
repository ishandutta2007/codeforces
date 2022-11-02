#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef double ld;
const ld eps=1e-10;

ld mi[101010];
ld ma[101010];

ld v1[101010];
ld v2[101010];

ld sq(ld x) {return x*x;}

pair<ld, ld> solve(ld a, ld b){
	ld d=sqrt(max((ld)0, sq(a+b)-4*a));
	return {0.5*(-d+a+b), 0.5*(d+a+b)};
}

int main(){
	int n;
	scanf("%d", &n);
	for (int i=0;i<n;i++){
		scanf("%lf", &ma[i]);
		if (i) ma[i]+=ma[i-1];
	}
	for (int i=0;i<n;i++){
		scanf("%lf", &mi[i]);
		if (i) mi[i]+=mi[i-1];
	}
	for (int i=0;i<n;i++){
		auto t=solve(ma[i], mi[i]);
		v1[i]=t.F;
		v2[i]=t.S;
	}
	ld su=0;
	for (int i=0;i<n;i++){
		printf("%0.10lf ", v1[i]-su);
		su+=v1[i]-su;
	}
	cout<<endl;
	su=0;
	for (int i=0;i<n;i++){
		printf("%0.10lf ", v2[i]-su);
		su+=v2[i]-su;
	}
	cout<<endl;
}
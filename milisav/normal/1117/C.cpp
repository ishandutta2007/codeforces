#include<bits/stdc++.h>
using namespace std;
long long n;
long long x[2];
long long y[2];
char s[200000];
long long dx,dy;
long long a=0,b=0;
long long cx=0,cy=0;
bool pos(long long d) {
	long long k=d/n;
	long long px=k*cx,py=k*cy;
	for(long long i=0;i<d-k*n;i++) {
		if(s[i]=='U') py++;
		if(s[i]=='D') py--;
		if(s[i]=='R') px++;
		if(s[i]=='L') px--;
	}
	px+=x[0];
	py+=y[0];
	if(abs(px-x[1])+abs(py-y[1])<=d) return true;
	return false;
}
int main()
{
	scanf("%lld %lld",&x[0],&y[0]);
	scanf("%lld %lld",&x[1],&y[1]);
	scanf("%lld",&n);
	scanf("%s",s);
	for(long long i=0;i<n;i++) {
		if(s[i]=='U') cy++;
		if(s[i]=='D') cy--;
		if(s[i]=='R') cx++;
		if(s[i]=='L') cx--;
	}
	long long l=0;
	long long r=2;
	long long m;
	for(long long i=0;i<18;i++) r*=10;
	while(l<r) {
		//cout<<l<<" "<<r<<endl;
		m=(l+r)>>1ll;
		if(pos(m)) r=m;
		else l=m+1;
	}
	if(pos(l)) printf("%lld",l);
	else printf("-1");
	return 0;
}
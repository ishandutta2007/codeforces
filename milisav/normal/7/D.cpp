#include<bits/stdc++.h>
using namespace std;
int n;
char s[6000000];
int h[6000000];
int v[6000000];
long long mod=1000000007;
long long a=10007;
int p[6000000];
long long modinv(long long x)
{
	long long c=mod-2;
	long long b=x,r=1;
	while(c>0) {
		if((c&1)) {
			r=r*b;
			r%=mod;
		}
		b=b*b;
		b%=mod;
		c=(c>>1);
	}
	return r;
}
int hs()
{
	long long c,b;
	long long d=0;
	c=0;
	b=1;
	p[0]=1;
	int sol=0;
	long long f=modinv(a);
	for(int i=0;i<n;i++) {
		c=c*a+s[i];
		c%=mod;
		h[i]=c;
		//cout<<i<<" "<<h[i]<<endl;
		if(i>0) {
			if(i%2==0) {
				d-=s[i/2];
				d%=mod;
				if(d<0) d+=mod;
				d*=f;
				d+=s[i]*b;
				d%=mod;
				b=b*a;
				b%=mod;
			}
			else {
				d+=s[i]*b;
				d%=mod;
			}
			//cout<<i<<" "<<d<<" "<<h[(i-1)/2]<<endl;
			if(d==h[(i-1)/2]) {
				p[i]=p[(i-1)/2]+1;
			}
		}
		sol+=p[i];
	}
	return sol;
}
int main()
{
	scanf("%s",s);
	n=strlen(s);
	printf("%d",hs());
}
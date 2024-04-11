#include<bits/stdc++.h>
using namespace std;
vector<int> primes;
bool c[1000000];
int n;
long long x[300000];
long long appart(long long y,long long s) {
	long long h,ming=-1,a,b;
	for(long long g=1;g*g<=y;g++) {
		if(y%g==0) {
			h=y/g;
			if((h-g)%2LL==0) {
				b=(h+g)>>1LL;
				a=(h-g)>>1LL;
				if(a*a-s<=0) return ming;
				ming=g;
			}
		}
	}
	return ming;
}
int main()
{
	for(int i=2;i<=1000;i++) {
		if(!c[i]) {
			for(int j=i*i;j<=300000;j=j+i) {
				c[j]=true;
			}
		}
	}
	for(int i=1;i<=300000;i++) if(!c[i]) primes.push_back(i);
	scanf("%d",&n);
	for(int i=0;i<n/2;i++) {
		scanf("%lld",&x[i*2+1]);
	}
	long long g,h,a,b;
	long long s=0;
	for(int i=1;i<n;i=i+2) {
		g=appart(x[i],s);
		//cout<<i<<" "<<x[i]<<" "<<g<<endl;
		if(g==-1) {
			printf("No");
			return 0;
		}
		h=x[i]/g;
		b=(g+h)>>1LL;
		a=abs((h-g)>>1LL);
		x[i-1]=a*a-s;
		s=b*b;
		if(x[i-1]<=0) {
			printf("No");
			return 0;
		}
	}
	printf("Yes\n");
	for(int i=0;i<n;i++) printf("%lld ",x[i]);
	return 0;
}
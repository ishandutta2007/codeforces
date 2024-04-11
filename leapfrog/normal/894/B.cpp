#include<bits/stdc++.h>
using namespace std;
const int P=1e9+7;long long n,m;int k;
inline int ksm(int x,long long q) {int r=1;for(;q;q>>=1,x=1ll*x*x%P) if(q&1) r=1ll*r*x%P;return r;}
int main()
{
	scanf("%lld%lld%d",&n,&m,&k);
	if(((n+m)&1)&&k==-1) return puts("0"),0;else return printf("%d\n",ksm(ksm(2,n-1),m-1)),0;
}
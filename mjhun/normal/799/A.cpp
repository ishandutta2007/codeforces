#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
using namespace std;
typedef long long ll;

ll n,t,k,d;

int main(){
	scanf("%lld%lld%lld%lld",&n,&t,&k,&d);
	ll tt=(n+k-1)/k*t;
	tt--;
	ll m=tt/t*k+(tt-d)/t*k;
	if(m>=n)puts("YES");
	else puts("NO");
	return 0;
}
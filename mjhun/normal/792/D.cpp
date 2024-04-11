#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
using namespace std;
typedef long long ll;

ll n;int q,l;
char s[100005];

ll move(ll x, char d){
	int h=0;
	while(!(x&(1LL<<h)))h++;
	if(d=='L'){
		if(!h)return x;
		return x-(1LL<<(h-1));
	}
	if(d=='R'){
		if(!h)return x;
		return x+(1LL<<(h-1));
	}
	if(h==l-1)return x;
	if(x&(1LL<<(h+1)))return x-(1LL<<h);
	return x+(1LL<<h);
}

int main(){
	scanf("%lld%d",&n,&q);
	while((n+1)!=(1LL<<l))l++;
	while(q--){
		ll x;
		scanf("%lld%s",&x,s);
		for(int i=0;s[i];++i)x=move(x,s[i]);
		printf("%lld\n",x);
	}
	return 0;
}
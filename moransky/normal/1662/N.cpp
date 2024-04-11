// xtqqwq
#include<bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template<typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}
template<typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n;
int cx[1505],cy[1505];
pii p[2500005];

int main(){
	n=readint();
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) p[readint()]=mp(i,j);
	ll ans=0;
	for(int i=1;i<=n*n;i++){
		int x=p[i].fi,y=p[i].se;
		ans+=1ll*cx[x]*(n-1-cy[y])+1ll*(n-1-cx[x])*cy[y];
		cx[x]++,cy[y]++;
	}
	printf("%lld\n",ans/2);
	return 0;
}
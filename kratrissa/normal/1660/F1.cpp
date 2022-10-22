#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int T,n,c[N],bit[3][N<<1];char s[N];ll ans;
void add(int t,int x){for(;x<=(n+2<<1);x+=x&-x)bit[t][x]++;}
int query(int t,int x){int res=0;for(;x;x-=x&-x)res+=bit[t][x];return res;}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%s",&n,s+1),ans=0;
		for(int i=1;i<=n;i++)c[i]=c[i-1]+(s[i]=='+'?-1:1);
		for(int i=0;i<3;i++)fill(bit[i],bit[i]+(n+2<<1)+1,0);
		for(int i=0;i<=n;i++)ans+=query((c[i]%3+3)%3,c[i]+n+2),add((c[i]%3+3)%3,c[i]+n+2);
		printf("%lld\n",ans);
	}
	return 0;
}
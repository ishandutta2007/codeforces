#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
int T,n,a[N],cc,f[N],mx[N],bit1[N],bit2[N];ll s[N],A[N];
void modify1(int x,int y){for(;x<=cc;x+=x&-x)bit1[x]=max(bit1[x],y);}
void modify2(int x,int y){for(;x<=cc;x+=x&-x)bit2[x]=max(bit2[x],y);}
int query1(int x){int res=-1e9;for(;x;x-=x&-x)res=max(res,bit1[x]);return res;}
int query2(int x){int res=-1e9;for(;x;x-=x&-x)res=max(res,bit2[x]);return res;}
void solve(){
	scanf("%d",&n),A[n+1]=s[0]=0;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),A[i]=s[i]=s[i-1]+a[i];
	sort(A+1,A+n+2),cc=unique(A+1,A+n+2)-A-1;
	for(int i=0;i<=n;i++)s[i]=lower_bound(A+1,A+cc+1,s[i])-A;
	fill(bit1,bit1+cc+1,-1e9),fill(bit2,bit2+cc+1,-1e9),fill(mx,mx+cc+1,-1e9);
	modify1(s[0],0),modify2(cc-s[0]+1,0),mx[s[0]]=0;
	for(int i=1;i<=n;i++)
		f[i]=max(mx[s[i]],max(query1(s[i]-1)+i,query2(cc-s[i])-i)),modify1(s[i],f[i]-i),modify2(cc-s[i]+1,f[i]+i),mx[s[i]]=max(mx[s[i]],f[i]);
	printf("%d\n",f[n]);
}
int main(){
	scanf("%d",&T);
	while(T--)solve();
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define N 200005
#define S 450
#define int long long
int read(){
	int w=0,f=1;
	char c=' ';
	while(c<'0'||c>'9')c=getchar(),f=c=='-'?-1:f;
	while(c>='0'&&c<='9')w=w*10+c-48,c=getchar();
	return w*f;
}
const int mod=1e9+7,inv=(mod+1)>>1;
int pown(int x,int y){
	int res=1;
	while(y){
		if(y&1)res=res*x%mod;
		x=x*x%mod,y>>=1;
	}
	return res;
}
int T,n,m,k,a[N],f[N],bel[N],now1,now2,now3,inv6;
struct node{
	int l,r,d,ans;
}q[N];
int cnt[N],len;
bool cmp1(int x,int y){
	return q[x].r<q[y].r;
}
bool cmp2(int x,int y){
	return q[x].r>q[y].r;
}
vector<int>b[N/S+2];
void ins(int x){
	cnt[f[x]]++;
	if(cnt[f[x]]>1)return;
	x=a[x],len++;
	now1=(now1+x)%mod;
	now2=(now2+x*x)%mod;
	now3=(now3+x*x%mod*x)%mod;
}
void del(int x){
	cnt[f[x]]--;
	if(cnt[f[x]]>0)return;
	x=a[x],len--;
	now1=(now1-x+mod)%mod;
	now2=(now2-x*x%mod+mod)%mod;
	now3=(now3-x*x%mod*x%mod+mod)%mod;
}
void init(){
	for(int i=1;(i-1)*S<n;i++){
		int l=(i-1)*S+1,r=min(i*S,n);
		for(int j=l;j<=r;j++)
			bel[j]=i;
	}
	inv6=pown(6,mod-2);
}
int calc(int x){
	return x*(len-1)%mod*len%mod*inv%mod;
}
int calc2(int x,int d){
	int s1=x*x%mod*len%mod;
	int s2=d*d%mod*(len-1)%mod*len%mod*(len*2-1)%mod*inv6%mod;
	int s3=x*d*2%mod*(len-1)%mod*len%mod*inv%mod;
	return (s1+s2+s3)%mod;
}
int sq(int x){
	return x*x%mod;
}
int calc3(int x,int d){
	int s1=x*x%mod*x%mod*len%mod;
	int s2=d*d%mod*d%mod*sq((len-1)%mod*len%mod*inv%mod)%mod;
	int s3=x*x%mod*d*3%mod*(len-1)%mod*len%mod*inv%mod;
	int s4=d*d%mod*x*3%mod*(len-1)%mod*len%mod*(len*2-1)%mod*inv6%mod;
	return (s1+s2+s3+s4)%mod;
}
map<int,int>mp;
signed main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		if(mp[a[i]])f[i]=mp[a[i]];
		else f[i]=i,mp[a[i]]=i;
	}
	init();
	for(int i=1;i<=m;i++)
		q[i].l=read(),q[i].r=read(),q[i].d=read(),b[bel[q[i].l]].push_back(i);
	for(int i=1;i<=bel[n];i++)
		if(i&1)sort(b[i].begin(),b[i].end(),cmp1);
		else sort(b[i].begin(),b[i].end(),cmp2);
	int l=1,r=0;
	for(int B=1;B<=bel[n];B++)
		for(auto i:b[B]){
			while(l>q[i].l)ins(--l);
			while(r<q[i].r)ins(++r);
			while(l<q[i].l)del(l++);
			while(r>q[i].r)del(r--);
			int st=(now1-calc(q[i].d)+mod)*pown(len,mod-2)%mod;
			if(now2==calc2(st,q[i].d)&&now3==calc3(st,q[i].d))q[i].ans=1;
			else q[i].ans=0;
		}
	for(int i=1;i<=m;i++)
		puts(q[i].ans?"Yes":"No");
	return 0;
}
#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define LL long long
#define INF 2147483233
#define MAXN 100+1000000
using namespace std;
inline LL read(){
	LL x=0,f=1; char ch=getchar();
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=-1;
	for(;isdigit(ch);ch=getchar())x=ch-'0'+(x<<3)+(x<<1);
	return x*f;
}
inline void write(LL n){
	char ch[24]; LL top=0;
	if(n<0)putchar('-'),n=-n;
	while(n)ch[++top]=n%10+'0',n/=10;
	while(top)putchar(ch[top--]);
	return ;
}
int n; LL t;
int rnd[MAXN]; LL num[MAXN]; int cnt[MAXN];
int rt,size,lch[MAXN],rch[MAXN],big[MAXN];
void iinit(){rt=0,size=0;return ;}
inline void update(int u){
	big[u]=big[lch[u]]+big[rch[u]]+cnt[u];
	return ;
}
inline void lturn(int &u){
	LL t=rch[u];rch[u]=lch[t],lch[t]=u;
	big[t]=big[u],update(u),u=t;return ;
}
inline void rturn(int &u){
	LL t=lch[u];lch[u]=rch[t],rch[t]=u;
	big[t]=big[u],update(u),u=t;return ;
}
void insert(int &cur,LL x){
	if(cur==0){
		cur=++size,num[cur]=x;
		cnt[cur]=1,rnd[cur]=rand();
		big[cur]=1; return ;
	}
	big[cur]++; 
	if(num[cur]==x)cnt[cur]++;
	else if(x>num[cur]){
		insert(rch[cur],x);
		if(rnd[rch[cur]]<rnd[cur])lturn(cur);
	}
	else {
		insert(lch[cur],x);
		if(rnd[lch[cur]]<rnd[cur])rturn(cur);
	}
	return ;
}
void del(int &k,LL x){
	if(k==0)return ;
	else if(num[k]==x){
		if(cnt[k]>1){cnt[k]--,big[k]--;return ;}
		if(lch[k]*rch[k]==0){k=lch[k]+rch[k];return ;}
		if(rnd[lch[k]]>rnd[rch[k]])lturn(k),del(lch[k],x);
		else rturn(k),del(rch[k],x);
	}
	else if(num[k]>x)big[k]--,del(lch[k],x);
	else big[k]--,del(rch[k],x);
	update(k); return ;
}
int fuck(int cur,LL x){
	if(cur==0)return 0;
	if(num[cur]<=x)return fuck(rch[cur],x);
	else return big[cur]-big[lch[cur]]+fuck(lch[cur],x);
}
int main()
{
	iinit(); LL ans=0;
	n=read(),t=read(); insert(rt,0);
	for (LL i=1,s=0;i<=n;i++){
		s+=read();ans+=fuck(rt,s-t);
		insert(rt,s);
	}
	printf("%I64d",ans);
}
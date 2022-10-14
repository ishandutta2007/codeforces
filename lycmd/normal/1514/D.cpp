#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
#define gc() (uu==vv&&(vv=(uu=cc)+fread(cc,1,1<<21,stdin),uu==vv)?EOF:*uu++)
#define pc(c) (*o++=(c))
using namespace std;
int const N=2333333,M=23333333;
char cc[M],*uu=cc,*vv=cc,buf[M],*p1=buf,*p2=buf,obuf[N],*o=obuf;
int n,b,q,cur,col,a[N],cnt[N],ccnt[N],ans[N];
struct query{
	int l,r,id;
	int operator<(const query&rhs)const{
		return l/b<rhs.l/b||l/b==rhs.l/b&&(l/b%2?r<rhs.r:r>rhs.r);
	}
}p[N];
int read(){
	char c=gc();
	int x=0;
	while(c<48||c>57)c=gc();
	while(c>47&&c<58)x=(x<<3)+(x<<1)+(c^48),c=gc();
	return x;
} 
void write(int x){
	if(x>9)write(x/10);
	pc((x%10)|48);
}
void add(int x){
	ccnt[cnt[a[x]]]--,ccnt[++cnt[a[x]]]++;
	while(ccnt[cur+1])cur++;
}
void del(int x){
	ccnt[cnt[a[x]]]--,ccnt[--cnt[a[x]]]++;
	while(!ccnt[cur])cur--;
}
signed main(){
	n=read(),q=read(),b=sqrt(n);
	for(int i=1;i<=n;i++)
		a[i]=read();
	for(int i=1;i<=q;i++)
		p[i].l=read(),p[i].r=read(),p[i].id=i;
	sort(p+1,p+1+q),ccnt[0]++;
	int l=1,r=0;
	for(int i=1;i<=q;i++){
		while(l<p[i].l)del(l++);
		while(l>p[i].l)add(--l);
		while(r<p[i].r)add(++r);
		while(r>p[i].r)del(r--);
		ans[p[i].id]=max(1ll,2*cur-p[i].r+p[i].l-1);
	}
	for(int i=1;i<=q;i++)
		write(ans[i]),pc(10);
	fwrite(obuf,o-obuf,1,stdout);
	return 0;
}
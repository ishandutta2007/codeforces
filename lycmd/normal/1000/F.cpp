#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define gc() (uu==vv&&(vv=(uu=cc)+fread(cc,1,1<<21,stdin),uu==vv)?EOF:*uu++)
#define pc(c) (*o++=(c))
using namespace std;
int const N=500010,M=23333333;
char cc[M],*uu=cc,*vv=cc,buf[M],*p1=buf,*p2=buf,obuf[N],*o=obuf;
int n,q,B,cur,top,a[N],s[N],pos[N],cnt[N],ans[N];
struct query{
	int l,r,id;
	int operator<(const query&rhs)const{
		return l/B<rhs.l/B||l/B==rhs.l/B&&(l/B%2?r<rhs.r:r>rhs.r);
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
void add(int t){
	cnt[t]++;
	if(cnt[t]==1)
		s[pos[t]=++top]=t;
	else if(cnt[t]==2)
		s[pos[s[top]]=pos[t]]=s[top],s[top--]=pos[t]=0;
}
void del(int t){
	if(cnt[t]==2)
		s[pos[t]=++top]=t;
	else if(cnt[t]==1)
		s[pos[s[top]]=pos[t]]=s[top],s[top--]=pos[t]=0;
	cnt[t]--;
}
int main(){
	B=sqrt(n=read());
	for(int i=1;i<=n;i++)
		a[i]=read();
	q=read();
	for(int i=1;i<=q;i++)
		p[i].l=read(),p[i].r=read(),p[i].id=i;
	sort(p+1,p+1+q);
	int l=1,r=0;
	for(int i=1;i<=q;i++){
		while(l<p[i].l)del(a[l++]);
		while(l>p[i].l)add(a[--l]);
		while(r<p[i].r)add(a[++r]);
		while(r>p[i].r)del(a[r--]);
		ans[p[i].id]=s[top];
	}
	for(int i=1;i<=q;i++)
		write(ans[i]),pc(10);
	fwrite(obuf,o-obuf,1,stdout);
	return 0;
}
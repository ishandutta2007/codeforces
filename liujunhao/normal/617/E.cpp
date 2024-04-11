#include<cstdio>
#include<algorithm>
#include<cmath>
#define MAXN 100000
#define MAXM 100000
#define MAXK 1000000
using namespace std;
int block[MAXN+10],n,m,a[MAXN+10],k,cnt[MAXK*2+10],sum[MAXN+10];
long long ans[MAXM+10];
void Read(int &x){
	char c;
	while(c=getchar(),c!=EOF)
		if(c>='0'&&c<='9'){
			x=c-'0';
			while(c=getchar(),c>='0'&&c<='9')
				x=x*10+c-'0';
			ungetc(c,stdin);
			return;
		}
}
struct node{
	int l,r,i;
	bool operator<(const node& x)const{
		if(block[l]==block[x.l])
			return r<x.r;
		return block[l]<block[x.l];
	}
}q[MAXM+10];
void init(){
	Read(n),Read(m),Read(k);
	int i,t=sqrt(n+0.5);
	for(i=1;i<=n;i++){
		Read(a[i]),sum[i]=sum[i-1]^a[i];
		block[i]=(i+t-1)/t;
	}
	for(i=1;i<=m;i++){
		Read(q[i].l),Read(q[i].r);
		q[i].l--;
		q[i].i=i;
	}
	sort(q+1,q+m+1);
}
void solve(){
	int i,l=0,r=-1;
	long long ansn=0;
	for(i=1;i<=m;i++){
		while(r<q[i].r)
			ansn+=cnt[sum[++r]^k],cnt[sum[r]]++;
		while(r>q[i].r)
			cnt[sum[r]]--,ansn-=cnt[sum[r--]^k];
		while(l<q[i].l)
			cnt[sum[l]]--,ansn-=cnt[sum[l++]^k];
		while(l>q[i].l)
			ansn+=cnt[sum[--l]^k],cnt[sum[l]]++;
		ans[q[i].i]=ansn;
	}
}
void print(){
	for(int i=1;i<=m;i++)
		printf("%I64d\n",ans[i]);
}
int main()
{
	init();
	solve();
	print();
}
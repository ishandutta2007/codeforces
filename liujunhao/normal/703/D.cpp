#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
#include<cmath>
using namespace std;
template<class T>
void Read(T &x){
	static char c;
	bool f(0);
	while(c=getchar(),c!=EOF){
		if(c=='-')
			f=1;
		else if(c>='0'&&c<='9'){
			x=c-'0';
			while(c=getchar(),c>='0'&&c<='9')
				x=x*10+c-'0';
			if(f)
				x=-x;
			ungetc(c,stdin);
			return;
		}
	}
}
#define MAXN 1000000
int c[MAXN+10],n,a[MAXN+10],m,r[MAXN+10],rcnt,l[MAXN+10],la[MAXN+10],sum[MAXN+10],ans[MAXN+10];
struct Query{
	int l,r,pos;
}q[MAXN+10];
inline int lowbit(int x){
	return x&-x;
}
void update(int x,int d){
	while(x<=n){
		c[x]^=d;
		x+=lowbit(x);
	}
}
int get_sum(int x){
	int ret=0;
	while(x){
		ret^=c[x];
		x-=lowbit(x);
	}
	return ret;
}
inline bool cmp(Query x,Query y){
	return x.r<y.r;
}
int main()
{
	Read(n);
	for(int i=1;i<=n;i++){
		Read(a[i]);
		r[i]=a[i];
		sum[i]=sum[i-1]^a[i];
	}
	sort(r+1,r+n+1);
	rcnt=unique(r+1,r+n+1)-r-1;
	for(int i=1;i<=n;i++){
		a[i]=lower_bound(r+1,r+rcnt+1,a[i])-r;
		l[i]=la[a[i]]+1;
		la[a[i]]=i;
	}
	Read(m);
	for(int i=1;i<=m;i++)
		Read(q[i].l),Read(q[i].r),q[i].pos=i;
	sort(q+1,q+m+1,cmp);
	int now=1,i;
	for(i=1;i<=m;i++){
		while(now<=q[i].r){
			update(l[now],r[a[now]]);
			update(now+1,r[a[now]]);
			now++;
		}
		ans[q[i].pos]=get_sum(q[i].l)^sum[q[i].r]^sum[q[i].l-1];
	}
	for(i=1;i<=m;i++)
		printf("%d\n",ans[i]);
}
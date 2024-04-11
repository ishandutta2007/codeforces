#pragma GCC target("avx")
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define F(i,j,n) for(int i=j;i<=n;i++)
#define D(i,j,n) for(int i=j;i>=n;i--)
#define ll long long
#define maxn 1000005
#define maxm 1000005
template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
    while(c < '0' || c > '9') { if(c == '-') fu = -1; c = getchar(); }
    while(c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}

template <typename T>
void print(T x) {
    if(x < 0) putchar('-'), x = -x;
    if(x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

using namespace std;
int n,cnt,tot;
int ans[maxn],c[maxn];
struct data{int flag,x,y,v,pos,id;}a[maxm],b[maxm];

inline bool cmp(data a,data b)
{
	if (a.x!=b.x) return a.x<b.x;
	return a.pos<b.pos;
}
inline void add(int x,int y)
{
	for(;x<=n;x+=(x&(-x))) c[x]+=y;
}
inline int query(int x)
{
	int ret=0;
	for(;x;x-=(x&(-x))) ret+=c[x];
	return ret;
}
inline void solve(int l,int r)
{
	if (l>=r) return;
	int mid=(l+r)>>1,l1=l,l2=mid+1;
	F(i,l,r)
	{
		if (a[i].flag==1&&a[i].pos<=mid) add(a[i].y,a[i].v);
		if (a[i].flag==2&&a[i].pos>mid) ans[a[i].id]+=a[i].v*query(a[i].y);
	}
	F(i,l,r) if (a[i].flag==1&&a[i].pos<=mid) add(a[i].y,-a[i].v);
	F(i,l,r)
	{
		if (a[i].pos<=mid) b[l1++]=a[i];
		else b[l2++]=a[i];
	}
	F(i,l,r) a[i]=b[i];
	solve(l,mid);solve(mid+1,r);
}
const int N = 1e6 + 5;
int A[N], B[N], pa[N], pb[N], m;

int main()
{
	read(n); read(m);
    for(register int i = 1; i <= n; i++) {
    	read(A[i]); pa[A[i]] = i; 
    }
    for(register int i = 1; i <= n; i++) {
    	read(B[i]); pb[B[i]] = i;
    }
    for(register int i = 1; i <= n; i++) {
		cnt++;a[cnt]=(data){1,pa[i],pb[i],1,cnt,0};
	} 
    for(register int i = 1; i <= m; i++) {
    	int opt; read(opt);
    	if(opt == 1) {
    		int aa, b, c, d;
    		read(aa); read(c); read(b); read(d);
    		int x1=aa-1,y1=b-1,x2=c,y2=d;
			tot++;
			cnt++;a[cnt]=(data){2,x1,y1,1,cnt,tot};
			cnt++;a[cnt]=(data){2,x2,y2,1,cnt,tot};
			cnt++;a[cnt]=(data){2,x1,y2,-1,cnt,tot};
			cnt++;a[cnt]=(data){2,x2,y1,-1,cnt,tot};
    	}
    	if(opt == 2) {
    		int aa, b;
    		read(aa); read(b);
    		if(aa == b) continue;
//    		del(root, Point(pa[B[a]], pb[B[a]], 1), 0);
//    		del(root, Point(pa[B[b]], pb[B[b]], 1), 0);
    		cnt++;a[cnt]=(data){1,pa[B[aa]],pb[B[aa]],-1,cnt,0};
    		cnt++;a[cnt]=(data){1,pa[B[b]],pb[B[b]],-1,cnt,0};
    		swap(B[aa], B[b]); pb[B[aa]] = aa; pb[B[b]] = b;
    		cnt++;a[cnt]=(data){1,pa[B[aa]],pb[B[aa]],1,cnt,0};
    		cnt++;a[cnt]=(data){1,pa[B[b]],pb[B[b]],1,cnt,0};
    	}
    }
	sort(a+1,a+cnt+1,cmp);
	solve(1,cnt);
	F(i,1,tot) printf("%d\n",ans[i]);
	return 0;
}
#include<bits/stdc++.h>
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
using namespace std;
const int N=5e5+9;

inline int read() {
    register int x=0, f=1; register char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+c-48,c=getchar();}
    return x*f;
}

int n,k,a[N],b[N],ans;

struct num {int val,id;} c[N];
bool cmp(const num &a,const num &b) {return a.val<b.val;}
void discrete() {
	rep(i,1,n) c[i].val=a[i], c[i].id=i;
	sort(c+1,c+n+1,cmp);
	int cnt=0;
	rep(i,1,n) {
		if(c[i].val!=c[i-1].val) cnt++;
		a[c[i].id]=cnt;
	}
}

int s[N];
int lb(int x) {return x&(-x);}
void ins(int x,int val) {for(;x<=n+1;x+=lb(x)) s[x]=max(s[x],val);}
void clr(int x) {for(;x<=n+1;x+=lb(x)) s[x]=0;}
int qry(int x,int ret=0) {for(;x;x-=lb(x)) ret=max(ret,s[x]); return ret;}

int main() {
	scanf("%d%d",&n,&k);
	n++; a[1]=-0x3f3f3f3f; a[n+1]=n+1;
	rep(i,2,n) scanf("%d",&a[i]), a[i]-=i;
	rep(i,1,k) scanf("%d",&b[i]), b[i]++;
	b[0]=1, b[k+1]=n+1;
	discrete();
	rep(i,0,k) {
		if(a[b[i]]>a[b[i+1]]) return puts("-1"), 0;
		rep(j,b[i],b[i+1]) {
			if(a[j]<a[b[i]]) continue;
			int f=qry(a[j]);
			ins(a[j],f+1);
		}
		int res=b[i+1]-b[i]-qry(a[b[i+1]])+1;
		ans+=res;
		rep(j,b[i],b[i+1]) clr(a[j]);
	}
	printf("%d\n",ans);
	return 0;
}
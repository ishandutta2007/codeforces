#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a),i##_end=(b);i<=i##_end;i++)
#define per(i,a,b) for(int i=(b),i##_st=(a);i>=i##_st;i--)
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define debug(x) cerr<<#x" = "<<x<<endl
#define Debug(...) fprintf(stderr, __VA_ARGS__)
#define Es(x,i) for(Edge *i=G[x];i;i=i->nxt)
typedef pair<int,int> pii;
typedef long long ll;
const int inf=~0u>>1,MOD=1e9+7;/*
char *TT,*mo,but[(1<<15)+2];
#define getchar() ((TT==mo&&(mo=((TT=but)+fread(but,1,1<<15,stdin)),TT==mo))?-1:*TT++)//*/
inline int rd() {
	int x,c,f=1;while(!isdigit(c=getchar()))f=c!='-';x=c-'0';
	while(isdigit(c=getchar()))x=x*10+c-'0';return f?x:-x;
}
const int N=3e5+11;
int n,K,a[N];
bool judge(int M){
	bool vis[N];
	memset(vis,0,sizeof vis);
	vis[0]=1;
	int cnt=1;
	rep(i,1,n){
		while(a[i]-a[cnt]>M)cnt++;
		while(i-cnt+1>=K){
			if(vis[cnt-1]){
				vis[i]=1;
				break;
			}
			cnt++;
		}
	}
	return vis[n];
}
int main(){
	n=rd(),K=rd();
	if(K==1||n==1)return puts("0"),0;
	rep(i,1,n)a[i]=rd();
	sort(a+1,a+n+1);
	int l=inf,r=a[n]-a[1];
	rep(i,1,n-1){
		l=min(l,a[i+1]-a[i]);
	}
	while(l<r){
//		int mid=l+r>>1;
		int mid=l+r>>1;
//		debug(mid);
		if(judge(mid))r=mid;
		else l=mid+1;
	}
	cout<<l<<endl;
}
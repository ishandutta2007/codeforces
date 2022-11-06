#include<bits/stdc++.h>
#define int long long
using namespace std;
#define fi first
#define se second
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vp;
typedef unsigned long long ull;
typedef bitset<509> bset;
typedef pair<bset,bset> v2;

long long read() {
	long long res=0, w=1; char c=getchar();
	while(!isdigit(c)) {if(c=='-') w=-1; c=getchar();}
	while(isdigit(c)) {res=res*10+c-48, c=getchar();}
	return res*w;
}

const int N=1e6+9;
int T,n;
char s[N];

int solve(int l,int r,char c) {
	if(l==r) return s[l]!=c;
	int mid=l+r>>1;
	int cnt=0,ans=r-l+1;
	rep(i,l,mid) cnt+=(s[i]!=c);
	ans=min(ans,cnt+solve(mid+1,r,c+1));
	cnt=0;
	rep(i,mid+1,r) cnt+=(s[i]!=c);
	ans=min(ans,cnt+solve(l,mid,c+1));
	return ans;
}

signed main() {
	T=read();
	while(T--) {
		n=read();
		scanf("%s",s+1);
		printf("%lld\n",solve(1,n,'a'));
	}
	return 0;
}
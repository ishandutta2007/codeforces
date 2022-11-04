#include<bits/stdc++.h>
#define int long long
using namespace std;
#define fi first
#define se second
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef unsigned long long ull;

long long read() {
	long long res=0, w=1; char c=getchar();
	while(!isdigit(c)) {if(c=='-') w=-1; c=getchar();}
	while(isdigit(c)) {res=res*10+c-48, c=getchar();}
	return res*w;
}

const int N=5e5+9;

int n,t,tot,st;
int p[N],suf[N];
char s[N];

bool check(int x) {
	int pos=0,curt=0,endp=0;
	int cnt=x;
	while(endp<n&&cnt<tot) cnt+=(s[++endp]=='S');
	while(endp<n&&suf[endp+1]) endp++;
	if(cnt<tot) return 0;
	rep(i,1,endp) {
		curt++;
		if(s[i]=='S') {
			x++;
			if(x==0) {
				if(suf[i]==0) curt+=(i-pos);
				else curt+=2*(i-pos);
				pos=0;
			}
		} else if(s[i]=='H') {
			x--;
			if(x<0&&!pos) {
				pos=i;
				int nt=curt+2*(endp-i);
				if(nt<=t) return 1;
			}
		}
	}
	return curt<=t;
}

signed main() {
	n=read(), t=read();
	scanf("%s",s+1);
	rep(i,1,n) tot+=(s[i]=='H'), st+=(s[i]=='S');
	per(i,n,1) suf[i]=suf[i+1]+(s[i]=='H');
	int l=max(0ll,tot-st),r=n,ans=-1;
	while(l<=r) {
		int mid=(l+r)/2;
		if(check(mid)) r=mid-1, ans=mid;
		else l=mid+1;
	}
	printf("%lld\n",ans);
	return 0;
}
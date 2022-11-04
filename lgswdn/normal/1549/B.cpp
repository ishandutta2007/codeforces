#include<bits/stdc++.h>
#define int long long
using namespace std;
#define fi first
#define se second
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
typedef pair<int,int> pii;
typedef vector<int> vi;

long long read() {
	long long res=0, w=1; char c=getchar();
	while(!isdigit(c)) {if(c=='-') w=-1; c=getchar();}
	while(isdigit(c)) {res=res*10+c-48, c=getchar();}
	return res*w;
}

const int N=1e6+9;

int T,n;
char s[N],t[N];
bool vs[N];

signed main() {
	T=read();
	while(T--) {
		n=read();
		scanf("%s%s",s+1,t+1);
		rep(i,1,n) vs[i]=0; int ans=0;
		rep(i,1,n) if(t[i]=='1') {
			if(s[i-1]=='1'&&!vs[i-1]) vs[i-1]=1, ans++;
			else if(s[i]=='0'&&!vs[i]) vs[i]=1, ans++;
			else if(s[i+1]=='1'&&!vs[i+1]) vs[i+1]=1, ans++;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
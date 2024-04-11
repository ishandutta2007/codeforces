#include<bits/stdc++.h>
#define int long long
using namespace std;
#define fi first
#define se second
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define jmp(i,a,b,c) for(int i=(a);i<=(b);i+=(c))
#define pmj(i,a,b,c) for(int i=(a);i>=(b);i-=(c))
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vp;
typedef unsigned long long ull;

long long read() {
	long long res=0, w=1; char c=getchar();
	while(!isdigit(c)) {if(c=='-') w=-1; c=getchar();}
	while(isdigit(c)) {res=res*10+c-48, c=getchar();} 
	return res*w;
}

const int N=1009;
int m,n; long long ans;
char s[N][N];
vi h[N];
int b[N];

bool check(vector<int> &cnt,int tot=0) {
	for(auto x:cnt) if(x%2==1) tot++;
	return tot<2;
}
int Manacher(vector<vi> &t) {
	int tot=t.size()-1; vi f(tot+1,0); int r=-1,c=-1,res=0;
	rep(i,1,tot) {
		f[i]=(i>r?1:min(f[2*c-i],r-i+1));
		while(i+f[i]<=tot&&t[i-f[i]]==t[i+f[i]]) f[i]++;
		if(f[i]+i>r) r=f[i]+i-1, c=i;
		if(t[i][0]<=n*m) res+=f[i]/2;
	}
	return res;
}

signed main() {
	n=read(), m=read();
	rep(i,1,n) scanf("%s",s[i]+1);
	//rep(i,1,n) rep(j,1,m) s[i][j]='a';
	rep(i,1,n) h[i].resize(26);
	vi ft=vi(26,-1),sep=vi(26,0);
	rep(l,1,m) {
		rep(i,1,n) b[i]=0;
		rep(i,1,n) rep(j,0,25) h[i][j]=0;
		rep(r,l,m) {
			rep(i,1,n) {
				h[i][s[i][r]-'a']++;
				if(h[i][s[i][r]-'a']%2) b[i]++;
				else b[i]--;
			}
			vector<vi> t(2*n+2);
			t[0]=ft, t[1]=sep;
			rep(i,1,n) {
				if(b[i]>1) t[i*2]=vi{i+m*n}, t[i*2+1]=sep;
				else t[i*2]=h[i], t[i*2+1]=sep;
			}
			ans+=Manacher(t);
		}
	}
	printf("%lld\n",ans);
	return 0;
}
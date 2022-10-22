#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
//#define mp make_pair
//#define OO(x) fixed<<setprecision(x)
using namespace std;
//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
inline int read(){
	char ch=getchar(); int w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=1555;
int n,p[M],t[M],sa[M][M],sb[M][M],a[M][M];
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	n=read();
	F(i,1,n){
		F(j,1,n){
			a[i][j]=read();
			t[j]=a[i][j];
			p[j]=j;
		}
		sort(p+1,p+n+1,[&](int x,int y){
			return t[x]<t[y];
		});
		F(j,1,n) sa[i][p[j]]=j-1;
	}
	F(i,1,n){
		F(j,1,n){
			t[j]=a[j][i];
			p[j]=j;
		}
		sort(p+1,p+n+1,[&](int x,int y){
			return t[x]<t[y];
		});
		F(j,1,n) sb[p[j]][i]=j-1;
	}
	LL all=1ll*n*(n-1)/2; all=all*all;
	LL tri=0;
	F(i,1,n){
		F(j,1,n){
			tri=(tri+1ll*sa[i][j]*sb[i][j]);
		}
	}
//	cerr<<tri<<"   hhh\n";
	LL bad=tri-all,good=all-bad;
	cout<<good<<"\n";
	return 0;
}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/
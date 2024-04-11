//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),bz=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) bz=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	bz?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}/*}}}*/
const int P=998244353;
struct mat
{
	int a[64][64];inline int* operator[](int x) {return a[x];}
	inline mat operator*(mat b)
	{
		mat r;for(int i=0;i<64;i++) for(int j=0;j<64;j++) r[i][j]=0;
		for(int k=0;k<64;k++) for(int i=0;i<64;i++) if(a[i][k])
			for(int j=0;j<64;j++) r[i][j]=(r[i][j]+1ll*a[i][k]*b[k][j])%P;
		return r;
	}
}pw[35],cl[4],tp;vector<pair<int,int> >v[100005];
int n,m,a[100005],F[4][4],rs[100005][4];
inline int gt(int v,int S)
{
	for(int i=0;i<4;i++)
	{
		char a=(S&3)!=i,b=((S>>2)&3)!=i,c=(S>>4)!=i;
		if((!F[v][3]||a)&&(!F[v][2]||b)&&(!F[v][1]||c)) return (S>>2)|(i<<4);
	}return -1;
}
inline void ksm(mat &x,int q) {for(int i=0;i<31;i++) if((q>>i)&1) x=x*pw[i];}
int main()
{
	read(n);for(int i=1;i<=n;i++) read(a[i]);
	read(m);for(int i=1,x,y,c;i<=m;i++) read(x,y,c),v[x].push_back(make_pair(y,c));
	for(int i=1;i<=3;i++) for(int j=1;j<=3;j++) read(F[i][j]);
	for(int i=1,T;i<=3;i++) for(int S=0;S<64;S++) T=gt(i,S),cl[i][S][T]++,pw[0][S][T]++;
	for(int i=1;i<31;i++) pw[i]=pw[i-1]*pw[i-1];
	rs[0][0]=1;for(int i=1;i<=n;i++)
	{
		sort(v[i].begin(),v[i].end());int ls=1;
		for(int j=0;j<64;j++) for(int k=0;k<64;k++) tp[j][k]=(j==0&&k==63);
		for(auto x:v[i]) ksm(tp,x.first-ls),tp=tp*cl[x.second],ls=x.first+1;
		ksm(tp,a[i]+1-ls);for(int j=0;j<4;j++) for(int S=0;S<64;S++) rs[i][j^(S>>4)]=(rs[i][j^(S>>4)]+1ll*rs[i-1][j]*tp[0][S])%P;
	}
	return printf("%d\n",rs[n][0]),0;
}
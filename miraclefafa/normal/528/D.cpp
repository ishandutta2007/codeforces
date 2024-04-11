#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define fi first
#define se second
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

const int N=201000;
int mth[N][5],s[N],t[N],n,m,k,mv[N],cnt;
char S[N],T[N];
set<int> st[5];
VI v1,v2,v3;

typedef complex<double> CD;
const double pi=acos(-1.0);
namespace fft{
	const int N=1<<19;
	CD cp1[N+10],cp2[N+10];
	int R[N+10];
	void rev(CD* a,int n) { for (int i=0;i<n;i++) if (R[i]<i) swap(a[R[i]],a[i]);}
	void dft(CD* a,int n,bool inv) {
		CD wi,w,u,v;
		rev(a,n);
		for (int m=2;m<=n;m<<=1) {
			double Arg=2*pi/m*(inv?-1:1);
			wi=CD(cos(Arg),sin(Arg));
			for (int j=0;j<n;j+=m) { w=1;
				for (int k=j,k2=j+m/2;k2<j+m;k++,k2++)
					u=a[k],v=a[k2]*w,a[k]=u+v,a[k2]=u-v,w=w*wi;
			}
		}
		if (inv) for (int j=0;j<n;j++) a[j]=a[j]/(1.*n);
	}
	VI solve(VI& p1,VI& p2) {
		int n=p1.size()+p2.size()+1;
		int l=1,cnt=0;
		while (l<=n) l+=l,cnt++;
		rep(i,0,l) { R[i]=0;rep(j,0,cnt) R[i]=(R[i]<<1)|((i>>j)&1);}
		rep(i,0,l) cp1[i]=0,cp2[i]=0;
		rep(i,0,SZ(p1)) cp1[i]=p1[i];
		rep(i,0,SZ(p2)) cp2[i]=p2[i];
		dft(cp1,l,0);
		dft(cp2,l,0);
		rep(i,0,l) cp1[i]*=cp2[i];
		dft(cp1,l,1);
		VI res;
		res.clear();
		n=p1.size()+p2.size()-1;
		rep(i,0,n) res.pb((ll)floor(cp1[i].real()+0.5));
		return res;
	}
}

int tran(char x) { if (x=='A') return 0; if (x=='C') return 1; if (x=='G') return 2; if (x=='T') return 3;}
int main() {
	scanf("%d%d%d",&n,&m,&k);
	scanf("%s",S); rep(i,0,n) s[i]=tran(S[i]);
	scanf("%s",T); rep(i,0,m) t[i]=tran(T[i]);
	rep(i,0,n) st[s[i]].insert(i);
	rep(i,0,n) rep(j,0,4) {
		auto it=st[j].lower_bound(i-k);
		if (it!=st[j].end()&&*it<=i+k) mth[i][j]=1; else mth[i][j]=0;
	}
	rep(j,0,4) {
		v1.clear(); v2.clear();
		rep(i,0,n) if (mth[i][j]) v1.pb(1); else v1.pb(0);
		rep(i,0,m) if (t[i]==j) v2.pb(1); else v2.pb(0);
		reverse(all(v2));
		v3=fft::solve(v1,v2);
		rep(i,0,n) mv[i]+=v3[i+m-1];
	}
	rep(i,0,n) if (mv[i]==m) cnt++;
	printf("%d\n",cnt);
}
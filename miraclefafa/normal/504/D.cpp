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

const int N=2010;
typedef bitset<N> number;
number base[N],d,sel,Sel[N];
bool bs[N];
string p;
int n,a[N];
void trans(string p) {
	d=0;
	int l=SZ(p)/8+1;
	reverse(all(p));
	while (SZ(p)<=8*l) p.pb('0');
	rep(i,0,l) { a[i]=0; per(j,0,8) a[i]=a[i]*10+p[8*i+j]-'0';}
	ll s=0;
	int tot=0;
	while (l) {
		s=0;
		per(i,0,l) {
			s=s*100000000+a[i];
			a[i]=s>>32;
			s=s%(1ll<<32);
		}
		rep(i,0,32) d[tot++]=(s>>i)&1;
		while (l&&a[l-1]==0) --l;
	}
}
int main() {
	scanf("%d",&n);
	rep(i,0,n) {
		cin>>p;
		trans(p);
		sel=0;
		bool sol=0;
		for (int k=2000;k>=0;k--) if (d[k]) {
			if (bs[k]) {
				d=d^base[k];
				sel^=Sel[k];
			} else {
				sol=1; sel[i].flip();
				bs[k]=1; base[k]=d; Sel[k]=sel;
				break;
			}
		}
		if (sol) puts("0");
		else {
			int cnt=0;
			rep(j,0,i) if (sel[j]) cnt++;
			printf("%d",cnt);
			rep(j,0,i) if (sel[j]) printf(" %d",j);
			puts("");
		}
	}
}
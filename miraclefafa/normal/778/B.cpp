#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cassert>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

const int N=5010;
int n,m,v1[N],v2[N],num[N][1010],ty[N],ty2[N],val[N],s[30],r1[N],r2[N];
map<string,int> name;
char op[N];
int main() {
	scanf("%d%d",&n,&m);
	name[string("?")]=n;
	rep(i,0,n) {
		scanf("%s",op);
		name[op]=i;
		scanf("%s",op);
		scanf("%s",op);
		if (op[0]=='0'||op[0]=='1') {
			ty[i]=0;
			rep(j,0,m) num[i][j]=op[j]-'0';
		} else {
			ty[i]=1;
			v1[i]=name[op];
			scanf("%s",op);
			if (op[0]=='X') ty2[i]=0;
			else if (op[0]=='A') ty2[i]=1; else ty2[i]=2;
			scanf("%s",op);
			v2[i]=name[op];
		}
//		printf("%d %d %d %d\n",ty[i],ty2[i],v1[i],v2[i]);
	}
	rep(j,0,m) {
		rep(oc,0,2) {
			s[oc]=0;
			val[n]=oc;
			rep(i,0,n) {
				if (ty[i]==0) val[i]=num[i][j];
				else {
					if (ty2[i]==0) val[i]=val[v1[i]]^val[v2[i]];
					else if (ty2[i]==1) val[i]=val[v1[i]]&val[v2[i]];
					else val[i]=val[v1[i]]|val[v2[i]];
				}
				s[oc]+=val[i];
			}
		}
		if (s[0]<=s[1]) r1[j]=0; else r1[j]=1;
		if (s[0]>=s[1]) r2[j]=0; else r2[j]=1;
	}
	rep(i,0,m) putchar(r1[i]+'0'); puts("");
	rep(i,0,m) putchar(r2[i]+'0'); puts("");
}
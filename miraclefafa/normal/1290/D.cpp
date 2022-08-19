#include <bits/stdc++.h>
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
typedef double db;
mt19937 mrand(random_device{}()); 
const ll mod=1000000007;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=2010;
int l[N],r[N],cnt,n,k,dup[N],bb[N];
char s[10];

int query(int x) {
	printf("? %d\n",x);
	fflush(stdout);
	scanf("%s",s);
	return s[0]=='Y';
}
void clear() { puts("R"); fflush(stdout); }

int main() {
	scanf("%d%d",&n,&k);
	int b=max(k/2,1),c=n/b;
	for (int i=0;i<c;i++) l[i]=i*b+1,r[i]=i*b+b;
	for (int d=1;d<c;d++) {
		for (int i=0;i<d&&i+d<c;i++) {
			for (int j=i;j<c;j+=d) {
				bb[j]=1;
				for (int k=l[j];k<=r[j];k++) if (query(k)) dup[k]=1;
			}
			clear();
		}
	}
	int ans=0;
	for (int i=1;i<=n;i++) ans+=!dup[i];
	printf("! %d\n",ans);
//	fprintf(stderr,"%d %d\n",cnt,3*n*n/2/k);
}
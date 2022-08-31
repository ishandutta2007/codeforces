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
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

int n,val[30],unq,duang;
char s[101000],t[101000];
int main() {
	scanf("%d",&n);
	rep(j,0,26) val[j]=1;
	unq=0;
	rep(i,0,n) {
		scanf("%s%s",s,t);
		int l=strlen(t);
		if (s[0]=='?') {
			if (i==n-1) {
				int id=t[0]-'a';
				rep(j,0,26) val[j]=j==id;
			} else {
				int id=t[0]-'a';
				val[id]=0;
				if (unq) duang+=1;
			}
		} else if (s[0]=='.') {
			rep(j,0,l) val[t[j]-'a']=0;
		} else {
			if (unq) duang+=1;
			int S=0;
			rep(j,0,l) S|=1<<(t[j]-'a'); S^=(1<<26)-1;
			rep(j,0,26) if (S&(1<<j)) val[j]=0;
		}
		int cnt=0;
		rep(j,0,26) cnt+=val[j];
		if (cnt==1) unq=1;
	}
	printf("%d\n",duang);
}
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

const int N=201000;

int a,b,k;
int main() {
	scanf("%d%d%d",&a,&b,&k);
	string s=string(b,'1')+string(a,'0');
	string t=string(b,'1')+string(a,'0');
	if (b==1||a==0) {
		if (k!=0) { puts("No"); return 0;}
		puts("Yes");
		printf("%s\n%s\n",s.c_str(),t.c_str());
		return 0;
	}
	if (k>a+b-2) { puts("No"); return 0; }
	puts("Yes");
	int d=a+b-k-1;
	if (t[d]=='0') {
		s[1]=t[1]='0';
		s[d]=t[d]='1';
	}
	t[d]='0';
	t[a+b-1]='1';
	printf("%s\n%s\n",s.c_str(),t.c_str());
}
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
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

int n,q,ty,x,p1,p2;
int query(int i) {
	if (i%2==0) return (p1+i)%n;
	else return (p2+i+n-1)%n;
}
int main() {
	scanf("%d%d",&n,&q);
	p1=0,p2=1;
	rep(i,0,q) {
		scanf("%d",&ty);
		if (ty==2) swap(p1,p2);
		else {
			scanf("%d",&x); x=-x;
			if (x<0) x+=n; 
			int q1=query(x),q2=query(1+x);
			p1=q1,p2=q2;
		}
//		printf("%d %d\n",p1,p2);
	}
	rep(i,0,n) printf("%d ",query(i)+1);
	puts("");
}
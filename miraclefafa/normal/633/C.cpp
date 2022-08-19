#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cassert>
#include <iostream>
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

const int N=101000;
int n,m,dp[N],pred[N],pre[N];
char s[N],t[N];
string cr[N];
struct node {
	node *go[30];
	int id;
}pool[1010000],*cur=pool,*rt;
void dfs(int n) {
	if (n==0) return;
	dfs(pre[n]);
	cout<<cr[pred[n]]<<" ";
}
int main() {
	scanf("%d",&n);
	scanf("%s",s+1);
	scanf("%d",&m);
	rt=cur++;
	rep(i,1,m+1) {
		scanf("%s",t);
		int l=strlen(t);
		cr[i]=string(t,t+l);
		node *p=rt;
		rep(j,0,l) {
			int w=(t[j]<='Z')?(t[j]-'A'):(t[j]-'a');
			if (!p->go[w]) p->go[w]=cur++;
			p=p->go[w];
		}
		p->id=i+1;
	}
	dp[0]=1;
	rep(i,1,n+1) {
		node *p=rt;
		for (int j=i;j>0;j--) {
			p=p->go[s[j]-'a'];
//			printf("%d %d\n",i,j);
			if (!p) break;
			if (dp[j-1]&&p->id) {
				pre[i]=j-1; dp[i]=1;
				pred[i]=p->id-1;
//				printf("%d %d %d\n",i,pre[i],pred[i]);
				break;
			}
		}
	}
	assert(dp[n]);
	dfs(n);
	puts("");
}
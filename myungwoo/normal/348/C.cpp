#include <vector>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;

#define eps 1e-9
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define sz(v) ((int)(v).size())
#define all(v) v.begin(),v.end()
#define same(a,b) (fabs((a)-(b))<eps)
#define set(arr,with) memset(arr,with,sizeof(arr))
#define add(target,value,mod) target = (target+value)%(mod)
#define put_min(target,value) target = min(target,value)
#define put_max(target,value) target = max(target,value)
typedef pair<int,int> pii;
typedef long long lld;

#define MAXN 100005

const int HS=316;
int N,M,Q;
lld A[MAXN],AD[MAXN],V[MAXN];
vector <int> S[MAXN];
vector <int> H,C[400];

int main()
{
	int i,j,k,t,x;
	char ch;
	scanf("%d%d%d",&N,&M,&Q);
	for (i=1;i<=N;i++) scanf("%lld",A+i);
	for (i=1;i<=M;i++){
		for (scanf("%d",&j);j--;){
			scanf("%d",&k);
			S[i].pb(k);
		}
		sort(all(S[i]));
		if (sz(S[i]) > HS){
			H.pb(i);
			for (j=0;j<sz(S[i]);j++) V[i] += A[S[i][j]];
		}
	}
	for (i=0;i<sz(H);i++){
		C[i].resize(M+1,0);
		for (j=1;j<=M;j++){
			for (k=t=0;k<sz(S[j]);k++){
				while (t < sz(S[H[i]]) && S[H[i]][t] < S[j][k]) t++;
				if (t < sz(S[H[i]]) && S[H[i]][t] == S[j][k]) C[i][j]++, t++;
			}
		}
	}
	while (Q--){
		scanf(" %c%d",&ch,&k);
		if (ch == '?'){
			lld ans=0;
			if (sz(S[k]) <= HS){
				for (i=0;i<sz(S[k]);i++) ans += A[S[k][i]];
				for (i=0;i<sz(H);i++) ans += (lld)C[i][k]*AD[H[i]];
			}else ans = V[k];
			printf("%lld\n",ans);
		}else{
			scanf("%d",&x);
			if (sz(S[k]) <= HS){
				for (i=0;i<sz(S[k]);i++) A[S[k][i]] += x;
			}else AD[k] += x;
			for (i=0;i<sz(H);i++){
				V[H[i]] += (lld)x*C[i][k];
			}
		}
	}
}
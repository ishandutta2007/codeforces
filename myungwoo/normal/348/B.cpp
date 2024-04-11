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

#pragma comment(linker,"/STACK:33554432")

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

int N,A[MAXN],mom[MAXN];
lld L[MAXN],S[MAXN],D[MAXN],sum,ans;

vector <int> con[MAXN];

lld gcd(lld a,lld b){ return b?gcd(b,a%b):a; }

bool dfs(int n)
{
	int i,k,cnt=0;
	L[n] = 1; S[n] = 1e16;
	for (i=sz(con[n]);i--;){
		k = con[n][i];
		if (mom[k]) continue;
		cnt++; mom[k] = n;
		if (dfs(k)) return 1;
		put_min(S[n],S[k]);
		L[n] = L[n]*L[k]/gcd(L[n],L[k]);
		if (L[n] > 1e8) return 1;
	}
	
	lld mn=1e16;
	for (i=sz(con[n]);i--;){
		k = con[n][i];
		if (mom[k] != n) continue;
		if (L[n] > S[k]) return 1;
		put_min(mn,S[k]/L[n]);
	}
	D[n] = mn*L[n];

	if (cnt) L[n] = L[n]*cnt, S[n] = S[n]*cnt;
	else S[n] = A[n];
	if (S[n] > 1e14) S[n] = 1e14;
	if (L[n] > 1e8) return 1;
	return 0;
}

int main()
{
	int i,j,k;
	scanf("%d",&N);
	for (i=1;i<=N;i++) scanf("%d",A+i), sum += A[i];
	for (i=1;i<N;i++){
		scanf("%d%d",&j,&k);
		con[j].pb(k), con[k].pb(j);
	}
	mom[1] = 1;
	if (dfs(1)){ cout << sum << endl; return 0; }
	cout << sum-D[1]*sz(con[1]) << endl;
}
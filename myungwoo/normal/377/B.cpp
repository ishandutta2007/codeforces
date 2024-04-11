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
#define add(target,value,mod) target = (target+(value))%(mod)
#define put_min(target,value) target = min(target,value)
#define put_max(target,value) target = max(target,value)
typedef long long lld;
typedef pair<int,int> pii;
typedef pair<lld,int> pli;
typedef pair<int,lld> pil;
typedef pair<lld,lld> pll;

#define MAXN 100005

int N,M,S,A[MAXN],ans,P[MAXN],Q[MAXN],org[MAXN];

struct Z{
	int b,c,idx;
	bool operator < (const Z &ot)const{
		return b<ot.b;
	}
} B[MAXN];

bool cmp(const int &a,const int &b){ return A[a] < A[b]; }

priority_queue <pii> que;

bool proc(int m)
{
	int i,j,k,p=M,last;
	lld sum=0;
	while (!que.empty()) que.pop();
	for (i=M,j=N;i;i--){
		while (j && B[j].b >= A[i]){
			que.push(mp(-B[j].c,j));
			j--;
		}
		if (i > p){ P[Q[i]] = B[last].idx; continue; }
		p -= m;
		if (que.empty()) return 0;
		k = que.top().sc; que.pop();
		sum += B[k].c; last = k; P[Q[i]] = B[last].idx;
		if (sum > S) return 0;
	}
	return 1;
}

int main()
{
	int i,j,k,s,e,m;
	scanf("%d%d%d",&N,&M,&S);
	for (i=1;i<=M;i++) scanf("%d",A+i), Q[i] = i;
	for (i=1;i<=N;i++) scanf("%d",&B[i].b);
	for (i=1;i<=N;i++) scanf("%d",&B[i].c), B[i].idx = i;
	sort(Q+1,Q+M+1,cmp);
	sort(A+1,A+M+1); sort(B+1,B+N+1);
	s = 1, e = M;
	while (s <= e){
		m = (s+e)>>1;
		if (proc(m)) e = m-1, ans = m;
		else s = m+1;
	}
	if (!ans){ puts("NO"); return 0; }
	puts("YES"); proc(ans);
	for (i=1;i<=M;i++) printf("%d ",P[i]); puts("");
}
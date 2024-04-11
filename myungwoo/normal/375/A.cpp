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
typedef long long lld;
typedef pair<int,int> pii;
typedef pair<lld,int> pli;
typedef pair<int,lld> pil;
typedef pair<lld,lld> pll;

#define MAXN 1000006

int N,cnt[10],A[]={1,6,8,9};
char buf[MAXN];

int main()
{
	int i;
	scanf("%s",buf); N = strlen(buf);
	for (i=0;i<N;i++) cnt[buf[i]-'0']++;
	for (i=0;i<4;i++) cnt[A[i]]--;
	if (cnt[0] == N-4){
		printf("1869");
		for (i=0;i<cnt[0];i++) printf("0"); puts("");
		return 0;
	}
	int r=0;
	for (i=10;i--;){
		while (cnt[i]--) printf("%d",i), r = (r*10+i)%7;
	}
	for (int T=24;T--;next_permutation(A,A+4)){
		int x=r;
		for (i=0;i<4;i++) x = (x*10+A[i])%7;
		if (!x){
			for (i=0;i<4;i++) printf("%d",A[i]); puts("");
			return 0;
		}
	}
}
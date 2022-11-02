#include <bits/stdc++.h>

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

#define add(target,value,mod) target = (target+(value))%(mod)

#define put_min(target,value) target = min(target,value)

#define put_max(target,value) target = max(target,value)

typedef long long lld;

typedef pair<int,int> pii;

typedef pair<lld,int> pli;

typedef pair<int,lld> pil;

typedef pair<lld,lld> pll;



#define MAXN 200005



int N, Q;

int A[MAXN];



int main()

{

    scanf("%d%d", &N, &Q);

    for (int i=1;i<=N;i++) scanf("%d", A+i);

    sort(A+1, A+N+1);

    while (Q--){

        int x; scanf("%d", &x);

        printf("%d ", upper_bound(A+1, A+N+1, x) - A - 1);

    } puts("");

}
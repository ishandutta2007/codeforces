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

int N, K;
int G[] = {0, 1, 0, 1, 2, 0, 2, 0, 1, 0};

int grundy(int n, int k)
{
    if (k&1){
        if (n < 10) return G[n];
        if (n&1) return 0;
        return grundy(n>>1, k) == 1 ? 2 : 1;
    }else{
        if (n < 3) return n;
        return !(n&1);
    }
}

int main()
{
    scanf("%d%d", &N, &K);
    int x = 0;
    for (int i=1;i<=N;i++){
        int v; scanf("%d", &v);
        x ^= grundy(v, K);
    }
    puts(x ? "Kevin" : "Nicky");
}
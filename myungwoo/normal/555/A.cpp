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

#define MAXN 100005

int N, K;
int num[MAXN];

int main()
{
    scanf("%d%d", &N, &K);
    for (int i=1;i<=K;i++){
        int c; scanf("%d", &c);
        for (int j=0;j<c;j++){
            int v; scanf("%d", &v);
            num[v] = i;
        }
    }
    int l = N;
    for (int i=2;i<=N;i++) if (num[i] != num[i-1]){ l = i-1; break; }
    printf("%d\n", (N-l)*2 - K + 1);
}
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

const int N = 5e6;
int T;
lld S[N+1];
bool V[N+1];

int main()
{
    for (int i=2;i<=N;i++) if (!V[i]){
        for (lld v=i;v<=N;v*=i){
            for (int j=v;j<=N;j+=v) V[j] = 1, S[j]++;
        }
    }
    for (int i=1;i<=N;i++) S[i] += S[i-1];
    for (cin >> T;T--;){
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%lld\n", S[a] - S[b]);
    }
}
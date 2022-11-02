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

int N, M;
int W[MAXN], D[MAXN], E[MAXN];
vector <int> con[MAXN];

void dy(int n, int turn)
{
    if (con[n].empty()){
        W[n] = D[n] = E[n] = 1;
        return;
    }
    if (turn) D[n] = 0, E[n] = N+1;
    else D[n] = N+1, E[n] = 0;
    for (int t: con[n]){
        dy(t, turn^1); W[n] += W[t];
        if (turn) D[n] += W[t]-D[t]+1, put_min(E[n], E[t]);
        else put_min(D[n], W[t]-D[t]), E[n] += E[t];
    }
    if (turn) D[n] = W[n]-D[n]+1;
    else D[n] = W[n]-D[n];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> N;
    for (int i=1;i<N;i++){
        int a, b;
        cin >> a >> b;
        con[a].pb(b);
    }
    dy(1, 0);
    printf("%d %d\n", D[1], E[1]);
}
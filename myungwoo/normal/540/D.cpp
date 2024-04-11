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

int R, S, P;
double D[101][101][101], X, Y, Z;
bool V[101][101][101];

int main()
{
    cin >> R >> S >> P;
    queue <int> que;
    D[R][S][P] = 1;
    que.push(R); que.push(S); que.push(P);
    V[R][S][P] = 1;
    while (!que.empty()){
        int r = que.front(); que.pop();
        int s = que.front(); que.pop();
        int p = que.front(); que.pop();

        int b = r*s + s*p + p*r;
        if (!b) continue;
        double pb = (double)(r*s)/b;
        if (r > 0 && s > 0){
            if (!V[r][s-1][p]){
                V[r][s-1][p] = 1;
                que.push(r); que.push(s-1); que.push(p);
            }
            D[r][s-1][p] += D[r][s][p] * pb;
        }
        pb = (double)(s*p)/b;
        if (s > 0 && p > 0){
            if (!V[r][s][p-1]){
                V[r][s][p-1] = 1;
                que.push(r); que.push(s); que.push(p-1);
            }
            D[r][s][p-1] += D[r][s][p] * pb;
        }
        pb = (double)(p*r)/b;
        if (p > 0 && r > 0){
            if (!V[r-1][s][p]){
                V[r-1][s][p] = 1;
                que.push(r-1); que.push(s); que.push(p);
            }
            D[r-1][s][p] += D[r][s][p] * pb;
        }
    }
    for (int i=1;i<=R;i++) X += D[i][0][0];
    for (int i=1;i<=S;i++) Y += D[0][i][0];
    for (int i=1;i<=P;i++) Z += D[0][0][i];
    printf("%.13lf %.13lf %.13lf\n", X, Y, Z);
}
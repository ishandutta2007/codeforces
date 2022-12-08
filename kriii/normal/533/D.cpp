#include <stdio.h>
#include <algorithm>
#include <stack>
using namespace std;

int N,X[100005],D[100005];
int L[100005],R[100005];
pair<double, int> U[100005];
double coord[100005]; int I[100005];

const int Z = 1 << 17;
int IT[Z*2];

void in(int x, int p)
{
    x += Z;
    while (x){
        IT[x] = max(IT[x],p);
        x /= 2;
    }
}

int out(int x, int y)
{
    int r = 0;
    x += Z; y += Z;
    while (x < y){
        if (x & 1) r = max(r,IT[x++]);
        if (~y & 1) r = max(r,IT[y--]);
        x /= 2; y /= 2;
    } if (x == y) r = max(r,IT[x]);
    return r;
}

bool chk(double d)
{
    for (int i=1;i<=N;i++){
        if (X[R[i]] - X[L[i]] <= 2 * d) return true;
    }
    for (int i=0;i<=N;i++){
        int u = L[i];
        double lx;
        if (i == 0) lx = 1e10;
        else lx = X[u] + 2 * D[i];
        if (lx <= X[i]) lx = - 1e11; 
        U[i] = make_pair(lx,i);
    }
    sort(U,U+N+1);
    for (int i=0;i<=N;i++) coord[i] = U[i].first, I[U[i].second] = i;
    for (int i=0;i<2*Z;i++) IT[i] = 0;

    for (int i=0;i<=N;i++){
        int v = R[i+1];
        double ux;
        if (i == N+1) ux = -1e10;
        else ux = X[v] - 2 * D[i+1];
        if (ux >= X[i+1]) ux = 1e11;
        int j = lower_bound(coord,coord+N+1,ux) - coord;
        in(I[i],X[i]);
        if (j <= N && (X[i+1] - out(j,N)) <= 2 *d) return true;
    }

    return false;
}

int main()
{
    scanf ("%d",&N);
    for (int i=0;i<=N+1;i++) scanf ("%d",&X[i]);
    for (int i=1;i<=N;i++) scanf ("%d",&D[i]);
    D[0] = D[N+1] = 1000000002;

    {
        stack<int> S;
        S.push(0); L[0] = 0;
        for (int i=1;i<=N+1;i++){
            while (S.top() != 0){
                int u = S.top(); S.pop();
                int v = S.top();
                if ((X[i] - X[v]) <= 2 * D[u]){
                    S.push(u);
                    break;
                }
            }
            L[i] = S.top();
            S.push(i);
        }
    }

    {
        stack<int> S;
        S.push(N+1); R[N+1] = N+1;
        for (int i=N;i>=0;i--){
            while (S.top() != N+1){
                int u = S.top(); S.pop();
                int v = S.top();
                if ((X[v] - X[i]) <= 2 * D[u]){
                    S.push(u);
                    break;
                }
            }
            R[i] = S.top();
            S.push(i);
        }
    }

    double ans = 0;
    if (L[N+1] == 0){
        double l = 0, r = 1e10;
        for (int i=0;i<100;i++){
            double m = (l + r) / 2;
            if (chk(m)) r = m;
            else l = m;
        }
        ans = r;
    }
    printf ("%.12lf\n",ans);

    return 0;
}
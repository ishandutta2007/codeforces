#include <bits/stdc++.h>
using namespace std;

#define MAXN 200005
#define pb push_back
#define mp make_pair
#define all(v) (v).begin(), (v).end()
typedef pair<int, int> pii;

int N;
int A[MAXN], L[MAXN], R[MAXN];
bool V[MAXN];

int CP(int x, int par[MAXN])
{
    return par[x] == x ? x : par[x] = CP(par[x], par);
}

int main()
{
    scanf("%d", &N);
    for (int i=1;i<=N;i++) scanf("%d", A+i);
    vector <pii> arr;
    for (int i=1;i<=N;i++){
        arr.pb(mp(-A[i], i));
        L[i] = R[i] = i;
    }
    sort(all(arr));
    int mx = 0;
    for (auto &p: arr){
        int x = p.second;
        if (x < N && V[x+1]){
            R[x] = CP(x+1, R);
            L[x+1] = x;
        }
        if (x > 1 && V[x-1]){
            L[x] = CP(x-1, L);
            R[x-1] = CP(x, R);
        }
        int now = CP(x, R) - CP(x, L) + 1;
        for (int i=mx+1;i<=now;i++)
            printf("%d ", A[x]);
        if (mx < now) mx = now;
        V[x] = 1;
    }
    puts("");
}
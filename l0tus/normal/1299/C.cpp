#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<pii,int> ppi;
const int MN = 1e6+5;
ll A[MN],S[MN];
pii P[MN],V[MN];
long double Q[MN];
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    int N;
    cin >> N;
    for(int i=1; i<=N; i++){
        cin >> A[i];
        S[i] = S[i-1]+A[i];
        P[i].va = i;
        P[i].vb = S[i];
    }
    V[0] = P[0];
    V[1] = P[1];
    int cur = 1;
    for(int i=2; i<=N; i++){
        while(cur&&(P[i].vb-V[cur-1].vb)*(V[cur].va-V[cur-1].va)<(V[cur].vb-V[cur-1].vb)*(P[i].va-V[cur-1].va)){
            cur--;
        }
        V[++cur] = P[i];
    }
    int s=0, e;
    for(int i=1; i<=cur; i++){
        e = V[i].va;
        for(int j=s+1; j<=e; j++){
            Q[j] = (long double)(S[e]-S[s])/(e-s);
        }
        s = e;
    }
    cout.fixed;
    cout.precision(10);
    for(int i=1; i<=N; i++) cout << Q[i] << '\n';
}
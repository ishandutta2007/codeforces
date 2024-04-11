#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
using namespace std;

typedef long long lld;

int N,mom[9],ans=1e9;
lld A[9],mul[9];
vector <lld> prime[9];

void dfs(int n)
{
    int i;
    if (n == N+1){
        int j,cnt=0,me=N;
        for (i=1;i<=N;i++) if (!mom[i]) cnt++;
        if (cnt > 1) me++;
        for (i=1;i<=N;i++){
            lld n=A[i]/mul[i];
            for (j=prime[i].size();j--;) if (n == prime[i][j]) break;
            if (j >= 0){ me += n==A[i]?0:1; continue; }
            for (j=prime[i].size();j--;){
                lld m = prime[i][j];
                while (n%m == 0) n /= m, me++;
            }
        }
        if (ans > me)
            ans = me;
        return;
    }
    dfs(n+1);
    for (i=1;i<n;i++){
        if (A[i]/A[n]+1 < mul[i] || A[i]%(mul[i]*A[n]) != 0) continue;
        mul[i] *= A[n];
        mom[n] = i;
        dfs(n+1);
        mom[n] = 0;
        mul[i] /= A[n];
    }
}

int main()
{
    int i;
    cin >> N;
    for (i=1;i<=N;i++) cin >> A[i];
    sort(A+1,A+N+1,greater<lld>());
    for (i=1;i<=N;i++){
        lld k=A[i],n;
        for (n=2;n*n<=k;n++) if (k%n == 0){
            prime[i].push_back(n);
            while (k%n == 0) k /= n;
        }
        if (k > 1) prime[i].push_back(k);
    }
    for (i=1;i<=N;i++) mul[i] = 1;
    dfs(2);
    cout << ans << endl;
}
#include <bits/stdc++.h>
#define va firsst
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9;
const int MN = 3e5+5;
ll F[MN],N,M,ans;
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    F[0] = 1;
    cin >> N >> M;
    for(int i=1; i<=N; i++){
        F[i] = F[i-1]*i%M;
    }
    for(int i=1; i<=N; i++){
        ans = (ans+F[N-i+1]*F[i]%M*(N-i+1)%M)%M;
    }
    cout << ans;
}
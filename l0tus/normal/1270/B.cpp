#include <bits/stdc++.h>
#define va firsst
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9;
const int MN = 2e5+5;
int A[MN];
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        int N;
        int ans = 0;
        cin >> N;
        for(int i=1; i<=N; i++) cin >> A[i];
        for(int i=1; i<=N-1; i++){
            if(abs(A[i+1]-A[i])>1) ans = i;
        }
        if(ans) cout << "YES\n" << ans << ' ' << ans+1 << '\n';
        else cout << "NO\n";

    }
}
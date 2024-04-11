#include <bits/stdc++.h>
#define va first
#define vb second
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pii,int> ppi;
typedef pair<int,pii> pip;

const int MN = 2e5+5;
const int MOD = 1e9+7;
const int INF = 1e9;


int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    int t,n,m;
    cin >> t;
    while(t--){
        cin >> n >> m;
        bool A[1005],B[1005];
        fill(A,A+1005,0);
        fill(B,B+1005,0);
        int x;
        for(int i=0; i<n; i++){
            cin >> x;
            A[x] = 1;
        }
        for(int i=0; i<m; i++){
            cin >> x;
            B[x] = 1;
        }
        int ans = 0;
        for(int i=1; i<=1000; i++){
            if(A[i]&&B[i]){
                ans = i;
            }
        }
        if(ans){
            cout << "YES\n";
            cout << 1 << ' ' << ans << '\n';
        }
        else cout << "NO\n";
    }
}
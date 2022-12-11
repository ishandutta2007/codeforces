#include <bits/stdc++.h>
#define va first
#define vb second
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pii,int> ppi;
typedef pair<int,pii> pip;

const int MN = 1e5+5;
const int MOD = 1e9+7;
const int INF = 1e9;

int A[MN];

int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        bool ans = 1;
        for(int i=1; i<=n; i++){
            cin >> A[i];
        }
        for(int i=n-1; i>=1; i--){
            if(ans){
                if(A[i]==1) ans = 0;
            }
            else ans = 1;
        }
        cout << (ans ? "First\n":"Second\n");
    }
}
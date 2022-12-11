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
        ll N,X=0,Y=0,K;
        cin >> N;
        for(int i=1; i<=N; i++){
            cin >> K;
            X += K;
            Y ^= K;
        }
        cout << 2 << '\n';
        cout << Y << ' ' << X+Y << '\n';
    }
}
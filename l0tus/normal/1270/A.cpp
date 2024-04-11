#include <bits/stdc++.h>
#define va firsst
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9;
const int MN = 2e5+5;
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        int N,A,B,X=0,Y=0,Z;
        cin >> N >> A >> B;
        while(A--){
            cin >> Z;
            X = max(X,Z);
        }
        while(B--){
            cin >> Z;
            Y = max(Y,Z);
        }
        if(X>Y) cout << "YES\n";
        else cout << "NO\n";
    }
}
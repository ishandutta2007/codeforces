#include <bits/stdc++.h>
#define va firsst
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9;
const int MN = 2e5+5;
int N,X,A,B;
ll ans;
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> N;
    while(N--){
        cin >> X;
        ans += X/2;
        if(X%2){
            if(N%2) A++;
            else B++;
        }
    }
    ans += min(A,B);
    cout << ans;
}
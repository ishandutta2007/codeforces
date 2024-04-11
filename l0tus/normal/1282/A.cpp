#include <bits/stdc++.h>
#define va firsst
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9;
const int MN = 2e5+5;
int A,B,C,R;
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        cin >> A >> B >> C >> R;
        if(A>B) swap(A,B);
        if(C+R<=A||C-R>=B) cout << B-A << '\n';
        else cout << B-A-min(B,C+R)+max(A,C-R) << '\n';
    }
}
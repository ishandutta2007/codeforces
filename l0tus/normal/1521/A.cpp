#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int MN = 2e5+5;

//int A[MN],S[MN];

int main()
{
    int T;
    cin >> T;
    while(T--){
        ll A,B;
        cin >> A >> B;
        if(B==1){
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        cout << A*B << " " <<  A  << " " <<  A*B + A << '\n';
    }
    return 0;
}
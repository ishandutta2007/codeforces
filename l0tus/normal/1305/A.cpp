#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<pii,int> ppi;
const int MN = 2e3+5;
int N,A[MN],B[MN];

int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        cin >> N;
        for(int i=0; i<N; i++) cin >> A[i];
        for(int i=0; i<N; i++) cin >> B[i];
        sort(A,A+N);
        sort(B,B+N);
        for(int i=0; i<N; i++) cout <<  A[i] << ' ';
        cout << '\n';
        for(int i=0; i<N; i++) cout << B[i] << ' ';
        cout << '\n';
    }
}
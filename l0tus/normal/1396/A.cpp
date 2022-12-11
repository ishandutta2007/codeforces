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

ll A[MN];
int main()
{
    #ifdef L0TUS
    freopen("C:\\Users\\SKYPC364\\Documents\\Coding\\BOJ\\input.txt", "r", stdin);
    freopen("C:\\Users\\SKYPC364\\Documents\\Coding\\BOJ\\output.txt", "w", stdout);
    #endif
    
    ios_base::sync_with_stdio(0),cin.tie(0);
    ll N;
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> A[i];
    }
    cout << "1 1\n";
    cout << -A[0] << '\n';
    A[0] = 0;
    if(N==1){
        cout << "1 1\n";
        cout << "0\n";
    }
    else{
        cout << 2 << ' ' << N << '\n';
        for(int i=1; i<N; i++){
            ll x = (N-1)*(A[i]%N);
            cout << x << ' ';
            A[i] += x;
        }
        cout << '\n';
    }
    cout << 1 << ' ' << N << '\n';
    for(int i=0; i<N; i++){
        cout << -A[i] << ' ';
    }
}
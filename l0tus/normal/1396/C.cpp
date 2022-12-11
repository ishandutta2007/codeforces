#include <bits/stdc++.h>
#define va first
#define vb second
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pii,int> ppi;
typedef pair<int,pii> pip;

const int MN = 1e6+5;
const int MOD = 1e9+7;
const int INF = 1e9;

ll A[MN],D[MN][2];
int main()
{
    #ifdef L0TUS
    freopen("C:\\Users\\SKYPC364\\Documents\\Coding\\BOJ\\input.txt", "r", stdin);
    freopen("C:\\Users\\SKYPC364\\Documents\\Coding\\BOJ\\output.txt", "w", stdout);
    #endif
    
    ios_base::sync_with_stdio(0),cin.tie(0);
    ll N,r1,r2,r3,d;
    cin >> N >> r1 >> r2 >> r3 >> d;
    for(int i=1; i<=N; i++) cin >> A[i];
    D[0][1] = 1e18;
    for(int i=1; i<=N; i++){
        if(i==N) D[i][0] = min(min(D[i-1][0],D[i-1][1]-d)+r1*A[i]+r3,D[i-1][1]+min(r2+r1,r1*A[i]+r1+r1));
        else D[i][0] = min(min(D[i-1][0],D[i-1][1])+r1*A[i]+r3,D[i-1][1]+min(r2+r1,r1*A[i]+r1+r1));
        D[i][1] = D[i-1][0]+d*2+min(r2+r1,r1*A[i]+r1+r1);
        //cout << D[i][0] << ' ' << D[i][1] << '\n';
    }
    cout << min(D[N][0],D[N][1])+d*(N-1);
}
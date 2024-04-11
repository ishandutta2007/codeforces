#include <bits/stdc++.h>
using namespace std;
#define va first
#define vb second
typedef long long ll;
typedef pair<int,int> pii;
const int MN = 2e5+3;
const long long MOD = 1e9+7;

long long N,M,L,R,sum,ans,cnt,A[MN],B[MN];
string S;

int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> N >> L >> R;
    long long S = R-L+1, a[3];
    long long D[2][3];
    a[0] = a[1] = a[2] = S/3;
    if(S%3==1)
    {
        if(R%3==0)
            a[0]++;
        if(R%3==1)
            a[1]++;
        if(R%3==2)
            a[2]++;
    }
    if(S%3==2)
    {
        if(R%3==0)
            a[0]++, a[2]++;
        if(R%3==1)
            a[1]++, a[0]++;
        if(R%3==2)
            a[2]++, a[1]++;
    }
    for(int i=0; i<3; i++) D[1][i] = a[i];
    for(int i=2; i<=N; i++){
        D[i%2][0] = (D[(i+1)%2][2]*a[1] + D[(i+1)%2][0]*a[0] + D[(i+1)%2][1]*a[2])%MOD;
        D[i%2][1] = (D[(i+1)%2][2]*a[2] + D[(i+1)%2][0]*a[1] + D[(i+1)%2][1]*a[0])%MOD;
        D[i%2][2] = (D[(i+1)%2][2]*a[0] + D[(i+1)%2][0]*a[2] + D[(i+1)%2][1]*a[1])%MOD;
    }
    //ans = (D[N%2][0] + D[N%2][1] + D[N%2][2])%MOD;
    cout << D[N%2][0];
}
#include <bits/stdc++.h>
#define first va
#define second vb
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MN = 1e3+5;
ll N,A[MN][MN],B[MN],cnt,ans,a,b,c,m,M;
bool ch;
string S;
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> N;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin >> A[i][j];
        }
    }
    for(int i=1; i<=N; i++){
        cout << (int)sqrt(A[i][i%N+1]*A[i][(i+1)%N+1]/A[i%N+1][(i+1)%N+1]) << ' ';
    }
}
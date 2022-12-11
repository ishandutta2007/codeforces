#include <bits/stdc++.h>
using namespace std;
#define va first
#define vb second
typedef long long ll;
typedef pair<int,int> pii;
using namespace std;
const int MN = 1e6+5;
const int INF = 1e9;

int A[MN],B[MN],N,M,K,cnt,tmp,ans,val;
string S;
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    //freopen("C:\\Users\\user\\Desktop\\input.txt","r",stdin);
    cin >> N >> M >> K;
    for(int i=0; i<N; i++){
        cin >> A[i];
        if(i) B[i-1] = A[i] - A[i-1] - 1;
    }
    sort(B,B+N-1);
    for(int i=0; i<(N-K); i++) ans += B[i];
    cout << ans+N;
}
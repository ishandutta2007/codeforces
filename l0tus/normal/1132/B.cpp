#include <bits/stdc++.h>
using namespace std;
#define va first
#define vb second
typedef long long ll;
typedef pair<int,int> pii;
using namespace std;
const int MN = 1e6+5;
const int INF = 1e9;

ll A[MN],B[MN],N,M,K,cnt,tmp,ans,val;
string S;
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> A[i];
        cnt += A[i];
    }
    sort(A,A+N,greater<ll>());
    cin >> M;
    for(int i=0; i<M; i++){
        cin >> tmp;
        cout << cnt-A[tmp-1] << '\n';
    }
}
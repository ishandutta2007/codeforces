#include <bits/stdc++.h>
using namespace std;
const int MAX = 3e5+5;
long long N,M,K,A[MAX],S[MAX],sum,cnt,val,res,ans;
bool check;
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> N >> M >> K;
    for(int i=0; i<N; i++){
        cin >> A[i];
    }
    sort(A,A+N,greater<long long>());
    ans += A[0]*(M%(K+1));
    cnt = M/(K+1);
    ans += cnt*(A[0]*K+A[1]);
    cout << ans;
}
#include <bits/stdc++.h>
using namespace std;
typedef pair<long long,long long> pii;
const int MN = 2e5+5;
long long N,M,K,B[MN],cnt,val,res,ans;
pii A[MN];
string S;
vector<long long> V;
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> N >> M >> K;
    for(int i=1; i<=N; i++){
        cin >> A[i].first;
        A[i].second = i;
    }
    sort(A+1,A+N+1);
    for(int i=N; i>=N-M*K+1; i--){
        ans += A[i].first;
        V.push_back(A[i].second);
    }
    sort(V.begin(),V.end());
    cout << ans << '\n';
    for(int i=1; i<K; i++){
        cout << V[i*M-1] << ' ';
    }
}
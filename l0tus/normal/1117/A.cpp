#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5+5;
int N,K,A[MAX],S[MAX],sum,cnt,val,res,ans;
bool check;
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> A[i];
        res = max(res,A[i]);
    }
    for(int i=0; i<N; i++){
        if(A[i]==res) cnt++;
        else cnt = 0;
        ans = max(cnt,ans);
    }
    cout << ans;
}
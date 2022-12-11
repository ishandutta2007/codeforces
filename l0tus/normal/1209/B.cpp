#include <bits/stdc++.h>
using namespace std;
const int MN = 105;
int N,A[MN],B[MN],O[MN],sum,ans;
string S;
int main()
{
    cin >> N >> S;
    for(int i=0; i<N; i++){
        O[i] = S[i]-'0';
        sum += O[i];
        cin >> A[i] >> B[i];
    }
    for(int t=0; t<200; t++){
        for(int i=0; i<N; i++){
            if(t>=B[i] && (t-B[i])%A[i]==0){
                sum -= O[i];
                O[i] = 1-O[i];
                sum += O[i];
            }
        }
        ans = max(sum,ans);
    }
    cout << ans;
}
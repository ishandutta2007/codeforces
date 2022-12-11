#include <bits/stdc++.h>
using namespace std;
const int MN = 2e5+5;
int A[MN];
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    int Q;
    cin >> Q;
    while(Q--){
        int N,num0=0,num1=0;
        cin >> N;
        string S;
        bool isodd = false;
        for(int i=1; i<=N; i++){
            cin >> S;
            A[i] = S.size();
            if(A[i]%2) isodd = true;
            for(int j=0; j<S.size(); j++){
                if(S[j]=='0') num0++;
                else num1++;
            }
        }
        if(num0%2&&num1%2&&!isodd) cout << N-1 << '\n';
        else cout << N << '\n';
    }
}
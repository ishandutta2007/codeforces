#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5+5;
int N,K,val[MAX][3],sum,cnt,res[MAX],ans;
string S,T,C,A;
int main()
{
    ios_base::sync_with_stdio(0);
    //cin.tie(0);
    cin >> S;
    N = S.size();
    for(int i=0; i<N; i++){
        cnt = i;
        for(int t=0; t<3; t++){
           val[i][t] = cnt%26;
           cnt/=26;
        }
    }
    T.resize(N);
    A.resize(N);
    for(int t=0; t<3; t++){
        for(int i=0; i<N; i++) T[i] = 'a'+val[i][t];
        cout << "? " << T << '\n';
        fflush(stdout);
        cin >> C;
        for(int i=0; i<N; i++){
            cnt = 1;
            for(int j=0; j<t; j++) cnt*=26;
            res[i] += (C[i]-'a')*cnt;
        }
    }
    for(int i=0; i<N; i++){
        A[res[i]] = S[i];
    }
    cout << "! " << A << '\n';
}
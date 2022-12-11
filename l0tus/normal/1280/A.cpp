#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MOD = 1e9+7;
const int MN = 1e7;
ll T,N,L,A[MN],len;
bool ch;
string S;
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> T;
    while(T--){
        L = 0;
        ch = 1;
        cin >> N >> S;
        for(int i=0; i<S.size(); i++) A[i] = S[i]-'0';
        len = S.size();
        while(1){
            L++;
            if(ch) for(int i=0; i<(len-L)*(A[L-1]-1); i++) A[len+i] = A[L+i];
            len = ((len-L+MOD)*A[L-1]+L)%MOD;
            if(len>=N) ch = 0;
            if(L==N) break;
        }
        cout << len << '\n';
    }
}
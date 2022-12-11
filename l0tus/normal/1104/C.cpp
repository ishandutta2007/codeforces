#include <bits/stdc++.h>
using namespace std;
#define va first
#define vb second
typedef long long ll;
typedef pair<int,int> pii;
const int MN = 1e5;
const int INF = 1e9;

long long N,M,L,ans,cnt1,cnt2,sum,A[MN],B[MN];
string S;

int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> S;
    cnt1 = 1, cnt2 = 1;
    for(int i=0; i<S.size(); i++){
        if(S[i]=='0'){
            cout << 1 << ' ' << cnt1 << '\n';
            cnt1++;
            cnt1 = (cnt1+3)%4+1;
        }
        else{
            cout << 3 << ' ' << cnt2 << '\n';
            cnt2+=2;
            cnt2 = (cnt2+3)%4+1;
        }
    }

    //cout << sum << ' ' << ans;

}
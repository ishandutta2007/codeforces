#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MN = 2e5+5;
int N,M,K,A[MN],B[MN],S[MN],ans,sum;

int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        int a,b,c,s,e=0,ans;
        cin >> a >> b >> c;
        s = min(a,b/2);
        ans = s;
        b -= 2*s;
        while(s>=0){
            while(b&&c>1){
                b-=1;
                c-=2;
                e++;
            }
            //cout << e;
            ans=max(ans,s+e);
            s--;
            b+=2;
        }
        cout << 3*ans << '\n';
    }
}
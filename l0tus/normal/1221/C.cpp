#include <bits/stdc++.h>
#define first va
#define second vb
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MN = 100;
int Q,N,C,M,X,tmp;
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> Q;
    for(int i=0; i<Q; i++){
        cin >> C >> M >> X;
        int ans = 0;
        ans = min(min(C,M),X);
        C -= ans, M -= ans, X -= ans;
        if(C<M) swap(C,M);
        if(C>=2*M){
            ans += M;
            M = 0, C -= 2*M;
        }
        else{
            tmp = C-M;
            ans += tmp;
            C -= 2*tmp, M -= tmp;
        }
        tmp = min(C/3,M/3);
        ans += 2*tmp;
        C -= 3*tmp, M -= 3*tmp;
        while(C>=1&&M>=1&&C+M>2){
            if(C>M) C-=2, M--;
            else M-=2, C--;
            ans++;
        }
        cout << ans << '\n';
    }
}
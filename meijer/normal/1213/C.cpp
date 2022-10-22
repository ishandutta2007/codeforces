#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define INF 1e9
#define REP(a,b,c) for(int a=int(b); a<int(c); a++)

int q;
ll n, m;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>q;
    while(q--) {
        cin>>n>>m;
        ll loopSize=1, last=m%10, loopTotal=0;
        while(true) {
            loopTotal += last;
            last += m%10; last %= 10;
            if(last == m%10) break;
            loopSize++;
        }
        ll repeat=n/m;
        ll loopRepeat=repeat/loopSize;
        ll ans=loopRepeat*loopTotal;
        REP(i,0,repeat%loopSize) {
            ans += last;
            last += m%10; last %= 10;
        }
        cout<<ans<<endl;
    }
}
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define INF 1e9
#define REP(a,b,c) for(int a=int(b); a<int(c); a++)

const int MX = 1e6+1e5;

int n, m, k;
int h[MX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T; cin>>T;
    while(T--) {
        cin>>n>>m>>k;
        REP(i,0,n) cin>>h[i];
        bool pos=true;
        REP(i,0,n-1) {
            if(h[i] < h[i+1]-k) {
                m -= (h[i+1]-k)-h[i];
                if(m<0) pos=false;
            } else {
                m += h[i]-max(0,h[i+1]-k);
            }
        }
        if(pos) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
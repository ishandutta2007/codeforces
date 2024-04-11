#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define INF 1e9
#define REP(a,b,c) for(int a=int(b); a<int(c); a++)

const int MX=1e5;
int T, s, i, e;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>T;
    while(T--) {
        cin>>s>>i>>e;
        if(e+s <= i) cout<<0<<endl;
        else {
            ll lb=0, ub=e;
            while(lb < ub) {
                ll m=(lb+ub+1)/2;
                if(s+e-m > i+m) lb=m;
                else            ub=m-1;
            }
            cout<<lb+1<<endl;
        }
    }
}
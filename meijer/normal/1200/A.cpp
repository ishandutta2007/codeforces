#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define INF 1e9
#define REP(a,b,c) for(int a=int(b); a<int(c); a++)

int n;
bitset<10> ans;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ans.reset();
    cin>>n;
    REP(i,0,n) {
        char e; cin>>e;
        if(e=='L') {
            REP(i,0,10)
                if(!ans[i])
                    {ans[i]=1; break;}
        } else if(e=='R') {
            REP(i,0,10)
                if(!ans[9-i])
                    {ans[9-i]=1; break;}
        } else {
            ans[e-'0'] = 0;
        }
    }
    REP(i,0,10)
        cout<<ans[i];
    cout<<endl;
}
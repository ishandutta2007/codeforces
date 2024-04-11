#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define INF 1e9
#define REP(a,b,c) for(int a=int(b); a<int(c); a++)

const int MX=3e5;

ll mem[MX][2], s[MX];
ll n, a, b;

ll getAns(ll i, ll j) {
    if(mem[i][j] == -1) {
        if(i == n) {
            mem[i][j] = j?a:0;
        } else {
            if(s[i]) {
                mem[i][j] = getAns(i+1, 1)+b;
                if(!j) mem[i][j] += a;
            } else {
                mem[i][j] = getAns(i+1, j) + j*b;
                if(j && !s[i-1]) mem[i][j] = min(mem[i][j], getAns(i+1, 0)+a);
            }
        }
    }
    return mem[i][j];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t;
    while(t--) {
        cin>>n>>a>>b;
        char ch;
        REP(i,0,n) cin>>ch, s[i]=ch=='1';
        REP(i,0,n+1) mem[i][0]=mem[i][1]=-1;
        cout<<getAns(0,0)+ll(n+1)*b+n*a<<endl;
    }
}
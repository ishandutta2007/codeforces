#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define INF 1e9
#define REP(a,b,c) for(int a=int(b); a<int(c); a++)

const int MX=1000;

int n, m;
int CNT[MX][5];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    REP(j,0,m) REP(i,0,5) CNT[j][i]=0;
    REP(i,0,n) {
        string a;
        cin>>a;
        REP(j,0,m)
            CNT[j][a[j]-'A']++;
    }
    int ans=0;
    REP(j,0,m) {
        int mx=0;
        REP(i,0,5) mx=max(mx, CNT[j][i]);
        int a; cin>>a;
        ans+=mx*a;
    }
    cout<<ans<<endl;
}
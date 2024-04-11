#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define INF 1e9
#define REP(a,b,c) for(int a=int(b); a<int(c); a++)

const int MX = 200;
const int MXM = 1200000;

int n;
int m;
bitset<MX> adjMat[MX];
int distMat[MX][MX];
int p[MXM];
bitset<MXM> skipped;
int removed=0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    REP(i,0,n) {
        string bits;
        cin>>bits;
        REP(j,0,n) adjMat[i][j] = bits[j]=='1';
    }
    cin>>m;
    REP(i,0,m) cin>>p[i], p[i]--;

    REP(i,0,n)
        REP(j,0,n)
            distMat[i][j] = (adjMat[i][j] ? 1 : INF);
    REP(i,0,n)
        distMat[i][i] = 0;
    REP(v,0,n)
        REP(i,0,n)
            REP(j,0,n)
                distMat[i][j] = min(distMat[i][j], distMat[i][v] + distMat[v][j]);

    int b=0;
    skipped.reset();
    REP(i,1,m) {
        if(i == b+1) continue;
        if(distMat[p[b]][p[i]] == i-b) {
            skipped[i-1] = 1;
            removed++;
        } else {
            b = i-1;
        }
    }
    cout<<m-removed<<endl;
    cout<<p[0]+1;
    REP(i,1,m)
        if(!skipped[i])
            cout<<" "<<p[i]+1;
    cout<<endl;
}
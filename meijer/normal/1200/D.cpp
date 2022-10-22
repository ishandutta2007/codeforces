#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define INF 1e9
#define REP(a,b,c) for(int a=int(b); a<int(c); a++)

const int MX = 2000;

int n, k;
bitset<MX> GRID[MX];
ll SEG[MX*4][MX];

int left (int i) {return i*2+1;}
int right(int i) {return i*2+2;}
void buildSeg(int p=0, int l=0, int r=n-1) {
    REP(i,0,n) SEG[p][i] = 0;
    if(l != r) {
        int m=(l+r)/2;
        buildSeg(left(p),l,m);
        buildSeg(right(p),m+1,r);
    }
}
void addSeg(int i, int j, int q, int p=0, int down=0, int l=0, int r=n-1) {
    SEG[p][q] += down;
    if(j<l||i>r) return;
    if(i<=l&&j>=r) {
        SEG[p][q]++;
    } else {
        int m=(l+r)/2;
        addSeg(i,j,q,left(p) ,SEG[p][q],l  ,m);
        addSeg(i,j,q,right(p),SEG[p][q],m+1,r);
        SEG[p][q] = 0;
    }
}
void addSegGrid(int i, int j, int p, int q) {
    i = max(i, 0), j=min(j, n-1);
    p = max(p, 0), q=min(q, n-1);
    if(i > j || p > q) return;
    REP(k,p,q+1)
        addSeg(i, j, k);
}
int getSeg(int i, int q, int p=0, int down=0, int l=0, int r=n-1) {
    SEG[p][q] += down;
    if(i<l||i>r) return 0;
    if(i<=l&&i>=r) {
        return SEG[p][q];
    } else {
        int m=(l+r)/2;
        int a = getSeg(i,q,left(p) ,SEG[p][q],l  ,m);
        int b = getSeg(i,q,right(p),SEG[p][q],m+1,r);
        SEG[p][q] = 0;
        return a+b;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>k;
    REP(i,0,n) {
        REP(j,0,n) {
            char a; cin>>a;
            GRID[i][j] = a=='B';
        }
    }
    buildSeg();

    int mn=0;

    //vert
    REP(i,0,n) {
        int mnB=INF, mxB=-INF;
        REP(j,0,n)
            if(GRID[i][j])
                mnB=min(mnB,j), mxB=max(mxB,j);
        if(mnB == INF) mn++;
        else {
            int len=k-(mxB-mnB+1);
            int lenH = k-1;
            if(len < 0) continue;
            addSegGrid(i-lenH, i, mnB-len, mnB);
        }
    }

    //horizon
    REP(j,0,n) {
        int mnB=INF, mxB=-INF;
        REP(i,0,n)
            if(GRID[i][j])
                mnB=min(mnB,i), mxB=max(mxB,i);
        if(mnB == INF) mn++;
        else {
            int len=k-(mxB-mnB+1);
            int lenV = k-1;
            if(len < 0) continue;
            addSegGrid(mnB-len, mnB,j-lenV, j);
        }
    }

    int ans=0;
    REP(i,0,n)
        REP(j,0,n)
            ans=max(ans, getSeg(i,j));
    cout<<ans+mn<<endl;
}
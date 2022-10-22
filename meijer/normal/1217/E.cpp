#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define INF 2e9
#define REP(a,b,c) for(int a=int(b); a<int(c); a++)

const int MX=2e5+1e4;

int a[MX], n, m;
ii SEG[MX*4][9];

int left (int i) {return (i<<1)+1;}
int right(int i) {return (i<<1)+2;}
ii combineVec(ii a, ii b) {
    ii c;
    c.first = min(a.first, b.first);
    if(a.first == b.first) {
        c.second = a.first;
    } else {
        if(a.first == c.first) {
            c.second = min(a.second, b.first);
        } else {
            c.second = min(b.second, a.first);
        }
    }
    return c;
}
void combineSeg(int p, int i) {
    SEG[p][i] = combineVec(SEG[left(p)][i], SEG[right(p)][i]);
}
void buildSeg(int p=0, int l=0, int r=n-1) {
    if(l == r) {
        int ca = a[l];
        REP(i,0,9) {
            SEG[p][i] = {INF, INF};
            if(ca%10 != 0) SEG[p][i] = {a[l], INF};
            ca /= 10;
        }
    } else {
        int m=(l+r)/2;
        buildSeg(left (p),l,m);
        buildSeg(right(p),m+1,r);
        REP(i,0,9) combineSeg(p, i);
    }
}
void updateSeg(int i, int value, int p=0, int l=0, int r=n-1) {
    if(i < l || i > r) return;
    if(l == r) {
        int ca = value;
        REP(i,0,9) {
            SEG[p][i] = {INF, INF};
            if(ca%10 != 0) SEG[p][i] = {value, INF};
            ca /= 10;
        }
    } else {
        int m=(l+r)/2;
        updateSeg(i, value, left (p), l, m);
        updateSeg(i, value, right(p), m+1, r);
        REP(i,0,9) combineSeg(p, i);
    }
}
ii getValueSeg(int i, int j, int pos, int p=0, int l=0, int r=n-1) {
    if(i > r || j < l) return {INF, INF};
    if(i <= l && j >= r) {
        return SEG[p][pos];
    } else {
        int m=(l+r)/2;
        ii a=getValueSeg(i, j, pos, left(p), l, m);
        ii b=getValueSeg(i, j, pos, right(p), m+1, r);
        return combineVec(a, b);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    REP(i,0,n) cin>>a[i];
    buildSeg();
    int q,l,r;
    REP(i,0,m) {
        cin>>q>>l>>r;
        if(q == 1) {
            updateSeg(--l, r);
        } else {
            l--; r--;
            int ans=INF;
            REP(i,0,9) {
                ii a=getValueSeg(l, r, i);
                if(a.second != INF)
                    ans=min(ans, a.first+a.second);
            }
            if(ans == INF) cout<<-1<<endl;
            else cout<<ans<<endl;
        }
    }
}
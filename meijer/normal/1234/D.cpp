#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define REP(a,b,c) for(int a=int(b); a<int(c); a++)
#define RE(a,c) REP(a,0,c)
#define REV(a,b,c) for(int a=int(c-1); a>=int(b); a--)
#define INF 1e9
#define pb push_back

const int MX=1e5, C='z'-'a'+1;
string s;
int q, l, r, t, pos, n;
char c;
bitset<C> SEG[MX*4];
bitset<C> EMPTYBS;

void buildSeg(int p=0,int l=0,int r=n-1) {
    SEG[p].reset();
    if(l == r) {
        SEG[p][s[l]-'a'] = 1;
    }  else {
        int m=(l+r)/2;
        buildSeg(p*2+1,l,m);
        buildSeg(p*2+2,m+1,r);
        SEG[p] = SEG[p*2+1]|SEG[p*2+2];
    }
}
void updateSeg(int i, int v, int p=0, int l=0, int r=n-1) {
    if(i < l || i > r) return;
    if(i == l && i == r) {
        SEG[p].reset();
        SEG[p][v] = 1;
    } else {
        int m=(l+r)/2;
        updateSeg(i,v,p*2+1,l,m);
        updateSeg(i,v,p*2+2,m+1,r);
        SEG[p] = SEG[p*2+1]|SEG[p*2+2];
    }
}
bitset<C> getSeg(int i, int j, int p=0, int l=0, int r=n-1) {
    if(j < l || i > r) return EMPTYBS;
    if(i <= l && j >= r) {
        return SEG[p];
    } else {
        int m=(l+r)/2;
        bitset<C> a = getSeg(i,j,p*2+1,l,m);
        bitset<C> b = getSeg(i,j,p*2+2,m+1,r);
        return a|b;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    EMPTYBS.reset();
    cin>>s; n=s.size();
    buildSeg();
    cin>>q;
    RE(i,q) {
        cin>>t;
        if(t == 1) {
            cin>>pos>>c; pos--;
            updateSeg(pos, c-'a');
        } else {
            cin>>l>>r; l--; r--;
            cout<<getSeg(l,r).count()<<endl;
        }
    }
}
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define INF 1e9
#define REP(a,b,c) for(int a=int(b); a<int(c); a++)

const int MX=3e5;
int n=0;
string s;
bitset<MX> bs;
bitset<MX*4> SEG;

int left (int i) {return (i<<1)+1;}
int right(int i) {return (i<<1)+2;}
void buildSeg(int i=0, int l=0, int r=n-1) {
    if(l == r) {
        SEG[i] = !bs[l];
    } else {
        int m=(l+r)/2;
        buildSeg(left (i),l,m);
        buildSeg(right(i),m+1,r);
        SEG[i] = SEG[left(i)] && SEG[right(i)];
    }
}
bool allZero(int i, int j, int p=0, int l=0, int r=n-1) {
    if(j < i) return 1;
    if(j<l || i>r) return 1;
    if(i <= l && j >= r) {
        return SEG[p];
    } else {
        int m = (l+r)/2;
        bool a=allZero(i,j,left(p),l,m);
        bool b=allZero(i,j,right(p),m+1,r);
        return a&&b;
    }
}

int countEnd(int e) {
    int b=e, cnt=0, i=0, numb=0;
    while(b!=-1) {
        if(bs[b]) {
            numb += 1<<i;
            if(e-numb+1 < 0) break;
            if(allZero(e-numb+1, b-1)) cnt++;
        }
        b--; i++;
        if(i > 20) break;
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t;
    while(t--) {
        cin>>s; n=s.size();
        REP(i,0,n) bs[i]=s[i]=='1';
        buildSeg();
        int ans=0;
        REP(i,0,n) ans+=countEnd(i);
        cout<<ans<<endl;
    }
}
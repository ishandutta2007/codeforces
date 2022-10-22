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

const int MX=3e5;
int q, n, m;
int a[MX], temp[MX];
int mxI[MX], mnI[MX];
int mem[MX];

int getAns(int l) {
    if(mem[l] == -1) {
        if(mxI[l] < mnI[l+1]) mem[l] = getAns(l+1)+1;
        else mem[l] = 1;
    }
    return mem[l];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>q;
    while(q--) {
        cin>>n;
        RE(i,n) cin>>a[i], a[i]--;
        RE(i,n) temp[i]=0;
        RE(i,n) temp[a[i]]=1;
        REP(i,1,n) temp[i] += temp[i-1];
        RE(i,n) a[i] = temp[a[i]]-1;
        m = temp[n-1];
        RE(i,n) mxI[a[i]] = i, mnI[a[n-i-1]] = n-i-1;
        RE(i,m) mem[i] = -1;
        mem[m-1] = 1;
        int ans=m;
        RE(i,m) ans=min(ans, m-getAns(i));
        cout<<ans<<endl;
    }
}
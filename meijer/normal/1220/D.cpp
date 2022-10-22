#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define REP(a,b,c) for(int a=int(b); a<int(c); a++)
#define RE(a,c) REP(a,0,c)
#define INF 1e9

const int MX=200000, BS=63;
ll n;
ll b[MX];
ll p[MX];
int cnt[BS];

int get2Pow(ll b) {
    int i=0;
    while(1) {
        if(b&1) return i;
        i++;
        b>>=1;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    RE(i,n) cin>>b[i];
    RE(i,n) p[i] = get2Pow(b[i]);
    RE(i,BS) cnt[i] = 0;
    RE(i,n) cnt[p[i]]++;

    int mx=-1, ansP;
    RE(i,BS)
        if(cnt[i]>mx)
            mx=cnt[i], ansP=i;
    cout<<n-mx<<endl;
    if(n-mx == 0) return 0;
    bool first=1;
    RE(i,n)
        if(p[i] != ansP)
            cout<<(first?"":" ")<<b[i], first=0;
    cout<<endl;
}
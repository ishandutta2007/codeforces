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
#define fi first
#define se second

const int MX=2e5;
ll a[MX], b[MX], n, c;
ll sumA[MX], sumB[MX];
ll mem[MX];

ll getA(ll l, ll r) {
    return sumA[r]-sumA[l];
}
ll getB(ll l, ll r) {
    return sumB[r]-sumB[l];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>c;
    RE(i,n-1) cin>>a[i];
    RE(i,n-1) cin>>b[i];
    sumA[0]=sumB[0]=0;
    RE(i,n-1) sumA[i+1]=sumA[i]+a[i], sumB[i+1]=sumB[i]+b[i];
    mem[0] = 0;
    ll minI=0;
    REP(i,1,n) {
        mem[i] = mem[i-1] + getA(i-1,i);
        mem[i] = min(mem[i], mem[minI]+c+getB(minI,i));
        if(mem[i] < mem[minI]+getB(minI,i))
            minI = i;
    }
    RE(i,n)
        cout<<(i==0?"":" ")<<mem[i]; cout<<endl;
}
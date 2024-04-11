#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define REP(a,b,c) for(int a=int(b); a<int(c); a++)
#define RE(a,c) REP(a,0,c)
#define REV(a,b,c) for(int a=int(c-1); a>=int(b); a--)
#define INF 1e18
#define pb push_back

const int MX=3e5;
ll n, q;
ll a[MX], b[MX];
ll mem[MX][3];

ll getAns(int i, int lastChance) {
    if(i >= n) return 0;
    if(mem[i][lastChance] == -1) {
        ll prev = i==0?-1:a[i-1]+lastChance;
        mem[i][lastChance] = INF;
        RE(j,3)
            if(prev != a[i]+j)
                mem[i][lastChance] = min(mem[i][lastChance], j*b[i] + getAns(i+1,j));
    }
    return mem[i][lastChance];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>q;
    while(q--) {
        cin>>n;
        RE(i,n) cin>>a[i]>>b[i];
        RE(i,n) mem[i][0]=mem[i][1]=mem[i][2]=-1;
        cout<<getAns(0,0)<<endl;
    }
}
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define INF 1e9
#define REP(a,b,c) for(int a=int(b); a<int(c); a++)

const int MX=100;

int n, r;
int a[MX], b[MX];
int SA[MX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>r;
    REP(i,0,n) cin>>a[i]>>b[i];
    REP(i,0,n) a[i]=max(a[i],-b[i]);
    REP(i,0,n) SA[i]=i;
    sort(SA, SA+n, [](int A, int B) {
        return a[A]<a[B];
    });
    bool pos=1;
    REP(k,0,n) {
        int i=SA[k];
        if(b[i] < 0) continue;
        if(a[i] > r) pos=0;
        r += b[i];
    }
    sort(SA, SA+n, [](int A, int B) {
        return a[A]+b[A]>a[B]+b[B];
    });
    REP(k,0,n) {
        int i=SA[k];
        if(b[i] >= 0) continue;
        if(a[i] > r) pos=0;
        r += b[i];
    }
    if(r < 0) pos = 0;
    cout<<(pos?"YES":"NO")<<endl;
}
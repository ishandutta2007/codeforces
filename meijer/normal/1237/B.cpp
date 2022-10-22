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
bitset<MX> ticket;
int n, a[MX], b[MX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ticket.reset();
    cin>>n;
    RE(i,n) cin>>b[i], b[i]--;
    RE(i,n) cin>>a[i], a[i]--;

    int j=0;
    RE(i,n) {
        if(ticket[b[i]]) continue;
        while(j != n && a[j] != b[i])
            ticket[a[j++]]=1;
        j++;
        if(j >= n) break;
    }
    cout<<ticket.count()<<endl;
}
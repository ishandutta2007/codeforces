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

const int MX=1e5;
int a, b, c, d;
int tot, mn, mx;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>a>>b>>c>>d;
    tot=a+b+c+d;
    mn = min(a, min(b, min(c, d)));
    mx = max(a, max(b, max(c, d)));
    cout<<(tot-mn-mx==mn+mx||tot-mx==mx?"YES":"NO")<<endl;
}
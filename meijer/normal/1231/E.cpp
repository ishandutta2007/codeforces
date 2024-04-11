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

const int MX=1e5;
int q, n;
string s, t;
string ss, st;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>q;
    while(q--) {
        cin>>n>>s>>t;
        ss = s, st = t;
        sort(ss.begin(), ss.end());
        sort(st.begin(), st.end());
        if(ss != st) {
            cout<<-1<<endl;
            continue;
        }
        int mnAns=n;
        RE(b,n) {
            int i=b, cAns=n;
            RE(j,n)
                if(i != n && t[i] == s[j])
                    i++, cAns--;
            mnAns = min(mnAns, cAns);
        }
        cout<<mnAns<<endl;
    }
}
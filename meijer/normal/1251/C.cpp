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
int t, n;
string a;
string ans;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--) {
        cin>>a; n=a.size();
        ans.clear(); ans.reserve(a.size());
        deque<char> q; bool even=0;
        RE(i,n) {
            if(even != a[i]%2) {
                while(!q.empty() && q.front() < a[i]) {
                    ans.pb(q.front());
                    q.pop_front();
                }
                if(q.empty()) {
                    even = a[i]%2;
                    q.push_back(a[i]);
                } else {
                    ans.pb(a[i]);
                }
            } else {
                q.push_back(a[i]);
            }
        }
        while(!q.empty()) {
            ans.pb(q.front());
            q.pop_front();
        }
        cout<<ans<<endl;
    }
}
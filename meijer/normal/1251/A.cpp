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
int t;
string s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--) {
        cin>>s;
        set<char> working;
        int cnt=0;
        char last=' ';
        RE(i,s.size()) {
            if(s[i] != last) {
                if(cnt % 2)
                    working.insert(last);
                last = s[i];
                cnt = 1;
            } else {
                cnt++;
            }
        }
            if(cnt % 2)
                working.insert(last);
        for(char c:working)
            cout<<c;
        cout<<endl;
    }
}
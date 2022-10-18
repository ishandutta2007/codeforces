#define all(v) v.begin(), v.end()
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz(v) (int(v.size()))
#define pch putchar
#define gch getchar()
#define FORD(i,a,b) for (int i=(a); i<=(b); i++)
#define FORP(i,a,b) for (int i=(a); i>=(b); i--)
#define REP(i,n) for (int i=0; i<(n); i++)
#define clean(v) memset(v,0,sizeof(v))

#include <iostream>
#include <string>
#include <set>

using namespace std;

template<typename T> T sqr(const T& c) {return c*c;} 

typedef long long ll;
typedef double lf;
string s;

set<pair<int,int> > memo;


int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    getline(cin,s);
    pair<int,int> cur(0,0);
    memo.clear();
    memo.insert(cur);
    REP(i,sz(s)) {
        if (s[i]=='U') cur.fs++;
        else if (s[i]=='D') cur.fs--;
        else if (s[i]=='L') cur.sc--;
        else if (s[i]=='R') cur.sc++;
        bool ok = 1;
        if (memo.find(cur)!=memo.end()) ok = 0;
        if (s[i]!='U' && !(memo.find(mp(cur.fs-1,cur.sc))==memo.end())) ok = 0; 
        if (s[i]!='D' && !(memo.find(mp(cur.fs+1,cur.sc))==memo.end())) ok = 0; 
        if (s[i]!='R' && !(memo.find(mp(cur.fs,cur.sc-1))==memo.end())) ok = 0; 
        if (s[i]!='L' && !(memo.find(mp(cur.fs,cur.sc+1))==memo.end())) ok = 0; 
        if (!ok) {
            cout << "BUG\n";
            return 0;
        } else memo.insert(cur);

    }
    cout << "OK\n";
}
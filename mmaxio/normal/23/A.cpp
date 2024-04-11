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
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

template<typename T> T sqr(const T& c) {return c*c;} 

typedef long long ll;
typedef double lf;

vector<string> d;
string s;

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    getline(cin,s);
    FORP(ans,sz(s),1) {
        d.clear();
        REP(st,sz(s)-ans+1) d.pb(s.substr(st,ans));
        //if (ans==3) REP(i,sz(d)) cerr<<d[i] << ' ';
        sort(all(d));
        REP(i,sz(d)-1) if (d[i]==d[i+1]) {printf("%d",ans); return 0;}
    }
    puts("0");
}
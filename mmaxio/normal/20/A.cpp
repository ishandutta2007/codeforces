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

using namespace std;

template<typename T> T sqr(const T& c) {return c*c;} 

typedef long long ll;
typedef double lf;

string s;

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    getline(cin,s);
    bool root = 1;
    REP(i,sz(s)) if (s[i]!='/') root = 0;
    if (root) {
        puts("/");
        return 0;
    }
    int uk = sz(s)-1;
    while (s[uk]=='/') uk--;
    pch(s[0]); FORD(i,1,uk) if (!(s[i]==s[i-1] && s[i]=='/')) pch(s[i]);
}
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

void ok() {
    puts("YES"); exit(0);
}

void fail() {
    puts("NO"); exit(0);
}

bool let(char c) {
    return (c>='A' && c<='Z') || (c>='a' && c<='z') || (c>='0' && c<='9') || c=='_';
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    getline(cin,s);
    int uk = 0, len = 0, n = sz(s);
    while (uk<n && let(s[uk])) uk++, len++;
    if (uk==n || s[uk]!='@' || len<1 || len>16) fail();

    uk++;
    
    int host = 0;
    
    while (1) {
        //cerr << uk << ' ';
        
        len = 0;
        while (uk<n && let(s[uk])) uk++, len++, host++;
        if (len<1 || len>16 ) fail();
        if (uk==n) {if (host>=1 && host<=32) ok(); else fail();}
        if (s[uk]=='/') break;
        if (s[uk]!='.') fail();
        host++, uk++;
    }
    
    if (host<1 || host>32) fail();
    uk++;
    len = 0;
    while (uk<n && let(s[uk])) uk++, len++;
    if (uk!=n) fail();
    if (len<1 || len>16) fail();
    ok();
}
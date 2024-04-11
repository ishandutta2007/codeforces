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
#include <string>
#include <cassert>

using namespace std;

template<typename T> T sqr(const T& c) {return c*c;} 

typedef long long ll;
typedef double lf;

void NumbToLet(int row) {
    int len = 1, col = 26;
    while (row>col) {
        len++, row -= col, col *= 26;
    }
    string res; res.resize(len);
    row--;
    FORP(i,len-1,0) {
        res[i] = 'A'+(row%26);
        row /= 26;
    }
    cout << res;
}

void LetToNumb(string &s) {
    int col = 26; int res1 = 0, res2 = 0;
    REP(i,sz(s)-1) {
        res1 += col;
        col *= 26;
    }
    REP(i,sz(s)) res2 *= 26, res2 += (s[i]-'A');
    printf("%d",res1+res2+1);
}

void gen1(string &s) {
    int uk = 1, row = 0, col = 0;
    while (s[uk]>='0' && s[uk]<='9') {
        row *= 10; row += (s[uk++]-'0');
    }
    uk++;
    while (uk<sz(s)) {
        col *= 10; col += (s[uk++]-'0');
    }
    NumbToLet(col);
    printf("%d",row);
    printf("\n");
}

void gen2(string &s) {
    int uk = 0, col = 0;
    string row = "";
    while (s[uk]>='A' && s[uk]<='Z') row.pb(s[uk++]);
    while (uk<sz(s)) {
        col *= 10; col += (s[uk++]-'0');
    }
    printf("R%d",col);
    printf("C");
    LetToNumb(row);
    printf("\n");
}

int main() {
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n; string s;
    scanf("%d\n",&n);
    REP(i,n) {
        getline(cin,s);
        int uk = 0;
        while (s[uk]>='A' && s[uk]<='Z') uk++;
        bool lol = 1;
        FORD(i,uk,sz(s)-1) lol &= (s[i]>='0'&&s[i]<='9');
        if (!lol) gen1(s); else gen2(s);
    }
}
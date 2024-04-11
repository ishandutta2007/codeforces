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
#include <map>
#include <set>
#include <cstdio>
#include <cstdlib>

using namespace std;

template<typename T> T sqr(const T& c) {return c*c;} 

typedef long long ll;
typedef double lf;

map<string,int> memo;
set<string> win;

string s[1000];
int k[1000];

int main() {
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;
    scanf("%d\n",&n);
    REP(i,n) {
        getline(cin,s[i],' ');
        scanf("%d\n",&k[i]);
        memo[s[i]] += k[i];
    }

    int best = -10000000;
    
    for (map<string,int>::iterator it = memo.begin(); it!=memo.end(); it++) {
        best = max(best, it->sc);
    }

    for (map<string,int>::iterator it = memo.begin(); it!=memo.end(); it++) {
        if (it->sc == best) win.insert(it->fs);
        it->sc = 0;
    }

    REP(i,n) {
        memo[s[i]] += k[i];
        if (win.find(s[i])!=win.end() && memo[s[i]]>=best) {
            cout << s[i] << '\n';
            return 0;
        }
    }

}
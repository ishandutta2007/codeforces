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
#include <algorithm>

using namespace std;

template<typename T> T sqr(const T& c) {return c*c;} 

typedef long long ll;
typedef double lf;

int dd, mm, yy;
int days[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

bool valid(int bd, int bm, int by) {
    bool res = 0;
    if (by % 4 == 0) days[2]++;
    if (bm >= 1 && bm <= 12 && bd>=1 && bd<=days[bm]) {
        if (by<yy-18 || (by==yy-18 && bm<mm) || (by==yy-18 && bm==mm && bd <=dd)) res = 1;
    }
    if (by % 4 == 0) days[2]--;
    return res;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    int b[3];
    scanf("%d.%d.%d",&dd,&mm,&yy);
    scanf("%d.%d.%d",&b[0],&b[1],&b[2]);
    sort(b,b+3);
    do {
        if (valid(b[0],b[1],b[2])) {
            puts("YES");
            return 0;
        }
    } while (next_permutation(b,b+3));
    puts("NO");
}
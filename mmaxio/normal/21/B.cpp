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

using namespace std;

template<typename T> T sqr(const T& c) {return c*c;} 

typedef long long ll;
typedef double lf;

int a1, b1, c1, a2, b2, c2;

int f() {
    if (a1==0 && b1==0 && c1!=0) return 0;
    if (a2==0 && b2==0 && c2!=0) return 0;
    if (a1==0 && b1==0) return -1;
    if (a2==0 && b2==0) return -1;
    if (a1*b2==a2*b1) {
        if (a1*c2==a2*c1 && b1*c2==b2*c1) return -1; else return 0;
    } else return 1;
}


int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    scanf("%d%d%d%d%d%d",&a1,&b1,&c1,&a2,&b2,&c2);
    printf("%d",f());
}
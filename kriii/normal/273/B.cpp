#include <stdio.h>
#include <map>
using namespace std;

map<int, map<int, int> > S;
map<int, map<int, int> >::iterator I;
map<int, int>::iterator J;

int N; long long ans,mod;

int main()
{
    int i,x;

    scanf ("%d",&N);
    for (i=1;i<=N;i++){
        scanf ("%d",&x);
        S[x][i]++;
    }
    for (i=1;i<=N;i++){
        scanf ("%d",&x);
        S[x][i]++;
    }
    scanf ("%lld",&mod);

    ans = 1;
    for (I=S.begin();I!=S.end();I++){
        long long u = 1, p = 0, v, c = 0, d;
        for (J=I->second.begin();J!=I->second.end();J++){
            d = J->second;
            while (d--){
                c++; v = c;
                while (v % 2 == 0) v /= 2, p++;
                u = (u * v) % mod;
            }
            if (J->second == 2) p--;
        }
        while (p--) u = (u * 2) % mod;
        ans = (ans * u) % mod;
    }
    printf ("%lld",ans);

    return 0;
}
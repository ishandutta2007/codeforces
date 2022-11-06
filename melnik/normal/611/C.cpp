#include  <iostream>
#include  <fstream>
#include <list>
#include <stack>
#include <deque>
#include <utility>
#include <queue>
#include <set>
#include <map>
#include <ext\hash_set>
#include <bitset>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <iomanip>
#include <ctime>
#include <iterator>
#include <cstdio>
#include <cstring>
#include <cstdlib>


using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

#define f first
#define s second
#define pb push_back
#define mp make_pair

const int maxn = 520;
const int inf = 2e9;
const double eps = 1e-8;
const int base = 1073676287;

int dp0[maxn][maxn];
int dp1[maxn][maxn] = {0};
int dp2[maxn][maxn] = {0};

void init(int n,int m) {
    int i, j;
    for ( i=0 ;i < n;i++)
        for ( j=0 ;j  <  m-1;j++) {
            if (dp0[i][j]==0&&dp0[i][j+1]==0)
                dp2[i][j]=1;
        }

    for ( i=0;i < n-1;i++)
        for ( j=0;j < m;j++) {
            if (dp0[i][j]==0&&dp0[i+1][j]==0)
                dp1[i][j]=1;
        }
    i=0;
    for ( j=1;j < m;j++) {
        dp2[i][j]+=dp2[i][j-1];
        dp1[i][j]+=dp1[i][j-1];
    }

    j=0;
    for (i=1;i < n;i++) {
        dp2[i][j]+=dp2[i-1][j];
        dp1[i][j]+=dp1[i-1][j];
    }
    for (i=1;i < n;i++)
        for (j=1;j < m;j++) {
            dp2[i][j]+=dp2[i-1][j]+dp2[i][j-1]-dp2[i-1][j-1];
            dp1[i][j]+=dp1[i-1][j]+dp1[i][j-1]-dp1[i-1][j-1];
        }

}


int main()
{
//    srand ( time (0) );
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int n,m;
    scanf("%d %d",&n,&m);
    for (int i = 0 ; i  <  n ; i++) {
        scanf("%*c");
        for (int j = 0 ;j  <  m; j++) {
            char c;
            scanf ("%c",&c);

            if (c == '.')
                dp0[i][j]=0;
            else
                dp0[i][j]=1;
        }
    }
    init(n,m);
    int q;
    scanf("%d",&q);
    while ( q-- ) {
        int x1 , x2 , y1 , y2;
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        int ans=0;
        x1--;
        x2--;
        y1--;
        y2--;
        if (x1>0&&y1>0) {
            if (x1!=x2)
            ans+=(dp1[x2-1][y2]-dp1[x1-1][y2]-dp1[x2-1][y1-1]+dp1[x1-1][y1-1]);
            if (y1!=y2)
            ans+=(dp2[x2][y2-1]-dp2[x1-1][y2-1]-dp2[x2][y1-1]+dp2[x1-1][y1-1]);
            }
        else if (x1==0&&y1>0) {
            if (x1!=x2)
            ans+=(dp1[x2-1][y2]-dp1[x2-1][y1-1]);
            if (y1!=y2) ans+=(dp2[x2][y2-1]-dp2[x2][y1-1]);
        }
        else
            if (y1==0&&x1>0) {
            if (x1!=x2)
                ans+=(dp1[x2-1][y2]-dp1[x1-1][y2]);
            if (y1!=y2)
                ans+=(dp2[x2][y2-1]-dp2[x1-1][y2-1]);
            }
        else {

           if (x1!=x2) ans=dp1[x2-1][y2];
           if (y1!=y2) ans+=dp2[x2][y2-1];

        }
        printf ( "%d\n", ans );
    }
    return 0;
}
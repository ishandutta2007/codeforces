#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<vector>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<ctype.h>
using namespace std;

#define X first
#define Y second
typedef long long ll;
typedef pair<int,int> Pi;

int gc(int x,int y){return y?gc(y,x%y):x;}

int main()
{
    int n, m, x, y, a, b;
    scanf("%d%d%d%d%d%d",&n,&m,&x,&y,&a,&b);
    int g = gc(a, b);
    a /= g, b /= g;

    int mul = min(n/a, m/b);
    a *= mul, b *= mul;
    int x1, y1, x2, y2;
    if(a&1)x1 = x - a/2 - 1, x2 = x + a/2;
    else x1 = x - a/2, x2 = x+a/2;
    if(b&1)y1 = y - b/2 - 1, y2 = y + b/2;
    else y1 = y - b/2, y2 = y+b/2;
    if(x1 < 0)x2 -= x1, x1 = 0;
    if(y1 < 0)y2 -= y1, y1 = 0;
    if(x2 > n)x1 -= x2 - n, x2 = n;
    if(y2 > m)y1 -= y2 - m, y2 = m;
    printf("%d %d %d %d",x1,y1,x2,y2);
    return 0;
}
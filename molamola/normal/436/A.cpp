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

int n, x;
struct str{
    int h, m;
    bool operator<(const str &l)const{
        return h < l.h;
    }
}inp2[2][2020],inp[2][2020];
int top2[2],top[2];

int solve(int t)
{
    int i;
    for(i=0;i<top2[0];i++)inp[0][i] = inp2[0][i];
    for(i=0;i<top2[1];i++)inp[1][i] = inp2[1][i];
    top[0] = top2[0], top[1] = top2[1];
    int now = x;
    int a = t, res = 0;
    while(1){
        for(i=top[a]-1;i>=0;i--){
            if(inp[a][i].h <= now)break;
        }
        if(i == -1)break;
        int mx = i;
        for(int j=i-1;j>=0;j--){
            if(inp[a][mx].m < inp[a][j].m)mx = j;
        }
        now += inp[a][mx].m;
        for(int j=mx;j<top[a]-1;j++)inp[a][j] = inp[a][j+1];
        top[a]--;
        res++;
        a ^= 1;
    }
    return res;
}

int main()
{
    scanf("%d%d",&n,&x);
    int i;
    for(i=1;i<=n;i++){
        int t;scanf("%d",&t);
        if(t == 0)scanf("%d%d",&inp2[0][top2[0]].h,&inp2[0][top2[0]].m), top2[0]++;
        else scanf("%d%d",&inp2[1][top2[1]].h,&inp2[1][top2[1]].m), top2[1]++;
    }
    sort(inp2[0], inp2[0]+top2[0]);
    sort(inp2[1], inp2[1]+top2[1]);
    int ans = 0;
    ans = max(solve(0),solve(1));
    printf("%d",ans);
    return 0;
}
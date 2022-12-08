#include <stdio.h>
#include <algorithm>
#include <map>
using namespace std;

map<int, int> ren;
pair<int, int> u[200002];
int cnt,bit[400004];

int main()
{
    int N;

    scanf ("%d",&N);
    for (int i=0;i<N;i++){
        scanf ("%d %d",&u[i].first,&u[i].second);
        ren[u[i].first+u[i].second] = 0;
        ren[u[i].first-u[i].second] = 0;
    }

    for (auto &p : ren) p.second = ++cnt;
    sort(u,u+N);
    int ans = 0;
    for (int i=0;i<N;i++){
        int see = ren[u[i].first-u[i].second];
        int r = 0;
        for (int x=see;x;x-=x&(-x)) r = max(r,bit[x]);
        r++;
        see = ren[u[i].first+u[i].second];
        for (int x=see;x<=cnt;x+=x&(-x)) bit[x] = max(bit[x],r);
        ans = max(ans,r);
    }

    printf ("%d\n",ans);

    return 0;
}
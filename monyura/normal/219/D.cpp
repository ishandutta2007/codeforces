#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <algorithm>
#include <stack>
#include <string>
#include <functional>
#include <ctime>
#include <complex>
#include <cstring>

using namespace std;

typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef long long ll;

#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;++x)
#define all(a) (a).begin(),(a).end()

struct vert
{
    vector<int> inc;
    vector<int> pr;
    bool was;
    int up;
    int down;
    vert()
    {
        was=0;
        up=down=0;
    }
} g[200200];

void dfs(int k)
{
    g[k].was=1;
    rep(i,0,g[k].inc.size())
        if (!g[g[k].inc[i]].was)
        {
            dfs(g[k].inc[i]);
            g[k].up+=g[g[k].inc[i]].up+!g[k].pr[i];
            g[k].down+=g[g[k].inc[i]].down+g[k].pr[i];
        }
}

int ans=1e9;
vector<int> vec;

void dfsAns(int k,int sum)
{
    int curr=sum+g[k].up;
    if (curr<ans)
    {
        ans=curr;
        vec.clear();
    }
    if (curr==ans)
        vec.push_back(k);
    g[k].was=1;
    rep(i,0,g[k].inc.size())
        if (!g[g[k].inc[i]].was)
            dfsAns(g[k].inc[i],sum+g[k].up-g[g[k].inc[i]].up+g[k].pr[i]-!g[k].pr[i]);
}

int main()
{
    //freopen("condoms.in", "r", stdin); freopen("condoms.out", "w", stdout);
    int n;
    cin>>n;
    rep(i,0,n-1)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        --a;--b;
        g[a].inc.push_back(b);
        g[a].pr.push_back(1);
        
        g[b].inc.push_back(a);
        g[b].pr.push_back(0);
    }
    dfs(0);
    rep(i,0,n)
        g[i].was=0;
    dfsAns(0,0);
    printf("%d\n",ans);
    sort(all(vec));
    rep(i,0,vec.size())
        printf("%d ",vec[i]+1);
    puts("");
    return 0;
}
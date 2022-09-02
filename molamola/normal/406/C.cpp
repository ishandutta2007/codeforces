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

vector <int> be[100010];
int n, m;

struct str{
    str(int x,int y,int z):x(x),y(y),z(z){}
    int x, y, z;
};
vector <str> ans;

int st[100010], en[200020], nxt[200020];
void addE(int s,int e,int c){nxt[c]=st[s],st[s]=c,en[c]=e;}

int chk[100010];

int dfs(int x,int f)
{
    vector <int> vec0;
    vector <Pi> vec1;
    chk[x] = 1;
    int i;
    for(i=st[x];i;i=nxt[i]){
        if(!chk[en[i]]){
            int tmp = dfs(en[i], x);
            if(tmp)vec1.push_back(Pi(en[i],tmp));
            else vec0.push_back(en[i]);
        }
        else if(en[i] != f)be[en[i]].push_back(x);
    }
    for(i=0;i<be[x].size();i++)vec0.push_back(be[x][i]);
    for(i=0;i<vec1.size();i++)ans.push_back(str(x, vec1[i].X, vec1[i].Y));
    int sz = vec0.size();
    for(i=0;i<sz/2;i++)ans.push_back(str(vec0[2*i],x,vec0[2*i+1]));

    if(sz%2 == 1)return vec0.back();
    return 0;
}

int main()
{
    scanf("%d%d",&n,&m);
    int i;
    for(i=1;i<=m;i++){
        int x, y;
        scanf("%d%d",&x,&y);
        addE(x, y, i<<1);
        addE(y, x, i<<1|1);
    }
    for(i=1;i<=n;i++)if(!chk[i])if(dfs(i,-1)){printf("No solution");return 0;}
    for(i=0;i<ans.size();i++)printf("%d %d %d\n",ans[i].x,ans[i].y,ans[i].z);
    return 0;
}
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

int n, k;
vector <Pi> ans;
Pi inp[100010];
inline void add(int s,int d){ans.push_back(Pi(s,d));}

int main()
{
    scanf("%d%d",&n,&k);
    int i;
    for(i=1;i<=n;i++){
        int x;
        scanf("%d",&x);
        inp[i] = Pi(x, i);
    }
    sort(inp+1,inp+1+n);
    if(inp[n].X > n){
        printf("-1");
        return 0;
    }
    vector <int> L[100010];
    for(i=1;i<=n;i++){
        L[inp[i].X].push_back(inp[i].Y);
    }
    if(L[0].size() != 1){
        printf("-1");return 0;
    }
    for(i=1;i<=n;i++){
        int a = L[i].size();
        int b = L[i-1].size();
        if((a && b == 0) || (a+b-1)/b > k-(i==1?0:1)){
            printf("-1");return 0;
        }
        if(a == 0)break;
        int t = (a+b-1)/b;
        int y = a%b;
        if(y == 0)y = b;
        int now = 0;
        for(int j=0;j<y;j++){
            for(int k=0;k<t;k++,now++){
                add(L[i-1][j], L[i][now]);
            }
        }
        for(int j=y;j<b;j++){
            for(int k=0;k<t-1;k++,now++){
                add(L[i-1][j], L[i][now]);
            }
        }
    }
    if(ans.size() != n-1){
        printf("-1");
        return 0;
    }
    printf("%d\n",ans.size());
    for(int i=0;i<ans.size();i++)printf("%d %d\n",ans[i].X, ans[i].Y);
    return 0;
}
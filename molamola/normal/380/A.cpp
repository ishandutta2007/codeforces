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

int m, n;
ll qua[100010][3];
int ans[100010];
struct str{
    ll q;
    int x;
    bool operator<(const str &l)const{
        return q<l.q;
    }
}inp[100010];

int ini[100010];

int main()
{
    scanf("%d",&m);
    int i;
    for(i=1;i<=m;i++){
        scanf("%lld%lld",qua[i],qua[i]+1);
        if(qua[i][0] == 2)scanf("%lld",qua[i]+2);
    }
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%lld",&inp[i].q);
        inp[i].x = i;
    }
    sort(inp+1,inp+1+n);
    ll L = 0;
    int now = 1;
    for(i=1;i<=m;i++){
        if(qua[i][0] == 1){
            ++L;
            if(L <= 1e5)ini[L] = qua[i][1];
            while(now != n+1 && inp[now].q <= L){
                ans[inp[now].x] = qua[i][1];
                now++;
            }
        }
        else{
            if(L <= 1e5){
                int s = L;
                for(int j=1;j<=qua[i][2];j++){
                    for(int k=1;k<=qua[i][1];k++){
                        ini[++s] = ini[k];
                        if(s > 1e5)break;
                    }
                    if(s > 1e5)break;
                }
            }
            L += qua[i][1] * qua[i][2];
            while(now != n+1 && inp[now].q <= L){
                int t = inp[now].q;
                t -= (L-qua[i][1]*qua[i][2]);
                t--;t %= qua[i][1];t++;
                ans[inp[now].x] = ini[t];
                now++;
            }
        }
    }
    for(i=1;i<=n;i++)printf("%d ",ans[i]);
    return 0;
}
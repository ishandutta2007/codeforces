#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<vector>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<ctype.h>
#include<queue>
using namespace std;

#define X first
#define Y second
typedef long long ll;
typedef pair<int,int> Pi;

int st[100010], en[800060], nxt[800060], len[800060];
inline void addE(int s,int e,int l,int c){nxt[c]=st[s],st[s]=c,en[c]=e,len[c]=l;}
int L[100010];
int q[100010][2];
int chk[100010];
int cnt[100010];
int pre[100010];
struct str{
    str(){}
    str(int x,int y,int z):x(x),y(y),z(z){}
    int x,y,z;
    bool operator<(const str &l)const{
        return z == l.z ? y < l.y : z > l.z;
    }
};
priority_queue <str> pq;

int main()
{
    int n, m, k;
    scanf("%d%d%d",&n,&m,&k);
    int i;
    for(i=1;i<=m;i++){
        int x, y, z;
        scanf("%d%d%d",&x,&y,&z);
        addE(x, y, z, i<<1);
        addE(y, x, z, i<<1|1);
    }
    for(i=1;i<=k;i++)scanf("%d%d",q[i],q[i]+1);
    for(i=1;i<=k;i++){
        addE(1, q[i][0], q[i][1], m*2+i*2);
        addE(q[i][0], 1, q[i][1], m*2+i*2+1);
    }
    int ans = 0;
    pq.push(str(1, -1, 0));
    while(!pq.empty()){
        str t = pq.top();
        pq.pop();
        if(chk[t.x])continue;
        chk[t.x] = 1;
        if(t.y == 0)ans++;
        L[t.x] = t.z;
        for(i=st[t.x];i;i=nxt[i]){
            if(chk[en[i]])continue;
            pq.push(str(en[i], i<=2*m+1, t.z + len[i]));
        }
    }
    printf("%d",k-ans);
    return 0;
}
#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>
#include<cctype>
#include<cstdlib>
using namespace std;
typedef pair<int,int>P;
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    queue<P>Q;
    int used[10001];
    fill_n(used,10001,1<<25);
    Q.push(P(n,0));
    while(Q.size()){
        int pos=Q.front().first,cnt=Q.front().second;
        Q.pop();
        if(pos>10000)continue;
        if(pos<0)continue;
        if(used[pos]<=cnt)continue;
        used[pos]=cnt;
        Q.push(P(pos-1,cnt+1));
        Q.push(P(pos*2,cnt+1));
    }
    printf("%d\n",used[m]);
    return 0;
}
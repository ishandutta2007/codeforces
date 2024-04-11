#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<vector>
#include<math.h>
#include<stdlib.h>
using namespace std;

const int R=(1<<17);
int T[2*R];
int n,m;

void fix(int x,int y)
{
    int t=0;
    T[x]=y;
    x>>=1;
    while(x){
        T[x]=t?T[2*x]^T[2*x+1]:T[2*x]|T[2*x+1];
        t^=1;
        x>>=1;
    }
}

int main()
{
//  freopen("input.txt","r",stdin);
    scanf("%d%d",&n,&m);
    int i;
    for(i=0;i<(1<<n);i++){
        scanf("%d",T+R+i);
    }
    int j;
    for(j=17;j;j--){
        for(i=(1<<j-1);i<(1<<j);i++){
            T[i]=j&1?T[2*i]|T[2*i+1]:T[2*i]^T[2*i+1];
        }
    }
    while(m--){
        int x,y;scanf("%d%d",&x,&y);
        fix(x+R-1,y);
        printf("%d\n",T[1]);
    }
    return 0;
}
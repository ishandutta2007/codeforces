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

int main()
{
//  freopen("input.txt","r",stdin);
    int t;
    scanf("%d",&t);
    while(t--){
        int n,p;
        scanf("%d%d",&n,&p);
        int i,x=1,y=2;
        for(i=0;i<2*n+p;i++){
            printf("%d %d\n",x,y);
            y++;
            if(y == n+1)x++,y=x+1;
        }
    }
    return 0;
}
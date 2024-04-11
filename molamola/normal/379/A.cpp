#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<vector>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<ctype.h>
#include<queue>
#include<functional>
using namespace std;

#define X first
#define Y second
typedef long long ll;
typedef pair<int,int> Pi;

int main()
{
//  freopen("input.txt","r",stdin);
    int a,b;
    scanf("%d%d",&a,&b);
    int ans=a;
    while(a>=b){
        int c=a/b;
        ans+=c;
        a=c+a%b;
    }
    printf("%d",ans);
    return 0;
}
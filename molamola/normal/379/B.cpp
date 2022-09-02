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
    int n;
    int p[300];
    int i;
    scanf("%d",&n);
    for(i=1;i<=n;i++)scanf("%d",p+i);
    int now=1;
    for(i=1;i<=n;i++){
        while(p[i]--){
            if(i!=n)printf("PRL");
            else printf("PLR");
        }
        if(i!=n)printf("R");
    }
    return 0;
}
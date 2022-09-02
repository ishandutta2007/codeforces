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
    int n;
    scanf("%d",&n);
    if(n%2 == 0){
        printf("-1");
    }
    else{
        for(int i=0;i<n;i++)printf("%d ",i);
        puts("");
        for(int i=0;i<n;i++)printf("%d ",i);
        puts("");
        for(int i=0;i<n;i++)printf("%d ",(2*i)%n);
    }
    return 0;
}
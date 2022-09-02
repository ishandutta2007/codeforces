
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
    int a, b;
    scanf("%d%d",&a,&b);
    int i, j;
    for(i=1;i<a;i++){
        int tmp = sqrt(a*a - i*i);
        if(tmp*tmp + i*i != a*a)continue;
        for(j=1;j<b;j++){
            int t2 = sqrt(b*b - j*j);
            if(t2*t2 + j*j != b*b)continue;
            if(i*j - t2*tmp == 0){
                if(t2 == tmp)continue;
                printf("YES\n");
                printf("0 0\n");
                printf("%d %d\n",i,tmp);
                printf("%d %d\n",-j,t2);
                return 0;
            }
        }
    }
    printf("NO");
    return 0;
}
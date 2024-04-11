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

int n,inp[100],d;
int s[550010],tmp[550010];

int main()
{
    scanf("%d%d",&n,&d);
    int i,j;
    for(i=1;i<=n;i++)scanf("%d",inp+i);
    tmp[0]=1;
    for(i=1;i<=n;i++){
        for(j=1;j<=10000*i;j++){
            if(j-inp[i]>=0)s[j]=tmp[j]+tmp[j-inp[i]];
            else s[j]=tmp[j];
            if(s[j]>0)s[j]=1;
        }
        for(j=1;j<=10000*i;j++)tmp[j]=s[j];
    }
    int cnt=0;
    for(i=0;i<=10000*n;){
        int tmp=i;
        for(j=i+d;j>i;j--){
            if(s[j]){i=j;cnt++;break;}
        }
        if(tmp==i){printf("%d %d\n",i,cnt);break;}
    }
    return 0;
}
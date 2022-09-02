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

int n;
int a[1010],b[1010],p[1010];

int main()
{
    scanf("%d",&n);
    int i;
    for(i=1;i<=n;i++)scanf("%d",p+i);
    for(i=1;i<n;i++){
        a[i]=p[i],b[i]=p[i+1];
        if(a[i]>b[i]){
            int tmp=a[i];
            a[i]=b[i];
            b[i]=tmp;
        }
    }
    bool f=0;
    for(i=1;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]<b[j] && a[j]<b[i]){
                if(a[i]<a[j] && b[i]<b[j] || a[i]>a[j] && b[i]>b[j])f=1;
            }
        }
    }
    printf("%s",f?"yes":"no");
    return 0;
}
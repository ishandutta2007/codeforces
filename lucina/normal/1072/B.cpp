#include<stdio.h>
#include<algorithm>
using namespace std;
const int maxn=2e5+5;
int n,a[maxn],b[maxn],t[maxn];
int solve(int x){
    if(x==n+1){
        printf("YES\n");
        for(int j=1;j<=n;j++)
        printf("%d ",t[j]);
        printf("\n");
        return 1;
    }
    for(int i=0;i<4;i++){
        t[x]=i;
        if(x>1&&(t[x]|t[x-1])!=a[x-1])
            continue;
        if(x>1&&(t[x]&t[x-1])!=b[x-1])
            continue;
        if(solve(x+1))
            return 1;
    }
    return 0;

}

int main(){
    bool check=true;
    scanf("%d",&n);
    for(int i=1;i<n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<n;i++)
        scanf("%d",&b[i]);
    if(solve(1)==0)
        printf("NO\n");
}
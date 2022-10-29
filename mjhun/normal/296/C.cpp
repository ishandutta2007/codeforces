#include <cstdio>
#include <iostream>
using namespace std;

int a[100005];
int l[100005];
int r[100005];
int d[100005];
int nc[100005];
long long int inc[100005];

int main(){
    int n,m,k,i,j;
    long long int b;
    scanf("%d %d %d",&n,&m,&k);
    for(i=1;i<=n;++i){
        scanf("%d",a+i);
    }
    for(i=1;i<=m;++i){
        scanf("%d %d %d",l+i,r+i,d+i);
    }
    while(k--){
        scanf("%d %d",&i,&j);
        nc[i]++;
        nc[j+1]--;
    }
    j=0;
    for(i=1;i<=m;++i){
        j+=nc[i];
        inc[l[i]]+=((long long int)d[i])*j;
        inc[r[i]+1]-=((long long int)d[i])*j;
    }
    b=0;
    for(i=1;i<=n;++i){
        b+=inc[i];
        cout<<b+a[i]<<' ';
    }
    putchar('\n');
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int x[100005];
int n;

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i)scanf("%d",x+i);
    sort(x,x+n);
    int r=1;
    for(int i=0;i<n;++i)if(x[i]>=r)r++;
    printf("%d\n",r);
    return 0;
}
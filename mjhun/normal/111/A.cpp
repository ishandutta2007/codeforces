#include <cstdio>
#include <iostream>
using namespace std;

int main(){
    int n,i;
    long long x,y;
    cin>>n>>x>>y;
    int m=y-n+1;
    if(y>=n&&((long long)m)*m+n-1>=x){
        printf("%d\n",m);
        for(i=0;i<n-1;++i){
            puts("1");
        }
    }
    else puts("-1");
    return 0;
}
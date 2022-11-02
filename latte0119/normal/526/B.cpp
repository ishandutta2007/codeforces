#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<cstdio>
using namespace std;

int main(){
    int a[1<<12];
    int N;
    scanf("%d",&N);
    for(int i=2;i<=((1<<(N+1))-1);i++){
        scanf("%d",&a[i]);
    }
    int ans=0;

    for(int i=(((1<<(N+1))-1)/2);i>=1;i--){
        ans+=max(a[i*2],a[i*2+1])-min(a[i*2],a[i*2+1]);
        a[i]+=max(a[i*2],a[i*2+1]);
    }

    printf("%d\n",ans);

    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int n,s,gr[100005],x,y,cnt=0;
double d;
int main(){
    scanf("%d%d",&n,&s);
    for(int i=0;i<n-1;i++){
        scanf("%d%d",&x,&y);
        gr[x]++;
        gr[y]++;
    }
    for(int i=1;i<=n;i++){
        if(gr[i]==1) cnt++;
    }
    printf("%.12f",(double)s*2.0/(double)cnt);

}
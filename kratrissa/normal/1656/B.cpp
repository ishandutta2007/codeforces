#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int T,n,k;set<int> s;
int main(){
    scanf("%d",&T);
    while(T--){
        s.clear(),scanf("%d%d",&n,&k);
        for(int i=1,x;i<=n;i++)scanf("%d",&x),s.insert(x);
        bool flag=0;
        for(int x:s)if(s.find(x+k)!=s.end()){flag=1;printf("Yes\n");break;}
        if(!flag)printf("No\n");
    }
    return 0;
}
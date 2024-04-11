#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int T;
int b,p,f;
int h,c;
int main(){
    scanf("%d",&T);
    while(T--){
        int ans=0;
        scanf("%d%d%d",&b,&p,&f);
        scanf("%d%d",&h,&c);
        if(h>c){
            ans+=h*min(b/2,p);
            b-=2*min(b/2,p);
            ans+=c*min(b/2,f);
        }
        else{
            ans+=(c)*min(b/2,f);
            b-=2*min(b/2,f);
            ans+=h*min(b/2,p);
        }
        printf("%d\n",ans);
 
    }
}
/*
    Good Luck
        -Lucina
*/
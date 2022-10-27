#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,t,ans,id,s,d;

int main(){
    ans=1e9;
    int k;
    scanf("%d%d",&n,&t);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&s,&d);
        if(s>=t){
            k=s;
        }
        else{
            k=s+((t-s)/d)*d;
            if(k<t)k+=d;
        }
        if(k<ans){
            ans=k;
            id=i;
        }
        /*s+d*k>t*/
    }
    printf("%d\n",id);

}
#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int t,L,v,l,r;

int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d%d",&L,&v,&l,&r);
        if(l%v)l=((l+v)/v)*v;
        if(r%v)r=v*(r/v);
        printf("%d\n",(L/v)-(l>r?0:(r-l)/v+1));
    }

}
#include<bits/stdc++.h>
using namespace std;
int q,x,y,h,w,u,v;
char f;
int main(){
    scanf("%d",&q);
    for(int i=1;i<=q;i++){
        scanf(" %c %d %d",&f,&u,&v);
        if(f=='+'){
        if(u>v)
            swap(u,v);
        w=max(w,u);
        h=max(h,v);
        }
        else{
            if((w<=u&&h<=v)||(w<=v&&h<=u))
                puts("YES\n");
            else
                puts("NO\n");
        }
    }
}
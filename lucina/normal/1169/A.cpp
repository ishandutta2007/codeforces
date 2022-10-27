#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int a,b,x,y,n;
int main(){
    scanf("%d%d%d%d%d",&n,&a,&x,&b,&y);
    while(true){
        a++;
        b--;
        if(a>n)a-=n;
        if(b==0)b+=n;
        if(a==b){
            return !printf("YES");
        }
        if(a==x)break;
        if(b==y)break;
    }
    return !printf("NO");


}
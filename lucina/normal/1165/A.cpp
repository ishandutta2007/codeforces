#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,x,y,ans;
char s[maxn];

int main(){
    scanf("%d%d%d",&n,&x,&y);
    scanf("%s",s);
    reverse(s,s+n);
    for(int i=0;i<x;i++){
        if(i<y){
            ans+=(s[i]=='1');
        }
        if(i==y){
            ans+=(s[i]=='0');
        }
        if(i>y){
            ans+=(s[i]=='1');
        }
    }
    printf("%d\n",ans);

}
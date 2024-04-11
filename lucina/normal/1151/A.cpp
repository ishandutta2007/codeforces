#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
string base="ACTG";
int n,ans;
char s[200];
int dis(char x,char y){
    if(x>y)swap(x,y);
    return min(y-x,26-y+x);
}
int main(){
    ans=1e9;
    scanf("%d%s",&n,s+1);
    for(int i=1;i+3<=n;i++){
            int sum=0;
        for(int j=0;j<4;j++){
            sum+=(dis(s[i+j],base[j]));
        }
        ans=min(ans,sum);
    }
    printf("%d\n",ans);
}
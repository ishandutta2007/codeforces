#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,s,ans;
int main(){
    scanf("%d%d",&n,&s);
    ans+=(s/n);
    if(s%n)
    ans++;
    printf("%d\n",ans);

}
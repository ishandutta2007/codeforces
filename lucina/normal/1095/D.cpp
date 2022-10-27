#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int a[maxn],n,x,y;
pair<int,int> f[maxn];
bool ch[maxn];

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&f[i].first,&f[i].second);
    }
    a[1]=1;
    ch[1]=true;
    if(f[f[1].first].first!=f[1].second&&f[f[1].first].second!=f[1].second){
        a[2]=f[1].second;
        a[3]=f[1].first;
    }
    else{
        a[2]=f[1].first;
        a[3]=f[1].second;
    }
    ch[a[2]]=true,ch[a[3]]=true;
    for(int i=2;i<=n-2;i++){
        if(ch[f[a[i]].first]){
            a[i+2]=f[a[i]].second;
            ch[a[i+2]]=true;
        }
        else{
            a[i+2]=f[a[i]].first;
            ch[a[i+2]]=true;
        }
    }
    for(int i=1;i<=n;i++){
        printf("%d ",a[i]);
    }
}
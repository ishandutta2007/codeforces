#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int n,m,a[maxn],b[maxn];
map<int,bool> vis;
vector<int> t;

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&a[i],&b[i]);
    }
    int x,y;
    x=sqrt(a[1]),y=a[1];
    for(int i=2;i<=x;i++){
        if(y%i==0){
            if(!vis[i]){
                vis[i]=true;
                t.push_back(i);
            }
            while(y%i==0)y/=i;
        }
        if(y==1)break;
    }
    if(y>1&&!vis[y])vis[y]=true,t.push_back(y);
    y=b[1],x=sqrt(b[1]);
    for(int i=2;i<=x;i++){
        if(y%i==0){
            if(!vis[i]){
                vis[i]=true;
                t.push_back(i);
            }
            while(y%i==0)y/=i;
        }
        if(y==1)break;
    }
    if(y>1&&!vis[y])vis[y]=true,t.push_back(y);
    //cout<<"OK";
    bool flag=true;
    for(auto i:t){
        flag=true;
        for(int j=2;j<=n;j++){
            flag&=(a[j]%i==0||b[j]%i==0);
        }
        if(flag)return printf("%d\n",i),0;
    }
    printf("-1");
   }
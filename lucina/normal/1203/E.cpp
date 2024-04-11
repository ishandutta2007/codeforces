#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n;
int a[maxn];
bool vis[maxn];

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    sort(a+1,a+1+n);
    int ct=0;
    for(int i=n;i>=1;i--){
        if(!vis[a[i]+1]){
            vis[a[i]+1]=true;
            ct++;
            continue;
        }
        if(!vis[a[i]]){
            vis[a[i]]=true;
            ct++;
            continue;
        }
        if(!vis[a[i]-1]&&a[i]>1){
            vis[a[i]-1]=true;
            ct++;
            continue;
        }
    }
    printf("%d\n",ct);
}
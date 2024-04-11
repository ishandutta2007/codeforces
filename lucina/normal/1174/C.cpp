#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,a[maxn],pt;
bool vis[maxn];


int main(){
    scanf("%d",&n);
    for(int i=2;i<=n;i++){
        if(!vis[i]){
            vis[i]=true;
            ++pt;
            for(int j=i;j<=n;j+=i){
                vis[j]=true;
                if(a[j]==0){
                    a[j]=pt;
                }
            }
        }
    }
    for(int i=2;i<=n;i++)
        printf("%d ",a[i]);
}
#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,a[maxn],c[maxn],r[maxn],ma[maxn],mi[maxn];
bool vis[maxn];
map<int,int> t;

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(t.count(c[a[i]])){
            t[c[a[i]]]--;
            if(t[c[a[i]]]==0)
                t.erase(t.find(c[a[i]]));
            }
        c[a[i]]++;
        t[c[a[i]]]++;
        ma[i]=max(ma[i-1],c[a[i]]);
        mi[i]=(t.begin()->first);
        }
        int ct=0;
    for(int i=1;i<=n;i++){
        if(!vis[a[i]]){
            vis[a[i]]=true;
            ct++;
        }
        r[i]=ct;
    }
    for(int i=n;i>=1;i--){
            if(r[i]==1){
                printf("%d\n",i);
                return 0;
            }
            if(mi[i]==1){
                if(1ll*ma[i]*(r[i]-1)==i-1){
                    printf("%d\n",i);
                    return 0;
                }
            }
            if(ma[i]==mi[i]+1){
                if(1ll*r[i]*mi[i]==i-1){
                    printf("%d\n",i);
                    return 0;
                }
            }
        }
    }
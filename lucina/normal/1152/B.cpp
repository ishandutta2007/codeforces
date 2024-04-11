#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=2e6+10;
int x,p[maxn],la;
vector<int> q;
int num;
map<int,bool> vis;

signed main(){
    int j=1;
    for(int i=0;i<=30;i++){
        p[i]=j;
        vis[p[i]]=true;
        j<<=1;
        j++;
    }
    scanf("%d",&x);
    while(true){
        if(vis[x]){
            printf("%d\n",num);
            for(int i:q)
                printf("%d ",i);
            return 0;
        }
        j=-1,la=-1;
        while((1<<(j+1))<=x){
            j++;
            if(((1<<j)&x)==0){
                la=j;
            }
        }
        q.push_back(la);
        num++;
        x^=(p[la]);
        if(vis[x]){
            printf("%d\n",num);
            for(int i:q){
                printf("%d ",i+1);
            }
            return 0;
        }
        x++;num++;
        if(vis[x]){
            printf("%d\n",num);
            for(int i:q){
                printf("%d ",i+1);
            }
            return 0;
        }
    }
}
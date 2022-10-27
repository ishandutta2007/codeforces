#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,p[maxn],pos[maxn],m;
vector<pair<int,int>> ans;
void swp(int i,int j){
    ans.push_back(make_pair(i,j));
    swap(pos[p[i]],pos[p[j]]);
    swap(p[i],p[j]);
    return;
}
void sw(int x){
    if(p[x]==x)return;
    if(abs(pos[x]-x)>=n/2){
        swp(x,pos[x]);
        return;
    }
    if(x<=n/2){
        if(pos[x]<=n/2){
            swp(pos[x],n);
            swp(x,pos[x]);
        }
        else{
            swp(pos[x],1);
            swp(1,n);
            swp(n,x);
            swp(1,pos[1]);
        }
    }
    else if(x>n/2){
        if(pos[x]>n/2){
            swp(pos[x],1);
            swp(1,x);
            swp(1,pos[1]);
        }
    }
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&p[i]);
        pos[p[i]]=i;
    }
    for(int i=1;i<=n;i++)
        sw(i);
    printf("%d\n",ans.size());
    for(auto i:ans){
        printf("%d %d\n",i.first,i.second);
    }
}
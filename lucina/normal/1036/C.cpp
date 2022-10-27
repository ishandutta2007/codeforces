#include<bits/stdc++.h>
using namespace std;
int t,pop[1030];
long long l,r;
vector<long long> a;
void dfs(int pos,long long s,int cnt){
   if(pos==18){
    a.push_back(s);
    return ;
   }
    dfs(pos+1,s*(long long)10,cnt);
    if(cnt<3){
        for(int i=1;i<=9;i++){
            dfs(pos+1,s*(long long)10+i,cnt+1);
        }
    }
    return;
}

int main(){
    dfs(0,0,0);
    a.push_back(1e18);
    sort(a.begin(),a.end());
    a.resize(unique(a.begin(),a.end()) - a.begin());
    scanf("%d",&t);
    while(t--){
        scanf("%lld%lld",&l,&r);
        printf("%d\n",upper_bound(a.begin(),a.end(),r)-lower_bound(a.begin(),a.end(),l));
    }
}
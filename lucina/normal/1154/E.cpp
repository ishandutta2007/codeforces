#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,k,u;
bool vis[maxn],ans[maxn];
vector<pair<int,int>> a;
set<int> s;
int main(){
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%d",&u);
        a.push_back(make_pair(u,i+1));
    }
    sort(a.begin(),a.end());
    for(int i=1;i<=n;i++){
        s.insert(i);
    }
    int x=0;
    while(!a.empty()){
        while(!a.empty()&&vis[a.back().second]){
            a.pop_back();
        }
        if(a.empty())break;
        int pos=a.back().second;
        a.pop_back();
        auto it=s.find(pos);
        vector<int> b;
        for(int i=0;i<=k;i++){
            b.push_back(*it);
            if(it==s.begin())break;
            it--;
        }
        it=next(s.find(pos));
        for(int i=0;i<k;i++){
            if(it==s.end())break;
            b.push_back(*it);
            it++;
        }
        for(auto i:b){
            s.erase(i);
            ans[i]=x;
            vis[i]=true;
        }
        x^=1;
    }
    for(int i=1;i<=n;i++){
        printf("%d",ans[i]+1);
    }
}
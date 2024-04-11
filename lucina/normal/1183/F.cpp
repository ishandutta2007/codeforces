#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int T,n,ans;
vector<int> fact[N];


int main(){
    for(int i=1;i<N;i++){
        for(int j=i;j<N;j+=i)
            fact[j].push_back(i);
    }

    scanf("%d",&T);
    int x,y,z;
    while(T--){
        x=0,y=0,z=0;
        set<int> s;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&x);
            s.insert(x);
        }
        ans=0;
        int x=*s.rbegin();
        ans=x;
        if(x%2==0&&x%3==0&&x%5==0){
            if(s.count(x/2)&&s.count(x/3)&&s.count(x/5)){
                ans=max(ans,x/2+x/3+x/5);
            }
        }
        for(auto i:fact[x]){
            auto it=s.find(i);
            if(it!=s.end())s.erase(it);
        }
        if(s.empty()){
            printf("%d\n",ans);
            continue;
        }
        y=*s.rbegin();
        for(int i:fact[y]){
            auto it=s.find(i);
            if(it!=s.end())s.erase(it);
        }
        if(!s.empty())z=*s.rbegin();
        ans=max(ans,x+y+z);
        printf("%d\n",ans);
        continue;
    }

}
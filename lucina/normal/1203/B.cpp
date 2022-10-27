#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int q,n,a[450],ct[maxn],r[maxn];
void solve(){
    scanf("%d",&n);
    vector<int> res;
    map<int,int> ct;
    for(int i=1;i<=4*n;i++){
        scanf("%d",&a[i]);
        ct[a[i]]++;
    }
    int shit=ct.begin()->first;
    for(auto &i:ct){
        if(i.second%2){printf("NO\n");return;}
        i.second/=2;
        res.push_back(shit*i.first);
    }
    #define bad {ok=false;break;}
    for(auto i:res){
        map<int,int> laz=ct;
        bool ok=true;
        for(auto &j:laz){
            if(j.second==0)continue;
            if(i%j.first)bad;
            int ret=i/j.first;
            if(ret==j.first){
                if(j.second%2)bad;
                j.second=0;
                continue;
            }
            if(laz[ret]<j.second) bad;
            laz[ret]-=j.second;
            j.second=0;
        }
        if(ok){printf("YES\n");return;}
    }
    printf("NO\n");
    return;
}

int main(){
    scanf("%d",&q);
    while(q--){
        solve();
    }
}
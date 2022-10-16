#include<bits/stdc++.h>
using namespace std;
map<string,int>ct,ct2;
vector<pair<string,int>>vv(1);
int n,x;
int main(){
    scanf("%d",&n);
    for(int xx=1;xx<=n;xx++){
        string s;
        cin>>s>>x;
        vv.push_back({s,x});
        ct[s]+=x;
    }
    int mx=0;
    for(auto q:ct)
    mx=max(mx,q.second);
    for(int xx=1;xx<=n;xx++)
    {
        ct2[vv[xx].first]+=vv[xx].second;
        if(ct2[vv[xx].first]>=mx&&ct[vv[xx].first]==mx){
            cout<<vv[xx].first<<endl;
            return 0;
        }
    }
}
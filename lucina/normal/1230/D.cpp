#include<bits/stdc++.h>
using namespace std;
const int maxn = 3e5+10;
int n;
long long a[maxn];
int b[maxn];
using pli = pair<long long ,int>;
vector<pli> v;
long long sum;
long long ans;
int ct[65];
map<long long,int> ss;
map<long long,int> m;
map<long long,long long> s;
bool ch(long long x,long long y){
    return ((x&y) == x);
}
int main(){
    scanf("%d",&n);
    int orsum = 0;
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        ss[a[i]] ++;
        m[a[i]] = i;
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&b[i]);
        s[a[i]] += b[i];
    }
    vector<long long> todel;
    for(auto &j:ss){
        if(j.second == 1) todel.push_back(j.first);
    }
    for(auto i:todel){
        s.erase(s.find(i));
    }
    vector<long long> res;
    for(auto j:s){
        ans += j.second;
        res.push_back(j.first);
    }
   // for(auto i:res){
     //   cerr<<i<<' ';
    //}
   // cerr<<'\n';
    if(res.empty()){
        return !printf("0");
    }
    for(auto i:todel){
        bool ok =false;
        for(auto j:res){
            ok |=ch(i,j);
        }
        if(ok)
            ans += b[m[i]],res.push_back(i);
    }
    printf("%lld\n",ans);
}
/*
    Good Luck
        -Lucina
*/
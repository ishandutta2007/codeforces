#include<bits/stdc++.h>
using namespace std;
void pre(){}
void solve(){
    long long int n,k,d;cin>>n>>k;
    map<long long int,int>m;
    for(int i=0;i<n;i++){
        cin>>d;
        m[d]++;
    }
    long long int ans = (*m.rbegin()).first-(*m.begin()).first;
    while(m.size()>1 && k>0){
        auto i =*m.begin();
        auto j =*m.rbegin();
        if(j.second<i.second){
            auto p = m.rbegin();
            p++;
            auto u = *p;
            auto oo = min(k,(j.first-u.first)*j.second);
            ans-=oo/j.second;
            k-=oo;
            m.erase(j.first);
            m[u.first]+=j.second;
        }else{
            auto p = m.begin();
            p++;
            auto u = *p;
            auto oo = min(k,(u.first-i.first)*i.second);
            ans-=oo/i.second;
            k-=oo;
            m.erase(i.first);
            m[u.first]+=i.second;
        }   
    }
    cout<<ans<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    long long int num = 1;
    //cin>>num;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}
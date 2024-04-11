#include<bits/stdc++.h>
using namespace std;
void pre(){
}
void solve(){
    long long int n,q,a,b;cin>>n>>q;
    pair<long long int,long long int>p1,p2,p3;
    set<pair<long long int,long long int>>s;
    set<pair<pair<long long int,long long int>,pair<long long int,long long int>>>blockages;
    map<pair<long long int,long long int>,set<pair<long long int,long long int>>>m;
    for(long long int i=0;i<q;i++){
        cin>>a>>b;
        long long int t;
        p1=make_pair(a,b);
        if(s.find(make_pair(a,b))!=s.end()){
            s.erase(p1);
            for(auto i:m[p1]){
                blockages.erase(make_pair(i,p1));
                blockages.erase(make_pair(p1,i));
                m[i].erase(p1);
            }
            m.erase(p1);
            if(blockages.size()==0){
                cout<<"Yes"<<"\n";
            }else{
                cout<<"No"<<"\n";
            }
            continue;
        }
        if(a==1){
            t=2;
        }else{
            t=1;
        }
        s.insert(p1);
        if(s.find(make_pair(t,b))!=s.end()){
            p2 = make_pair(t,b);
            blockages.insert(make_pair(p1,p2));
            blockages.insert(make_pair(p2,p1));
            m[p1].insert(p2);
            m[p2].insert(p1);
        }
        if(s.find(make_pair(t,b+1))!=s.end()){
            p2 = make_pair(t,b+1);
            blockages.insert(make_pair(p1,p2));
            blockages.insert(make_pair(p2,p1));
            m[p1].insert(p2);
            m[p2].insert(p1);
        }
        if(s.find(make_pair(t,b-1))!=s.end()){
            p2 = make_pair(t,b-1);
            blockages.insert(make_pair(p1,p2));
            blockages.insert(make_pair(p2,p1));
            m[p1].insert(p2);
            m[p2].insert(p1);
        }
        if(blockages.size()==0){
            cout<<"Yes"<<"\n";
        }else{
            cout<<"No"<<"\n";
        }
    }
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
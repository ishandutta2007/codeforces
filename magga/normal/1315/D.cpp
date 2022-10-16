#include<bits/stdc++.h>
using namespace std;
void pre(){}
void solve(){
    long long int n,d;cin>>n;
    long long int arr[n];
    map<long long int,multiset<long long int>>m;
    for(long long int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(long long int i=0;i<n;i++){
        cin>>d;
        m[arr[i]].insert(d);
    }
    set<pair<long long int,long long int>>curr;
    long long int ans = 0;
    long long int sum = 0;
    long long int index = 0;
    long long int he = 0;
    long long int last = 0;
    for(auto i:m){
        //cout<<i.first<<" "<<ans<<" "<<curr.size()<<"\n";
        d = i.second.size();
        long long int space = i.first-last-1;
        for(long long int i=0;i<space;i++){
            ans+=sum;
            if(curr.size()==0){
                break;
            }
            sum -= -1*(*curr.begin()).first;
            curr.erase(*curr.begin());
        }
        ans+=sum;
        for(long long int j:i.second){
            curr.insert({-1*j,index});
            index++;
            sum+=j;
        }
        sum -= -1*(*curr.begin()).first;
        curr.erase(*curr.begin());
        last=i.first;
    }
    long long int space = curr.size();
    for(long long int i=0;i<space;i++){
            ans+=sum;
            if(curr.size()==0){
                break;
            }
            sum -= -1*(*curr.begin()).first;
            curr.erase(*curr.begin());
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
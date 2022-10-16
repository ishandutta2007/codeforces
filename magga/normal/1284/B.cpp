#include<bits/stdc++.h>
using namespace std;
void solve(){
    long long int n,l;cin>>n;
    long long int re = 0;
    vector<pair<long long int,long long int>>v;
    map<long long int,long long int>m;
    for(long long int i=0;i<n;i++){
        cin>>l;
        long long int arr[l];
        for(long long int i=0;i<l;i++){
            cin>>arr[i];
        }
        if(l==1){
            v.push_back(make_pair(arr[0],arr[0]));
            m[arr[0]]++;
            continue;
        }
        bool flag = false;
        for(long long int i=0;i<l-1;i++){
            if(arr[i]<arr[i+1]){
                flag = true;
                break;
            }
        }
        if(flag){
            re++;
        }else{
            v.push_back(make_pair(arr[l-1],arr[0]));
            if(arr[l-1]==arr[0]){
                m[arr[0]]++;
            }
        }
    }
    sort(v.begin(),v.end());
    long long int ans = 2*n*re - re*re;
    multiset<long long int>s;
    for(long long int i=0;i<v.size();i++){
        s.insert(v[i].second);
        long long int kre = *s.begin();
        while(s.size()!=0 && *s.begin()<=v[i].first){
            long long int kree = *s.begin();
            s.erase(kree);
        }
        //cout<<ans<<" "<<v[i].first<<" "<<v[i].second<<"\n";
        ans+=i+s.size();
    }
    for(pair<long long int,long long int>i:m){
        ans-=(i.second*(i.second-1))/2;
    }
    cout<<ans<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int num = 1;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}
#include<bits/stdc++.h>
using namespace std;
bool check(vector<long long int>a,vector<long long int>&b,long long int ans,long long int m){
    for(long long int i=0;i<a.size();i++){
        a[i]+=ans;
        a[i]%=m;
    }
    sort(a.begin(),a.end());
    if(a==b){
        return true;
    }else{
        return false;
    }
}
void solve(){
    long long int n,m,d;cin>>n>>m;
    set<long long int>se;
    vector<long long int>k;
    vector<long long int>m1;
    map<long long int,long long int>a1;
    map<long long int,long long int>b1;
    for(long long int i=0;i<n;i++){
        cin>>d;
        k.push_back(d);
        a1[d]++;
    }
    for(long long int i=0;i<n;i++){
        cin>>d;
        m1.push_back(d);
        b1[d]++;
    }
    sort(m1.begin(),m1.end());
    sort(k.begin(),k.end());
    long long int a[a1.size()];
    long long int b[2*b1.size()];
    long long int ref1[a1.size()];
    long long int ref2[b1.size()];
    long long int j=0;
    for(auto i:b1){
        b[j]=i.second;
        b[j+b1.size()]=i.second;
        ref2[j]=i.first;
        j++;
    }
    j=0;
    for(auto i:a1){
        a[j]=i.second;
        ref1[j]=i.first;
        j++;
    }
    long long int ans = 0;
    long long int max;
    for(long long int i=0;i<a1.size();i++){
        bool flag = true;
        for(long long int j=0;j<a1.size();j++){
            if(a[j]!=b[j+i]){
                flag=false;
                break;
            }
        }
        if(!flag){
            ans++;
        }else{
            ans = ref2[i]-ref1[0];
            if(ans<0){
                ans+=m;
            }
            se.insert(ans);
        }
    }
    for(auto i:se){
        if(check(k,m1,i,m)){
            cout<<i<<"\n";
            return;
        }
    }
}
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int num=1;
    for(long long int i=0;i<num;i++){
       	solve();
    }
}
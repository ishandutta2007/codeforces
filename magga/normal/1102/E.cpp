#include<bits/stdc++.h>
using namespace std;
const long long int mod = 998244353;
long long int power(long long int x,long long int y){  
    long long int res = 1;
    x = x % mod;
    if (x == 0) return 0;
    while (y > 0){   
        if (y & 1)  
            res = (res*x) % mod;  
        y = y>>1;
        x = (x*x) % mod; 
    }  
    return res;
}  
long long int inv(long long int a){return power(a,mod-2);}
long long int add(long long int a,long long int b){return (a+b)%mod;}
long long int sub(long long int a,long long int b){return (a-b+mod)%mod;}
long long int mul(long long int a,long long int b){return (a*b)%mod;}
void pre(){}
void solve(){
    long long int n;cin>>n; 
    long long int arr[n];
    map<long long int,long long int>m1,m2;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(m1.find(arr[i])==m1.end()){
            m1[arr[i]]=i;
        }
        m2[arr[i]]=i;
    }
    vector<pair<long long int,long long int>>v;
    for(auto i:m1){
        if(i.second!=m2[i.first])
            v.push_back({i.second,m2[i.first]});
    }
    sort(v.begin(),v.end());
    set<long long int>s;
    int j = 0;
    int ans = 0;
    if(j<v.size() && v[j].first==0){
        s.insert(v[j].second);
        j++;
    }
    for(int i=1;i<n;i++){
        while(s.size()>0 && *s.begin()<i){
            s.erase(s.begin());
        }
        if(s.size()==0){
            ans++;
        }
        if(j<v.size() && v[j].first==i){
            s.insert(v[j].second);
            j++;
        }
    }
    cout<<power(2,ans)<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    long long int num = 1;
    //cin>>num;
    for(long long int i=0;i<num;i++){
	//cout<<"Case #"<<i+1<<": ";
       	solve();
    }   
}
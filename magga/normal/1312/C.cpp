#include<bits/stdc++.h>
using namespace std;
void pre(){}
vector<long long int> convert10tob(long long int N,long long int b){
     if (N == 0){
        vector<long long int> v;
        return v;
     }   
     long long int x = N % b;
     N /= b;
     if (x < 0)
        N += 1; 
     auto s = convert10tob(N, b);
     if(x<0){
        s.push_back(x + (b * -1));
     }else{
        s.push_back(x);
     }
    return s;
}
void solve(){
    long long int n,k;cin>>n>>k;
    long long int arr[n];
    for(long long int i=0;i<n;i++){cin>>arr[i];}
    bool flag[100];
    for(long long int i =0;i<100;i++){
        flag[i]=false;
    }
    for(long long int i=0;i<n;i++){
        vector<long long int> j = convert10tob(arr[i],k);
        long long int o = 0;
        if(j.size()==0){
            continue;
        }
        for(long long int m=j.size()-1;m>=0;m--){
            if(m<0){
                continue;
            }
            if(j[m]>1){
                cout<<"NO"<<"\n";
                return;
            }
            if(flag[o] && j[m]==1){
                cout<<"NO"<<"\n";
                return;
            }
            if(j[m]==1){
                flag[o]=1;
            }
            o++;
        }
    }
    cout<<"YES"<<"\n";
}
int main(){
    pre();
    long long int num = 1;
    cin>>num;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}
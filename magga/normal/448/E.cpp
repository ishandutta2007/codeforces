#include<bits/stdc++.h>
using namespace std;
void pre(){}
set<long long int>pd;
struct primeFactorization {
    long long int countOfPf, primeFactor; 
}; 
vector<long long int>ret;
void generateDivisors(long long int curIndex,long long int curDivisor,vector<primeFactorization>& arr){ 
    if (curIndex == arr.size()) { 
        ret.push_back(curDivisor); 
        return; 
    } 
    for (int i = 0; i <= arr[curIndex].countOfPf; ++i) { 
        generateDivisors(curIndex + 1, curDivisor, arr); 
        curDivisor *= arr[curIndex].primeFactor; 
    } 
} 
void generate(long long int n){
    vector<primeFactorization>oo;
    for(auto i:pd){
        if(n%i==0){
            auto j = 0;
            while(n%i==0){
                n/=i;
                j++;
            }
            oo.push_back({j,i});
        }
    }
    generateDivisors(0,1,oo);
    sort(ret.begin(),ret.end());
}
long long int ans[100001];
int j = 0;
void rec(long long int n,long long int x){
    if(j==100000){
        return;
    }    
    if(x==0){
        ans[j]=n;
        j++;
        return;
    }    
    if(n==1){
        ans[j]=1;
        j++;
        return;
    }
    if(pd.find(n)!=pd.end()){
        for(int i=0;i<x;i++){
            if(j==100000)
                return;
            ans[j]=1;
            j++;
        }
        if(j==100000)
            return;
        ans[j]=n;
        j++;
        return;
    }
    generate(n);
    auto oops = ret;
    ret.clear();
    for(auto i:oops){
        rec(i,x-1);
    } 
}
void solve(){
    long long int n,x;cin>>n>>x;
    long long int oo = n;
    for(long long int i=2;i<=sqrt(n);i++){
        if(oo%i==0){
            pd.insert(i);
            while(oo%i==0){
                oo/=i;
            }
        }
    }
    if(oo>1) pd.insert(oo);
    rec(n,x);
    for(int i=0;i<j;i++){
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    solve();
}
#include<bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define filei freopen("input.txt", "r", stdin);
#define fileo freopen("output.txt", "w", stdout);
#define gooi cout<<"Case #"<<i+1<<": ";
#define pii pair<long long int,long long int>
#define F first
#define S second
typedef long long ll;
using namespace std;

#define MAXN   1000001 
int spf[MAXN];  
void sieve(){ 
    spf[1] = 1; 
    for (int i=2; i<MAXN; i++)  spf[i] = i; 
    for (int i=4; i<MAXN; i+=2) spf[i] = 2; 
    for (int i=3; i*i<MAXN; i++){  
        if (spf[i] == i){  
            for (int j=i*i; j<MAXN; j+=i) 
                if (spf[j]==j) 
                    spf[j] = i; 
        } 
    } 
}  
vector<int> getFactorization(int x){ 
    vector<int> ret; 
    while (x != 1){ 
        ret.push_back(spf[x]); 
        x = x / spf[x]; 
    } 
    return ret; 
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void pre(){}
void solve(){
    long long int n,q;cin>>n>>q;
    vector<long long int>divisors;
    for(long long int i=2;i<=n;i++){
        if(n%i==0 && spf[i]==i){
            divisors.push_back(i);
        }
    }
    long long int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<vector<long long int>>vs(divisors.size());
    multiset<long long int>answers;
    for(long long int p=0;p<divisors.size();p++){
        long long int i  = divisors[p];
        long long int nums = n/i;
        for(int j=0;j<nums;j++){
            long long int curr = 0;
            long long int currPoit = j;
            for(int k=0;k<i;k++){
                curr+=arr[currPoit];
                currPoit=(currPoit+nums)%n;
            }
            vs[p].push_back(curr*nums);
            answers.insert(curr*nums);
        }
    }
    cout<<(*answers.rbegin())<<"\n";
    for(int i=0;i<q;i++){
        long long int t,x;cin>>t>>x;
        t--;
        for(long long int p=0;p<divisors.size();p++){
            long long int i  = divisors[p];
            long long int nums = n/i;
            long long int k = t%nums;
            answers.erase(answers.find(vs[p][k]));
            vs[p][k] -= arr[t]*nums;
            vs[p][k] += x*nums;
            answers.insert(vs[p][k]);
        }
        arr[t] = x;
        cout<<(*answers.rbegin())<<"\n";
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    sieve();
    long long int num = 1;
    cin>>num;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}
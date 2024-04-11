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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void pre(){}
long long int nearestSmallerEqFib(long long int n)
{
    if (n == 0 || n == 1)
        return n;
    long long int f1 = 0, f2 = 1, f3 = 1;
    while (f3 <= n)
    {
        f1 = f2;
        f2 = f3;
        f3 = f1 + f2;
    }
    return f2;
}
 
set<long long> FibRepresntation(long long int n)
{
    set<long long int>s;
    while (n > 0)
    {
        long long int f = nearestSmallerEqFib(n);
        s.insert(f);
        n = n - f;
    }
    return s;
}
 
void solve(){
    long long int n,d;cin>>n;
    multiset<long long int>ms;
    long long int sum = 0;
    for(int i=0;i<n;i++){
        cin>>d; 
        sum+=d;
        ms.insert(d);
        // auto t = FibRepresntation(d);
        // for(auto i:t) ms.insert(i);
    }
    long long int fb[50];
    long long int pf[50];
    fb[1]=1;
    fb[2]=1;
    pf[1]=1;
    pf[2]=2;
    for(int i=3;i<=48;i++){
        fb[i] = fb[i-1] + fb[i-2];
        pf[i] = pf[i-1] + fb[i];
    }
    int k = -1;
    for(int i=1;i<=48;i++){
        if(pf[i]==sum){
            k = i;
            break; 
        }
    }
    if(k==-1){
        cout<<"NO"<<"\n";
        return;
    }
    long long int last = 0;
    while(k>0){
        auto i = *ms.rbegin();
        if(i<fb[k]){
            cout<<"NO"<<"\n";
           return;
        }
        ms.erase(ms.find(i));
        ms.insert(last);
        last = i - fb[k];
        k--;
        // if(ms.find(fb[k])==ms.end()){
        //     cout<<"NO"<<"\n";
        //     return;
        // }
        // ms.erase(ms.find(fb[k]));
        // k--;
    }
    cout<<"YES"<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    long long int num = 1;
    cin>>num;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}
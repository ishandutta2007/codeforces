#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define filei freopen("input.txt", "r", stdin);
#define fileo freopen("output.txt", "w", stdout);
#define gooi cout<<"Case #"<<i+1<<" :";
#define INF 1000000000
#define pii pair<long long int,long long int>
#define F first
#define S second
typedef long long ll;
using namespace std;
// Please write the recurances once :(
void pre(){}
void solve(){
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    int t = sqrt(n);
    vector<pair<int,vector<int>>>components;
    pair<int,vector<int>>a;
    a.F = 0;
    components.push_back(a);
    int last = 0;
    for(int i=0;i<n;i++){
        if(arr[i]==1){
            last++;
            cout<<last<<" ";
            components.clear();
            components.push_back(a);
            continue;
        }
        int len = 1;
        int g = arr[i];
        int comp = -1;
        for(int i=components.size()-1;i>=0;i--){
            if( __gcd(g,components[i].F) <= len + components[i].S.size()){
                comp = i;
                break;
            }
            len +=  components[i].S.size();
            g = __gcd(g,components[i].F);
        }
        if(comp!=-1){
            bool flag = 0;
            if(len==g)
                flag = 1;
            for(int i=components[comp].S.size()-1;i>=0;i--){
                len++;
                g = __gcd(g,components[comp].S[i]);
                if(len==g)
                    flag = 1;
            }
            if(flag){
                last++;
                cout<<last<<" ";
                components.clear();
                components.push_back(a);
                continue;
            }
        }
        cout<<last<<" ";
        components.back().S.push_back(arr[i]);
        components.back().F = __gcd(components.back().F,arr[i]);
        if(components.back().S.size()==t){
            components.push_back(a);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    long long int num = 1;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}
/*
each change divides into smaller arrays 
1  - change 
k - all factors of k in truble upto 1e9 so bad
t - gcd falls logn times 
so segment tree?
or sqrt decomp (better)
divide into sqrt packages 
only 2 needed to check 
*/
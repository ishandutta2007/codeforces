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
    vector<int>f(n+1),arr(n);
    set<int>s;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        f[arr[i]]++;
    }   
    for(int i=0;i<=n;i++){
        if(f[i]==0) s.insert(i);
    }
    vector<int>ans;
    int target = *s.begin();
    set<int>curr;
    int cur_mex = 0; 
    for(int i=0;i<n;i++){
        curr.insert(arr[i]);
        while(curr.find(cur_mex)!=curr.end()) cur_mex++;
        f[arr[i]]--;
        if(f[arr[i]]==0) s.insert(arr[i]);
        if(cur_mex==target){
            ans.push_back(cur_mex);
            curr.clear();
            cur_mex = 0;
            target = *s.begin();
        } 
    }
    cout<<ans.size()<<"\n";
    for(auto i:ans) cout<<i<<" ";
    cout<<"\n";
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

// elements are 0 to n 
// a map of remaining in array 
// if 0 then add to set 
// lowermost is mex 
// as soon as hit it 
// do again 
// // if mex > max then only mex 
// //     first occurance of mex + recursive on rest array 


// // else 
// //     first element max // figire out which max
// //     then largest possible max 
// //     until 0 is a mex in dat case add all the remaining as 0
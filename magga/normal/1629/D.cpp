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
    multiset<string>b,f;
    string arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        f.insert(arr[i]);
    }
    bool flag = 0;
    for(int i=0;i<n;i++){
        if(arr[i].size()==1) flag = 1;
        f.erase(f.find(arr[i]));
        string rev = arr[i];
        reverse(rev.begin(),rev.end());
        if(rev==arr[i]) flag = 1;
        if(arr[i].size()==3){
            if(f.find(rev)!=f.end()) flag = 1;
            if(f.find(rev.substr(1))!=f.end()) flag = 1;
        }
        if(arr[i].size()==2){
           if(f.find(rev)!=f.end()) flag = 1;
           for(char i = 'a';i<='z';i++){
               if(f.find(i+rev)!=f.end()) flag = 1;
           } 
        }   
        b.insert(arr[i]);
    }
    if(flag) cout<<"YES"<<"\n";
    else cout<<"NO"<<"\n";
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


// core of any palindrome 
// either 3 (itself a palindrome)
// 1 letterd ending done 
// 3 + 3 (reverse exists)
// 3 + 2 (makes a palindrome)
// 2 + 3 (makes a palindrome)
// 2 + 2 (reverse exists)
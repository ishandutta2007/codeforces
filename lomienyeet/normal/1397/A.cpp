#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int freq[26]={0};
        for(int i=0;i<n;i++){
            string s;
            cin>>s;
            for(auto i:s)freq[i-'a']++;
        }
        for(int i=0;i<26;i++){
            if(freq[i]%n){
                cout<<"NO\n";
                goto e;
            }
        }
        cout<<"YES\n";
        e:;
    }
}
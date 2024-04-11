#include<bits/stdc++.h>
using namespace std;
void pre(){}
int val(char c){return int(c)-int('a');}
void solve(){
    string s,t;cin>>s>>t;
    set<long long int>arr[26];
    for(long long int i=0;i<26;i++){
        arr[i].insert(-2);
        arr[i].insert(s.size()+5);
    }
    for(long long int i=0;i<s.size();i++){
        arr[int(s[i])-int('a')].insert(i);
    }
    long long int in = -1;
    long long int ans = 1;
    long long int k = 0;
    for(long long int i=0;i<t.size();i++){
        if(arr[val(t[i])].size()==2){
            cout<<-1<<"\n";
            return;
        }    
        else{
            auto j = arr[val(t[i])].lower_bound(in);
            k = *j;
            if(k==in){
                j++;
                k = *j;
            }
            //cout<<k<<" "<<in<<"----------\n";
            if(k>s.size()){
                ans++;
                //cout<<i<<"\n";
                auto lo = arr[val(t[i])].begin();
                lo++;
                in = *lo;
            }else{
                in = k;
            }
        }
    }
    cout<<ans<<"\n";
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
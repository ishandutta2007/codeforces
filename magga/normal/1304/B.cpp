#include<bits/stdc++.h>
using namespace std;
void pre(){}
string rev(string s){
    string ret = s;
    for(long long int i=0;i<s.size();i++){
        ret[i]=s[s.size()-1-i];
    }
    return ret;
}
bool isPalindrome(string str){ 
    int l = 0; 
    int h = str.size() - 1; 
    while (h > l) 
    { 
        if (str[l++] != str[h--]) 
        { 
           
            return false; 
        } 
    } 
   return true;
} 
void solve(){
    long long int n,m;cin>>n>>m;
    map<string,long long int>ma;
    queue<string>front;
    stack<string>beck;
    string s;
    long long int ans = 0 ;
    for(long long int i=0;i<n;i++){
        cin>>s;
        if(ma.find(rev(s))!=ma.end() && ma[rev(s)]>0){
            ma[rev(s)]--;
            front.push(s);
            beck.push(rev(s));
        }else{
            ma[s]++;
        }
    }
    string dum;
    for(auto i:ma){
        if(i.second>0 && isPalindrome(i.first)){
            dum = i.first;
            break;
        }
    }
    ans+=( front.size()+beck.size() )*m + dum.size();
    cout<<ans<<"\n";
    while(front.size()!=0){
        cout<<front.front();
        front.pop();
    }
    cout<<dum;
    while(beck.size()!=0){
        cout<<beck.top();
        beck.pop();
    }
    cout<<"\n";
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
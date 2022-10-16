#include<bits/stdc++.h>
using namespace std;
vector<pair<long long int,long long int>>v;
pair<long long int,long long int>p;
string change(long long int i,long long int j,string s){
    string ret = s;
    for(long long int k=i;k<=j;k++){
        ret[k] = s[j-k+i]; 
    }
    return ret;
}
void reshape(long long int a,string &s){
    long long int ref = a;
    for(long long int i = a+1;i<1000000000;i++){
        if(s[i] == '(' ){
            ref = i;
            break;
        }
    }
    s = change(a,ref,s);
    p.first = a;
    p.second = ref;
    v.push_back(p);
}
void reshape1(long long int a,string &s){
    long long int ref = a;
    for(long long int i = a+1;i<1000000000;i++){
        if(s[i] == ')' ){
            ref = i;
            break;
        }
    }
    s = change(a,ref,s);
    p.first = a;
    p.second = ref;
    v.push_back(p);
}
void solve(){
    string target="";
    v.clear();
    long long int n,k;cin>>n>>k;
    for(long long int i=0;i<k-1;i++){
        target+='(';
        target+=')';
    }
    for(long long int i=0;i<=(n-2*k)/2;i++)target+='(';
    for(long long int i=0;i<=(n-2*k)/2;i++)target+=')';
    string s;cin>>s;
    long long int dp = 0;
    for(long long int i = 0;i<n-1;i++){
        if(s[i]!=target[i] && s[i]==')'){
            reshape(i,s);
        }else if(s[i]!=target[i] && s[i]=='('){
            reshape1(i,s);
        }
    }
    //cout<<s<<"\n";
   // cout<<target<<"\n";
    cout<<v.size()<<"\n";
    for(pair<long long int,long long int>p:v){
        cout<<p.first+1<<" "<<p.second+1<<"\n";
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int num = 1;
    cin>>num;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}
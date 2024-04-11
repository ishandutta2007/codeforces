#include<bits/stdc++.h>
using namespace std;
map<char,char>m;
void solve(){
    long long int n;cin>>n;
    string s,t;cin>>s>>t;
    long long int count = 0;
    vector<long long int>v;
    for(long long int i=0;i<n;i++){
        if(s[i]!=t[i]){
            v.push_back(i);
            count++;
        }
    }
    if(count==0){
        cout<<"Yes"<<"\n";
    }else if(count==2 && s[v[0]]==s[v[1]] && t[v[0]]==t[v[1]]){
        cout<<"Yes"<<"\n";    
    }else{
         cout<<"No"<<"\n";    
    }
    
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int num;
    cin>>num;
    for(long long int i=0;i<num;i++)
    {
       	solve();
    }
}
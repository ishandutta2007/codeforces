#include<bits/stdc++.h>
using namespace std;
void solve()
{
    string s,t;cin>>s>>t;
    bool flag = false;
    for(int i=0;i<s.size();i++){
        if(t.find(s[i])!=string::npos){
            flag=true;
        }
    }
    if(flag){
        cout<<"YES"<<"\n";
    }else{
        cout<<"NO"<<"\n";
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
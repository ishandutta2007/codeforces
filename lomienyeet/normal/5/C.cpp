// i am doing tasks with the tag "constructive algorithms", not actual constructives

#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    string s;
    cin>>s;
    stack<int> st;
    int z=0,cur=0,dp[s.length()+5]={};
    for(int i=0;i<s.length();i++){
        if(s[i]=='(')st.push(i);
        else{
            if(st.size()){
                cur+=2;
                st.pop();
                if(st.empty()){
                    z=max(z,cur);
                    dp[cur]++;
                }
                else{
                    dp[i-st.top()]++;
                    z=max(z,i-st.top());
                }
            }
            else cur=0;
        }
    }
    cout<<z<<" "<<(!z?1:dp[z])<<"\n";
}
#include<bits/stdc++.h>
using namespace std;
void pre(){}
void solve(){
    string s;cin>>s;
    long long int n = s.size();
    stack<pair<long long int,bool>>val;
    for(long long int i=0;i<n;i++){
        if(s[i]=='('){
            val.push({1,0});
        }else{
            if(val.size()==0){
                val.push({1,1});
                continue;
            }
            if(val.top().first==1 && val.top().second==0){
                val.pop();
                val.push({2,0});
                long long int tot=0;
                while(val.size()>0 && val.top().first>1){
                    tot+=val.top().first;
                    val.pop();
                }
                val.push({tot,0});
            }else if(val.top().first==1 && val.top().second==1){
                val.push({1,1});
            }else{
                long long int tot = 0;
                while(val.size()>0 && val.top().first>1){
                    tot+=val.top().first;
                    val.pop();
                }    
                if(val.size()>0 && val.top().first==1 && val.top().second==0){
                    val.pop();
                    tot+=2;
                    while(val.size()>0 && val.top().first>1){
                        tot+=val.top().first;
                        val.pop();
                    }
                    val.push({tot,0});
                }else{
                    val.push({tot,0});
                    val.push({1,1});
                }
            }
        }
    }
    pair<long long int,long long int>ans={0,1};
    while(val.size()>0){
        if(val.top().first>1){
            if(ans.first==val.top().first){
                ans.second++;
            }else if(ans.first<val.top().first){
                ans.first=val.top().first;
                ans.second=1;
            }
        }
        val.pop();
    }
    cout<<ans.first<<" "<<ans.second<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    long long int num = 1;
    //cin>>num;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}
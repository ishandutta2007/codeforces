#include<bits/stdc++.h>
using namespace std;
void pre(){}
void solve(){
    string s;cin>>s;
    vector<vector<long long int>>ans;
    bool flag = true;
    long long int n = s.size();
    bool fl[n];
    for(long long int i=0;i<n;i++){
        fl[i]=0;
    }
    while(flag){
        long long int i = 0;
        long long int j = n-1;
        vector<long long int>v,w;
        while(i<n){
            if(fl[i]==0 && s[i]=='('){
                v.push_back(i);
            }
            if(fl[j]==0 && s[j]==')'){
                w.push_back(j);
            }
            i++;
            j--;
        }
        if(v.size()==0 || w.size()==0){
            break;
        }
        if(v[0]>w[0]){
            break;
        }
        i = 0;
        vector<long long int>h;        
        ans.push_back(h);
        long long int k = min(v.size(),w.size());
        while(i<k && v[i]<w[i]){
            flag=true;
            ans[ans.size()-1].push_back(v[i]);
            ans[ans.size()-1].push_back(w[i]);
            fl[v[i]]=1;
            fl[w[i]]=1;
            i++;
        }
    }
    cout<<ans.size()<<"\n";
    for(long long int i=0;i<ans.size();i++){
        sort(ans[i].begin(),ans[i].end());
        cout<<ans[i].size()<<"\n";
        for(long long int i:ans[i]){
            cout<<i+1<<" ";
        }
        cout<<"\n";
    }
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
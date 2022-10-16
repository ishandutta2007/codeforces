#include<bits/stdc++.h>
using namespace std;
void solve(){
    long long int n;cin>>n;
    string s,t;cin>>s>>t;
    bool b = false;
    vector<pair<long long int,long long int>>v;
    for(long long int i=0;i<n;i++){
        if(s[i]==t[i]){
            continue;
        }else{
            b = false;
            for(long long int j=i+1;j<n;j++){
                if(t[j]==t[i]){
                    v.push_back(make_pair(i,j));
                    t[j]=s[i];
                    b=1;
                    break;
                }
            }
            if(b){
                continue;
            }
            for(long long int j=i+1;j<n;j++){
                if(s[j]==s[i]){
                    v.push_back(make_pair(j,i));
                    s[j]=t[i];
                    b=1;
                    break;
                }
            }
            if(b){
                continue;
            }
            for(long long int j=i+1;j<n;j++){
                if(t[j]==s[i]){
                    v.push_back(make_pair(j,j));
                    v.push_back(make_pair(j,i));
                    t[j]=s[j];
                    s[j]=t[i];
                    b=1;
                    break;
                }
            }
            if(b){
                continue;
            }
            cout<<"No"<<"\n";
            return;
        }
    }
    cout<<"Yes"<<"\n";
    cout<<v.size()<<"\n";
    for(pair<long long int,long long int>p:v){
        cout<<p.first+1<<" "<<p.second+1<<"\n";
    }
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int num = 1;
    cin>>num;
    for(long long int i=0;i<num;i++)
    {
       	solve();
    }
}
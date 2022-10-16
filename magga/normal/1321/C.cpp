#include<bits/stdc++.h>
using namespace std;
void pre(){}
int val(char c){return int(c)-'a';}
bool merg(pair<long long int,long long int>p,pair<long long int,long long int>q){
    if(p.first>q.first && p.first>q.second){
        return false;
    }
    if(q.first>p.first && q.first>p.second){
        return false;
    }
    return true;
}
void solve(){
    long long int n,ans=0;cin>>n;
    string s;cin>>s;
    for(long long int i=25;i>=1;i--){
        string t;
        char c = char(i+'a');
        char b = char(i-1+'a');
        for(long long int j=0;j<s.size();j++){
            if(s[j]==c){
                if(t.size()!=0 && t[t.size()-1]==b){
                    continue;
                }
                if(j!=-s.size()-1 && s[j+1]==b){
                    continue;
                }
                long long int k = j;
                while(k<s.size() && s[k+1]==c){
                    k++;
                }
                if(k<s.size() && s[k+1]==b){
                    j=k;
                    continue;
                }
                t+=c;
                while(j!=k){
                    t+=c;
                    j++;
                }
                continue;
            }
            t+=s[j];
        }
        s=t;
    }
    cout<<n-s.size()<<"\n";
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
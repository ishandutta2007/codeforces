#include<bits/stdc++.h>
using namespace std;
void solve(){
    string s;
    string ret;
    cin>>s;
    ret=s;
    if(s[0]=='?'){
      if(s.size()==1 || s[1]=='?'){
          ret[0]='a';
      }else if(s[1]=='a'){
          ret[0]='b';
      }else{
          ret[0]='a';
      }   
    }
    set<char>se,te;
    se.insert('a');
    se.insert('b');
    se.insert('c');
    long long int n = s.size();
    for(long long int i=1;i<n-1;i++){
        te=se;
        if(s[i]=='?'){
            te.erase(ret[i-1]);
            if(s[i+1]!='?'){
                te.erase(s[i+1]);
            }
            ret[i]=*te.begin();
        }else{
            if(s[i]==s[i-1]){
                cout<<-1<<"\n";
                return;
            }
        }
    }
     if(n!=1 && s[n-1]=='?'){
      se.erase(ret[n-2]);
      ret[n-1]=*se.begin();
    }
    if(n>1 && ret[n-1]==ret[n-2]){
        cout<<-1<<"\n";
        return;
    }
    cout<<ret<<"\n";
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
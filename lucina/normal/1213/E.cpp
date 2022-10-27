#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
string s,t;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;
    cin>>n>>s>>t;
    if(s==t){
        if(s[0]==s[1]){
            cout<<"YES\n";
            for(int i=1;i<=n;i++)
            cout<<"abc";
            return 0;
        }
        reverse(s.begin(),s.end());
        for(char c='a';c<='c';c++){
            if(c!=s[0]&&c!=s[1]){
                s+=c;
                break;
            }
        }
        cout<<"YES\n";
        for(int i=1;i<=n;i++)
            cout<<s;
        return 0;
    }
    if(s[0]==s[1]&&t[0]==t[1]){
        cout<<"YES\n";
        for(int i=0;i<n;i++){
            cout<<"abc";
        }
        return 0;
    }
    if(s[0]==t[1]&&s[1]==t[0]){
        string shit;
        /**
        aaaaaaccccccccbbbbbbbb
        */
        char stupid;
        for(stupid='a';stupid<='c';stupid++){
            if(stupid!=s[0]&&stupid!=s[1])
            break;
        }
        cout<<"YES\n";
        for(int i=1;i<=n;i++)
            cout<<s[0];
        for(int i=1;i<=n;i++)
            cout<<stupid;
        for(int i=1;i<=n;i++)
            cout<<s[1];
        return 0;
    }

    if(s[0]==s[1]||t[0]==t[1]){
        string now=(s[0]==s[1])?t:s;
        reverse(now.begin(),now.end());
        for(char c='a';c<='c';c++){
            if(c!=now[0]&&c!=now[1]){
                now+=c;
                break;
            }
        }
        cout<<"YES\n";
        for(int i=0;i<n;i++)
            cout<<now;
        return 0;
    }
    string tot;
    if(s[1]==t[0]){
        tot=s+t[1];
    }
    else if(t[1]==s[0]){
        tot=t+s[1];
    }
    else if(t[0]==s[0]){
       // cout<<"this case?\n";
        tot=tot+t[0]+t[1]+s[1];
        string cur;
        cur = cur+t[1]+s[1];
        cout<<"YES\n";
        for(int i=1;i<=n;i++)
            cout<<cur;
        for(int i=1;i<=n;i++)
            cout<<t[0];
        return 0;
    }
    else if(t[1]==s[1]){
        string cur;
        cur=cur+s[0]+t[0];
        cout<<"YES\n";
        for(int i=1;i<=n;i++)
            cout<<t[1];
        for(int i=1;i<=n;i++)
            cout<<cur;
        return 0;
    }
    else
        throw;
    reverse(tot.begin(),tot.end());
    cout<<"YES\n";
    for(int i=1;i<=n;i++)
        cout<<tot;
    return 0;
    ///
   // ab bc ca
   // ba cb ac
   // aa bb cc
   /**
        bcbcaa
   */
}
/*
    RIP Edelgard
*/
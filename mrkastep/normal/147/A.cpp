#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <queue>

using namespace std;

#define ll long long int
#define For(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
#define mp make_pair
#define x first
#define y second

const int mod=1e9+7;
const int INF=2e9;
const ll LONGINF=4e18;

string s;
int pos;

bool num(char c){
    return (c>='0'&&c<='9');
}

bool letter(char c){
    return (c>='A'&&c<='Z')||(c>='a'&&c<='z');
}

bool sym(char c){
    return c==','||c=='!'||c=='.'||c=='?';
}

string getword(){
    string ans="";
    while(pos<s.size()&&s[pos]==' ') pos++;
    if(pos==s.size()) return ans;
    while(pos<s.size()&&letter(s[pos])){
        ans.pb(s[pos]);
        pos++;
    }
    return ans;
}

string getsym(){
    string ans="";
    while(pos<s.size()&&s[pos]==' ') pos++;
    if(pos==s.size()) return ans;
    if(sym(s[pos])){
        ans.pb(s[pos]);
        pos++;
        return ans;
    }
    return ans;
}







void solve(){
    string ans="",t;
    while(pos<s.size()){
        t=getword();
        if(!t.empty()){
            if(!ans.empty()&&ans.back()!=' '){
                ans+=' ';
            }
            ans+=t;
            continue;
        }
        t=getsym();
        ans+=t+' ';
    }
    if(!ans.empty()&&ans.back()==' '){
        ans.pop_back();
    }
    printf("%s",ans.c_str());




    
}


int main(){
#pragma comment(linker,"/STACK:268435456")
#ifdef HOME
    freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);
#endif
    int n;
    ll a;
    char c[100100];
    while(gets(c)){
        s=c;
        pos=0;
        solve();
    }




    return 0;
}
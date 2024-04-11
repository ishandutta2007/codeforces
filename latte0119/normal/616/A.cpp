#include<bits/stdc++.h>
using namespace std;

//#define int long long

typedef pair<int,int>pint;
typedef vector<int>vint;
typedef vector<pint>vpint;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
template<class T,class U>void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>void chmax(T &t,U f){if(t<f)t=f;}

string s,t;

void Latting(string &x){
    int p=0;
    while(p<x.size()-1&&x[p]=='0')p++;
    x=x.substr(p,x.size()-p);
}

void P(char c){
    printf("%c\n",c);
}

int main(){
    cin>>s>>t;
    Latting(s);
    Latting(t);

    if(s==t)P('=');
    else if(s.size()>t.size())P('>');
    else if(s.size()<t.size())P('<');
    else if(s>t)P('>');
    else P('<');
    return 0;
}
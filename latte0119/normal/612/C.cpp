#include<bits/stdc++.h>
using namespace std;

//#define int long long

typedef pair<int,int>pint;
typedef vector<int>vint;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
template<class T,class U>void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>void chmax(T &t,U f){if(t<f)t=f;}

string s;
char in[]="[<{(";
char out[]="]>})";

int main(){
    cin>>s;
    stack<int>stk;
    int ans=0;
    rep(i,s.size()){
        int x=find(in,in+4,s[i])-in;
        int y=find(out,out+4,s[i])-out;
        if(x!=4)stk.push(x);
        else{
            if(stk.empty()){
                cout<<"Impossible"<<endl;
                return 0;
            }
            if(stk.top()!=y)ans++;
            stk.pop();
        }
    }
    
    if(stk.empty())cout<<ans<<endl;
    else cout<<"Impossible"<<endl;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
typedef vector<int>vint;
typedef pair<int,int>pint;

string s;

int main(){
    cin>>s;
    vector<int>ans;

    while(true){
        string x;
        rep(i,s.size()){
            if(s[i]=='0')x+='0';
            else{
                x+='1';
                s[i]--;
            }
        }
        while(x.size()&&x[0]=='0')x=x.substr(1);
        if(x.size()){
            stringstream ss(x);
            int tmp;ss>>tmp;
            ans.pb(tmp);
        }
        else break;
    }
    cout<<ans.size()<<endl;
    rep(i,ans.size())cout<<ans[i]<<" ";cout<<endl;
    return 0;
}
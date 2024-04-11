#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
typedef vector<int>vint;
typedef pair<int,int>pint;

string C="CODEFORCES";

int main(){
    string s;
    cin>>s;

    for(int i=0;i<s.size();i++){
        for(int j=i+1;j<=s.size();j++){
            if(s.substr(0,i)+s.substr(j)==C){
                cout<<"YES"<<endl;
                return 0;
            }
        }
    }
    cout<<"NO"<<endl;

    return 0;
}
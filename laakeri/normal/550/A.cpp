#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;

int f[101010];

int main(){
    string s;
    cin>>s;
    int n=s.size();
    for (int i=0;i<n-1;i++){
        if (s[i]=='A'&&s[i+1]=='B') f[i]|=1;
        if (s[i]=='B'&&s[i+1]=='A') f[i]|=2;
    }
    int f1=1e9;
    int f2=1e9;
    for (int i=0;i<n;i++){
        if (f[i]&1){
            if (f2<i-1){
                cout<<"YES"<<endl;
                return 0;
            }
            f1=min(f1, i);
        }
        if (f[i]&2){
            if (f1<i-1){
                cout<<"YES"<<endl;
                return 0;
            }
            f2=min(f2, i);
        }
    }
    cout<<"NO"<<endl;
}
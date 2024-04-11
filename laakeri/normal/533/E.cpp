#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    string s,t;
    cin>>n>>s>>t;
    int i2=0;
    int f=0;
    for (int i=0;i<n&&i2<n;i++,i2++){
        if (s[i]!=t[i2]){
            if (f==0){
                i2--;
            }
            else{
                i--;
            }
            f++;
        }
    }
    int v=0;
    if (f==2&&i2==n){
        v++;
    }
    if (f==1&&i2==n-1){
        v++;
    }
    i2=0;
    f=0;
    for (int i=0;i<n&&i2<n;i++,i2++){
        if (t[i]!=s[i2]){
            if (f==0){
                i2--;
            }
            else{
                i--;
            }
            f++;
        }
    }
    if (f==2&&i2==n){
        v++;
    }
    if (f==1&&i2==n-1){
        v++;
    }
    cout<<v<<endl;
}
#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string v;
    string s,t;
    cin>>s>>t;
    int n=s.size();
    int d=0;
    for (int i=0;i<n;i++){
        if (s[i]!=t[i]){
            if (d>0){
                v+=s[i];
                d--;
            }
            else{
                v+=t[i];
                d++;
            }
        }
        else{
            v+=s[i];
        }
    }
    if (d==0){
        cout<<v<<endl;
    }
    else{
        cout<<"impossible"<<endl;
    }
}
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n],b[n];
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++)cin>>b[i];
    int s1=0,s2=0;
    for(int i=0;i<n;i++){
        if(a[i]!=b[i]){
            s1+=a[i];
            s2+=b[i];
        }
    }
    if(!s1||s2==n)cout<<"-1\n";
    else cout<<s2/s1+1<<"\n";
}
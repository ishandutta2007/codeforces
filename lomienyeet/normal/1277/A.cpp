#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int ans=0,a=n,b=n%10,c=0;
        while(a>=10){
            a/=10;
            ans+=9;
            c++;
            b=a%10;
        }
        int e=b;
        for(int i=0;i<c;i++)e=e*10+b;
        if(n>=e)cout<<b+ans<<" ";
        else cout<<b+ans-1<<" ";
    }
}
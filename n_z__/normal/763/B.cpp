#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    cout<<"YES"<<endl;
    while(n--)
    {
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        cout<<2*abs(a%2)+abs(b%2)+1<<endl;
    }
}
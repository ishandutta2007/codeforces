#include<bits/stdc++.h>
using namespace std;
int q[10001],top=0;
int main(){
    int n;
    string s,t;
    cin>>n>>t>>s;
    s=' '+s,t=' '+t;
    for(int x=1,y;x<=n&&top>=0;x++){
    for(y=x;y<=n;y++)if(s[x]==t[y])break;
    if(y==n+1)top=-1;
    else for(int z=y-1;z>=x;z--)q[++top]=z,swap(t[z],t[z+1]);}
    cout<<top<<endl;
    for(int x=1;x<=top;x++)cout<<q[x]<<endl;
}
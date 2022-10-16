#include<bits/stdc++.h>
using namespace std;
#define int long long
double aa[100001];
signed main(){
    string a,b;
    cin>>a>>b;
    int fa=100000-a.length()+1,fb=100000-b.length()+1;
    for(int x=0;x<a.length();x++)
    aa[100000-a.length()+x+1]=a[x]-'0';
    for(int x=0;x<b.length();x++)
    aa[100000-b.length()+x+1]-=b[x]-'0';
    for(int x=min(fa,fb),y;x<=100000-2;x++)
    aa[x+1]+=aa[x],aa[x+2]+=aa[x],aa[x]=0;
    double ans=double(aa[99999]*(1+sqrt(5))/2+aa[100000]);
    //cout<<ans<<endl;
    if(abs(ans)<=1e-8)cout<<'=';
    else if(ans<0)cout<<'<';
    else cout<<'>';
}
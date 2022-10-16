#include<bits/stdc++.h>
#define i long long
using namespace std;map<i,i>m;i n,a,s,t,y,x=1;main(){cin>>n;for(m[0]=1;x<=n;x++)cin>>y,m[s]=x,a+=x-(t=max(t,m[(s+=y)]));cout<<a;}
#include<bits/stdc++.h>
#define int long long
using namespace std;
pair<int,int>a[100001],b[100001];
long double calc(pair<int,int>*u,pair<int,int>*v,int q,int w)
{
    return (long double)(u[q].second-v[w].second)/(u[q].first-v[w].first);
}
main(){
    int n;
    cin>>n;
    for(int q,w,x=1;x<=n;x++)
    cin>>q>>w,a[x]={q,w-q*q};
    sort(a+1,a+1+n);
    int now=0;
    for(int x=1;x<=n;x++)
    {
        while(now&&a[x].first==b[now].first)now--;
        while(now>1&&calc(b,b,now,now-1)<=calc(a,b,x,now))now--;
        b[++now]=a[x];
    }
    cout<<now-1<<endl;
}
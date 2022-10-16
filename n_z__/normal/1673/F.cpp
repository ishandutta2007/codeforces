#include<bits/stdc++.h>
using namespace std;
int lowbit(int x){return x&(-x);}
pair<int,int>f[40001];
int main()
{
    int n,k;
    cin>>n>>k;
    for(int x=1;x<=n;x++){
    for(int y=1;y<n;y++)
    cout<<lowbit(y)*lowbit(y)<<' ';cout<<endl;}
    for(int x=1;x<n;x++){
    for(int y=1;y<=n;y++)
    cout<<2*lowbit(x)*lowbit(x)<<' ';cout<<endl;}
    for(int x=0,qwq=0;x<32;x++)
    {
        qwq^=2*lowbit(x)*lowbit(x);
        int qaq=qwq;
        for(int y=0;y<32;y++)
        qaq^=lowbit(y)*lowbit(y),f[qaq]={x+1,y+1};
    }
    int lst=0;
	while(k--) {
        int x;
        cin>>x;
        x^=lst;
        cout<<f[x].first<<' '<<f[x].second<<endl;
        lst=x;
	}
}
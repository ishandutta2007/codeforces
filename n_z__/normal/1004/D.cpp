#include<bits/stdc++.h> 
using namespace std;
int cc[1000001],cd[1000001];
int main(){
	int t;
    cin>>t;
    int mx=0;
    for(int x=1;x<=t;x++)
    {
        int u;
        cin>>u;
        cc[u]++;
        mx=max(mx,u);
    }
    int fx;
    for(fx=1;fx<=t;fx++)
    if(cc[fx]!=4*fx)break;
    for(int n=1;n<=t;n++)
    if(t%n==0)
    {
        int m=t/n,fy=n+m-fx-mx;
        if(fx>n||fy<=0)continue;
        memset(cd,0,sizeof(cd));
        for(int x=1;x<=n;x++)
        for(int y=1;y<=m;y++)
        cd[abs(x-fx)+abs(y-fy)]++;
        for(int x=0;x<=mx;x++)
        if(cc[x]!=cd[x])goto nxt;
        cout<<n<<' '<<m<<endl<<fx<<' '<<fy<<endl;
        return 0;
        nxt:;
    }
	puts("-1");
}
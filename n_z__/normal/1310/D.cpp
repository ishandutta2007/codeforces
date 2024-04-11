#include<bits/stdc++.h>
using namespace std;
int c[101],d[101][101],f[15][101];
int main()
{
    auto st=clock();
	int n,k;
    cin>>n>>k;
    for(int x=1;x<=n;x++)
    for(int y=1;y<=n;y++)
    cin>>d[x][y];
	srand(time(0));
    int ans=1e9;
	while(clock()-st<=2800)
	{
		for(int x=1;x<=n;x++)
        c[x]=rand()%2;
        for(int x=0;x<=k;x++)
        for(int y=1;y<=n;y++)
        f[x][y]=1e9;
		f[0][1]=0;
        for(int x=0;x<k;x++)
        for(int y=1;y<=n;y++)
        for(int z=1;z<=n;z++)
        if(c[y]!=c[z])f[x+1][z]=min(f[x+1][z],f[x][y]+d[y][z]);
		ans=min(ans,f[k][1]);
	}
	cout<<ans<<endl;
}
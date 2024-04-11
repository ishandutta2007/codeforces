#include<bits/stdc++.h>
using namespace std;
#define int long long
int ans[1001][1001];
main()
{
	int n,k;
	cin>>n>>k;
	int now=1;
	int aans=0;
	while(now<=n){
		now*=k;
		aans++;
		bool bo=false;
		for(int z=0;now*z+1<=n;z++)
		for(int x=1;x<=now&&z*now+x<=n;x++)
		for(int y=x+1;y<=now&&z*now+y<=n;y++)
		if(!ans[z*now+x][z*now+y])
		ans[z*now+x][z*now+y]=aans,bo=true;
		if(bo==false)aans--;
	}
	cout<<aans<<endl;
	for(int x=1;x<=n;x++)
	for(int y=x+1;y<=n;y++)
	cout<<ans[x][y]<<' ';
}
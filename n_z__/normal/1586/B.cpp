#include<bits/stdc++.h>
using namespace std;
#define int long long
bool bo[100001];
main()
{
    int t;cin>>t;while(t--){
    	int n,m;
    	cin>>n>>m;
    	memset(bo,0,sizeof(bo));
    	for(int x=1;x<=m;x++)
    	{
    		int y;
    		cin>>y>>y;
    		bo[y]=true;
    		cin>>y;
    	}
    	for(int x=1;x<=n;x++)
    	if(bo[x]==false)
		{
			for(int y=1;y<=n;y++)
			if(y!=x)cout<<x<<' '<<y<<endl;
			break; 
		}	
    }
}
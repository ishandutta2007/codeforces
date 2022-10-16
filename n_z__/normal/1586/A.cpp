#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[101];
main()
{
    int t;cin>>t;while(t--){
    	int n;cin>>n;
    	int s=0;
    	for(int x=1;x<=n;x++)
    	cin>>a[x],s+=a[x];
    	for(int x=2;x*x<=s;x++)
    	if(s%x==0){
    		cout<<n<<endl;
    		for(int z=1;z<=n;z++)
    		cout<<z<<' ';cout<<endl;
    		goto nxt;
    	}
    	for(int x=1;x<=n;x++)
    	{
    		for(int y=2;y*y<=s-a[x];y++)
    		if((s-a[x])%y==0){
	    		cout<<n-1<<endl;
	    		for(int z=1;z<=n;z++)
	    		if(x!=z)cout<<z<<' ';cout<<endl;
	    		goto nxt;
    		}
    	}
    	if(n==3)cout<<1<<endl<<a[1]<<endl;
    	else if(n==2)cout<<1<<endl<<a[1]<<endl;
    	nxt:;
    }
}
#include<iostream>
#include<vector>
using namespace std;
bool isp(int N)
{
	if(N==1)return false;
	for(int i=2;i*i<=N;i++)if(N%i==0)return false;
	return true;
}
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		int X,D;
		cin>>X>>D;
		X/=D;
		if(X%D!=0)cout<<"NO\n";//{X}
		else if(X==D)cout<<"NO\n";//{D}
		else
		{
			X/=D;
			int cnt=2;
			while(X%D==0)X/=D,cnt++;
			if(X==1)
			{
				if(isp(D))cout<<"NO\n";//{D}
				else cout<<"YES\n";//{D},{aD,bD}(ab=D)
			}
			else if(isp(X))
			{
				if(cnt==2||isp(D))cout<<"NO\n";//{D,DX}
				else
				{
					int nc=0;
					while(D%X==0)D/=X,nc++;
					if(D>1)cout<<"YES\n";
					else if(nc==2)
					{
						if(cnt>=4)cout<<"YES\n";
						else cout<<"NO\n";
					}
					else cout<<"YES\n";
				}
			}
			else cout<<"YES\n";//{D,DX},{D,aD,bD}(ab=X)
		}
	}
}
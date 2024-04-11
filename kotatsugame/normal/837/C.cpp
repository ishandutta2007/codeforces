#include<iostream>
using namespace std;
int N,H,W;
int x[100],y[100];
main()
{
	cin>>N>>H>>W;
	for(int i=0;i<N;i++)cin>>x[i]>>y[i];
	int ans=0;
	for(int i=0;i<N;i++)for(int j=i+1;j<N;j++)
	{
		int now=x[i]*y[i]+x[j]*y[j];
		if(x[i]+x[j]<=H&&y[i]<=W&&y[j]<=W
			||x[i]+x[j]<=W&&y[i]<=H&&y[j]<=H
			||x[i]+y[j]<=H&&y[i]<=W&&x[j]<=W
			||x[i]+y[j]<=W&&y[i]<=H&&x[j]<=H
			||y[i]+x[j]<=H&&x[i]<=W&&y[j]<=W
			||y[i]+x[j]<=W&&x[i]<=H&&y[j]<=H
			||y[i]+y[j]<=H&&x[i]<=W&&x[j]<=W
			||y[i]+y[j]<=W&&x[i]<=H&&x[j]<=H)
		{
			if(ans<now)ans=now;
		}
	}
	cout<<ans<<endl;
}
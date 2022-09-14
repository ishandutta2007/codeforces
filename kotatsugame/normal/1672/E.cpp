#include<iostream>
using namespace std;
int N;
int ask(int W)
{
	cout<<"? "<<W<<endl;
	int ret;
	cin>>ret;
	return ret;
}
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>N;
	int SL=0,SR=N*2000+N-1;
	while(SR-SL>1)
	{
		int mid=(SL+SR)/2;
		int h=ask(mid);
		if(h==1)SR=mid;
		else SL=mid;
	}
	int S=SR;
	int ans=S;
	for(int h=2;h<=N;h++)
	{
		int w=(S-1)/h;
		int nh=ask(w);
		if(nh!=0)ans=min(ans,nh*w);
	}
	cout<<"! "<<ans<<endl;
}
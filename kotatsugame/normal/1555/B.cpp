#include<iostream>
#include<algorithm>
using namespace std;
int T;
int W,H;
int w,h;
main()
{
	cin>>T;
	for(;T--;)
	{
		int x1,x2,y1,y2;
		cin>>W>>H>>x1>>y1>>x2>>y2>>w>>h;
		int nw=x2-x1,nh=y2-y1;
		int ans=1e9;
		if(w+nw<=W)
		{
			ans=min(ans,max(w-x1,0));
			ans=min(ans,max(x2-(W-w),0));
		}
		if(h+nh<=H)
		{
			ans=min(ans,max(h-y1,0));
			ans=min(ans,max(y2-(H-h),0));
		}
		if(ans==(int)1e9)ans=-1;
		cout<<ans<<endl;
	}
}
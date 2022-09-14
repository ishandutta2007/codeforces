#include<iostream>
using namespace std;
int T,N;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N;
		int l=0,r=N;
		while(r-l>1)
		{
			int mid=(l+r)/2;
			cout<<"? 1 "<<mid<<endl;
			int cnt=0;
			for(int i=0;i<mid;i++)
			{
				int a;cin>>a;
				cnt+=a<=mid;
			}
			if(cnt%2==1)r=mid;
			else l=mid;
		}
		cout<<"! "<<r<<endl;
	}
}
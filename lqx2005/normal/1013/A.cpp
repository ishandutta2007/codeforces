#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    long long maxx=0,ans,maxy=0;
    bool k=true;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
    	cin>>ans;
    	maxx=maxx+ans;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>ans;
		maxy=maxy+ans;
	}
	if(maxx>=maxy)
	{
		cout<<"Yes"<<endl;
	}
	else
	{
		cout<<"No"<<endl;
	}
    return 0;
}
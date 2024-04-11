#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
main()
{
    ios::sync_with_stdio(false),cin.tie(),cout.tie();
	int q;
	cin>>q;
	while(q--)
	{
        string s;
		cin>>s;
		int ans1=10,ans2=10;
		int now1=0,now2=0;
		for(int x=1;x<=5;x++)
		{
			if(s[2*(x-1)]!='0')now1+=1;
			if(now1-now2>6-x){ans1=2*x-1;break;}
			if(s[2*(x-1)+1]=='1')now2+=1;
			if(now1-now2>5-x){ans1=2*x;break;}
			//cout<<x<<','<<now1<<','<<now2<<endl;
        }
		now1=now2=0;
		for(int x=1;x<=5;x++)
		{
			if(s[2*(x-1)]=='1')now1+=1;
			if(now2-now1>5-x){ans2=2*x-1;break;}
			if(s[2*(x-1)+1]!='0')now2+=1;
			if(now2-now1>5-x){ans2=2*x;break;}
			//cout<<x<<','<<now1<<','<<now2<<endl;
		}
		cout<<min(ans1,ans2)<<endl;
    }
}
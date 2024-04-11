#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int T,N;
int A,B,AB,BA;
string S;
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	vector<int>all,ab,ba;
	for(;T--;)
	{
		cin>>A>>B>>AB>>BA>>S;
		{
			int ac=0,bc=0;
			for(char c:S)
			{
				if(c=='A')ac++;
				else bc++;
			}
			if(ac!=A+AB+BA||bc!=B+AB+BA)
			{
				cout<<"NO\n";
				continue;
			}
		}
		all.clear();
		ab.clear();
		ba.clear();
		int absum=0,basum=0,allsum=0;
		for(int i=0;i<S.size();)
		{
			int j=i;
			while(j<S.size()&&((j-i)%2==0)==(S[j]==S[i]))j++;
			int len=j-i;
			char fst=S[i];
			i=j;
			if(len%2==1)
			{
				all.push_back(len);
				allsum+=len/2;
			}
			else
			{
				if(fst=='A')
				{
					ab.push_back(len);
					absum+=len/2;
				}
				else
				{
					ba.push_back(len);
					basum+=len/2;
				}
			}
		}
		if(AB<=absum)
		{
			if(BA<=basum)
			{
				cout<<"YES\n";
			}
			else
			{
				BA-=basum;
				BA-=allsum;
				if(BA<=0)cout<<"YES\n";
				else
				{
					sort(ab.begin(),ab.end());
					for(int i=ab.size();i--;)
					{
						int u=(ab[i]-2)/2;
						u=min(BA,u);
						BA-=u;
						if(u>0)ab[i]-=u*2+2;
						AB-=ab[i]/2;
					}
					if(BA<=0&&AB<=0)cout<<"YES\n";
					else cout<<"NO\n";
				}
			}
		}
		else
		{
			if(BA<=basum)
			{
				AB-=absum;
				AB-=allsum;
				if(AB<=0)cout<<"YES\n";
				else
				{
					sort(ba.begin(),ba.end());
					for(int i=ba.size();i--;)
					{
						int u=(ba[i]-2)/2;
						u=min(AB,u);
						AB-=u;
						if(u>0)ba[i]-=u*2+2;
						BA-=ba[i]/2;
					}
					if(AB<=0&&BA<=0)cout<<"YES\n";
					else cout<<"NO\n";
				}
			}
			else
			{
				AB-=absum;
				BA-=basum;
				if(AB+BA<=allsum)cout<<"YES\n";
				else cout<<"NO\n";
			}
		}
	}
}
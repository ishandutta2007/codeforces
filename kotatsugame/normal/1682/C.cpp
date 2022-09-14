#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int T,N;
int A[2<<17];
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	vector<int>v;
	for(;T--;)
	{
		cin>>N;
		for(int i=0;i<N;i++)cin>>A[i];
		sort(A,A+N);
		v.clear();
		for(int i=0;i<N;)
		{
			int j=i+1;
			while(j<N&&A[i]==A[j])j++;
			v.push_back(j-i);
			i=j;
		}
		bool one=false;
		int l=0,r=0;
		for(int i=0;i<v.size();)
		{
			if(v[i]>1)
			{
				l++;
				r++;
				i++;
			}
			else
			{
				one=true;
				int c=0;
				while(i<v.size()&&v[i]==1)i++,c++;
				if(c%2==0)l+=c/2,r+=c/2;
				else
				{
					if(l<=r)l+=c/2+1,r+=c/2;
					else l+=c/2,r+=c/2+1;
				}
			}
		}
		if(one)
		{
			if(l<=r)l++;
			else r++;
		}
		cout<<min(l,r)<<"\n";
	}
}
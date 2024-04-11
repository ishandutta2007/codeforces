#include<iostream>
#include<vector>
using namespace std;
int N,A[2<<17];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		cin>>N;
		int cnt=0;
		for(int i=0;i<N;i++)
		{
			cin>>A[i];
			if(A[i]!=0)cnt++;
		}
		if(cnt%2==1)
		{
			cout<<"-1\n";
			continue;
		}
		vector<pair<int,int> >ans;
		for(int i=0;i<N;)
		{
			if(A[i]==0)
			{
				ans.push_back(make_pair(i,i+1));
				i++;
				continue;
			}
			int j=i+1;
			while(A[j]==0)j++;
			if(A[i]!=A[j])
			{
				ans.push_back(make_pair(i,j));
				ans.push_back(make_pair(j,j+1));
			}
			else
			{
				if((j-i)%2==1)
				{
					ans.push_back(make_pair(i,j+1));
				}
				else
				{
					ans.push_back(make_pair(i,j-1));
					ans.push_back(make_pair(j-1,j+1));
				}
			}
			i=j+1;
		}
		cout<<ans.size()<<"\n";
		for(pair<int,int>p:ans)cout<<p.first+1<<" "<<p.second<<"\n";
	}
}
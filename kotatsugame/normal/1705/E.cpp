#include<iostream>
#include<set>
#include<vector>
using namespace std;
int N,Q;
int A[2<<17];
int cnt[2<<17];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>N>>Q;
	for(int i=0;i<N;i++)
	{
		cin>>A[i];
		cnt[A[i]]++;
	}
	for(int i=1;i<2<<17;i++)if(cnt[i]>=2)
	{
		cnt[i+1]+=cnt[i]/2;
		cnt[i]%=2;
	}
	set<pair<int,int> >S;
	for(int i=1;i<2<<17;)
	{
		if(cnt[i]==0)i++;
		else
		{
			int j=i;
			while(cnt[j]==1)j++;
			S.insert(make_pair(i,j));
			i=j;
		}
	}
	for(;Q--;)
	{
		int k,l;cin>>k>>l;k--;
		{
			int a=A[k];
			auto it=S.lower_bound(make_pair(a+1,-1));
			bool del=false;
			if(it!=S.begin())
			{
				it--;
				if(a<it->second)
				{
					del=true;
					int l=it->first,r=it->second;
					S.erase(it);
					if(l<a)S.insert(make_pair(l,a));
					if(a+1<r)S.insert(make_pair(a+1,r));
				}
				else it++;
			}
			if(!del)
			{
				int l=it->first,r=it->second;
				S.erase(it);
				if(l+1<r)S.insert(make_pair(l+1,r));
				it=S.lower_bound(make_pair(a+1,-1));
				bool add=false;
				if(it!=S.begin())
				{
					it--;
					if(it->second==a)
					{
						add=true;
						int nl=it->first;
						S.erase(it);
						S.insert(make_pair(nl,l));
					}
				}
				if(!add)S.insert(make_pair(a,l));
			}
		}
		A[k]=l;
		{
			int a=A[k];
			auto it=S.lower_bound(make_pair(a+1,-1));
			bool ins=false;
			if(it!=S.begin())
			{
				it--;
				if(a<it->second)
				{
					ins=true;
					int l=it->first,r=it->second;
					S.erase(it);
					if(l<a)S.insert(make_pair(l,a));
					//[r,r+1)
					it=S.lower_bound(make_pair(r+1,-1));
					if(it!=S.end()&&it->first==r+1)
					{
						int nr=it->second;
						S.erase(it);
						S.insert(make_pair(r,nr));
					}
					else S.insert(make_pair(r,r+1));
				}
				else it++;
			}
			if(!ins)
			{
				int nr;
				if(it!=S.end()&&it->first==a+1)
				{
					int r=it->second;
					S.erase(it);
					it=S.insert(make_pair(a,nr=r)).first;
				}
				else it=S.insert(make_pair(a,nr=a+1)).first;
				if(it!=S.begin())
				{
					it--;
					if(it->second==a)
					{
						int l=it->first;
						S.erase(it);
						S.erase(make_pair(a,nr));
						S.insert(make_pair(l,nr));
					}
				}
			}
		}
		cout<<S.rbegin()->second-1<<"\n";
	}
}
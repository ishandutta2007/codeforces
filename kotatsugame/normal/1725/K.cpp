#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
using namespace std;
vector<pair<int,set<int> > >S;
int itoS[4<<17];
map<int,int>htoS;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N;
	cin>>N;
	auto make=[](int h)
	{
		if(htoS.find(h)==htoS.end())
		{
			S.push_back(make_pair(h,set<int>()));
			htoS[h]=S.size()-1;
		}
		return htoS[h];
	};
	for(int i=0;i<N;i++)
	{
		int a;cin>>a;
		S[itoS[i]=make(a)].second.insert(i);
	}
	int Q;cin>>Q;
	for(int q=0;q<Q;q++)
	{
		int op;cin>>op;
		if(op==1)
		{
			int i,h;cin>>i>>h;i--;
			int si=itoS[i];
			S[si].second.erase(i);
			S[itoS[i]=make(h)].second.insert(i);
		}
		else if(op==2)
		{
			int i;cin>>i;i--;
			cout<<S[itoS[i]].first<<"\n";
		}
		else
		{
			int l,r;cin>>l>>r;
			r++;
			int mid=l+(r-l)/2;
			auto mg=[](int x,int y)
			{
				if(S[x].second.size()>=S[y].second.size())
				{
					for(int id:S[y].second)
					{
						S[x].second.insert(id);
						itoS[id]=x;
					}
					S[y].second.clear();
					return x;
				}
				else
				{
					for(int id:S[x].second)
					{
						S[y].second.insert(id);
						itoS[id]=y;
					}
					S[x].second.clear();
					S[y].first=S[x].first;
					return y;
				}
			};
			//[l,mid)->l-1,[mid,r)->r
			{
				int to=make(l-1);
				auto it=htoS.erase(htoS.find(l-1));
				while(it!=htoS.end()&&it->first<mid)
				{
					int si=it->second;
					it=htoS.erase(it);
					to=mg(to,si);
				}
				htoS[l-1]=to;
			}
			{
				int to=make(r);
				auto it=htoS.erase(htoS.find(r));
				while(it!=htoS.begin()&&(--it)->first>=mid)
				{
					int si=it->second;
					it=htoS.erase(it);
					to=mg(to,si);
				}
				htoS[r]=to;
			}
		}
	}
}
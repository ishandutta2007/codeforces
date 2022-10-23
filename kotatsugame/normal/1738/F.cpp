#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N;
int col[1000];
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		cin>>N;
		vector<pair<int,int> >di(N);
		for(int i=0;i<N;i++)
		{
			col[i]=-1;
			cin>>di[i].first;
			di[i].second=i;
		}
		sort(di.begin(),di.end());
		reverse(di.begin(),di.end());
		int color=1;
		for(pair<int,int>p:di)
		{
			int d=p.first;
			int u=p.second;
			if(col[u]!=-1)continue;
			bool pr=true;
			col[u]=color;
			for(int i=0;i<d;i++)
			{
				cout<<"? "<<u+1<<endl;
				int v;cin>>v;v--;
				if(col[v]==-1)col[v]=color;
				else
				{
					int c=col[v];
					for(int i=0;i<N;i++)if(col[i]==color)col[i]=c;
					pr=false;
					break;
				}
			}
			if(pr)color++;
		}
		cout<<"!";
		for(int i=0;i<N;i++)cout<<" "<<col[i];
		cout<<endl;
	}
}
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N;
char S[1000];
int id[26];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>N;
	for(int i=0;i<26;i++)id[i]=-1;
	for(int i=0;i<N;i++)
	{
		cout<<"? 2 1 "<<i+1<<endl;
		int ret;
		cin>>ret;
		vector<pair<int,char> >idx;
		for(int j=0;j<26;j++)if(id[j]!=-1)idx.push_back(make_pair(id[j],j+'a'));
		sort(idx.begin(),idx.end());
		int l=-1,r=idx.size();
		while(r-l>1)
		{
			int mid=(l+r)/2;
			cout<<"? 2 "<<idx[mid].first+1<<" "<<i+1<<endl;
			int ret;
			cin>>ret;
			if((int)(idx.size()-mid)==ret)l=mid;
			else r=mid;
		}
		if(l==-1)
		{
			cout<<"? 1 "<<i+1<<endl;
			cin>>S[i];
		}
		else S[i]=idx[l].second;
		id[S[i]-'a']=i;
	}
	cout<<"! ";
	for(int i=0;i<N;i++)cout<<S[i];
	cout<<endl;
}
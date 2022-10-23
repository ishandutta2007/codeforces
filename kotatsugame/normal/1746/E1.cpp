#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool ask(const vector<int>&A)
{
	cout<<"? "<<A.size();
	for(int a:A)cout<<" "<<a;
	cout<<endl;
	string r;
	cin>>r;
	return r=="YES";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N;cin>>N;
	vector<int>S(N);
	for(int i=1;i<=N;i++)S[i-1]=i;
	while(S.size()>=4)
	{
		vector<int>V[4];
		for(int i=0;i<S.size();i++)V[i%4].push_back(S[i]);
		vector<int>AB=V[0],AC=V[0];
		for(int v:V[1])AB.push_back(v);
		for(int v:V[2])AC.push_back(v);
		int t=0;
		if(ask(AB))t|=2;
		if(ask(AC))t|=1;
		int d;
		if(t==0b11)d=3;
		else if(t==0b10)d=2;
		else if(t==0b01)d=1;
		else d=0;
		S.clear();
		for(int i=0;i<4;i++)if(i!=d)for(int v:V[i])S.push_back(v);
	}
	if(S.size()==3)
	{
		int x=S[0],y=S[1],z=S[2];
		int t=0;
		if(ask({x}))t|=1<<4;
		if(ask({x}))t|=1<<3;
		if((t>>4&1)==(t>>3&1))
		{
			if(t>>4&1)S={x};
			else S={y,z};
		}
		else
		{
			if(ask({y}))t|=1<<2;
			if((t>>2)==0b101)S={y,z};
			else if((t>>2)==0b011)S={x,y};
			else if((t>>2)==0b010)S={x,z};
			else
			{
				if(ask({y}))t|=1<<1;
				if((t>>1)==0b1000)S={x,z};
				else
				{
					if(ask({z}))t|=1<<0;
					if(t==0b10010)S={x,y};
					else S={x,z};
				}
			}
		}
	}
	for(int v:S)
	{
		cout<<"! "<<v<<endl;
		string r;cin>>r;
		if(r==":)")break;
	}
}
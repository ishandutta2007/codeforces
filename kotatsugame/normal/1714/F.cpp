#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int N,d12,d23,d31;
void path(int a,int b,int len,int&v)
{
	vector<int>now;
	now.reserve(len+1);
	now.push_back(a);
	for(int i=1;i<len;i++)now.push_back(v++);
	now.push_back(b);
	for(int i=0;i<len;i++)cout<<now[i]<<" "<<now[i+1]<<"\n";
}
bool disp(int a,int b,int c,int dab,int dbc,int dac)
{
	int mid=dab+dbc-dac;
	if(mid<0||mid%2!=0)return false;
	mid/=2;
	int X=dab-mid;
	int Y=dbc-mid;
	int Z=mid;
	if(X<=0||Y<=0||X+Y+Z+1>N)return false;
	cout<<"YES\n";
	int v;
	if(mid==0)
	{
		v=4;
		path(b,a,X,v);
		path(b,c,Y,v);
	}
	else
	{
		v=5;
		path(4,a,X,v);
		path(4,b,Z,v);
		path(4,c,Y,v);
	}
	while(v<=N)
	{
		cout<<"1 "<<v<<"\n";
		v++;
	}
	return true;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		cin>>N>>d12>>d23>>d31;
		if(disp(1,2,3,d12,d23,d31));
		else if(disp(1,3,2,d31,d23,d12));
		else if(disp(2,1,3,d12,d31,d23));
		else cout<<"NO\n";
	}
}
#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <string.h>
#include <stack>
#define Endl endl
#define mp make_pair
#define rep(N) for(int i=0;i<N;i++)
#define repj(N) for(int j=0;j<N;j++)
#define ll long long 
#define pii pair<int,int>
#define For(I,N) for(int I=0;I<N;I++)
#define cinone(N) int N;cin>>N;
#define scanfone(N) int N;cin>>N;
#define cingroup(N,M) int N[M];for(int yiuytvnm=0;yiuytvnm<M;yiuytvnm++) cin>>N[yiuytvnm];
#define scanfgroup(N,M) int N[M];for(int qrwuoiq=0;qrwuoiq<M;qrwuoiq++) scanf("%d",&N[qrwuoiq]);
typedef unsigned long long ull;
using namespace std;
string c0="What are you doing at the end of the world? Are you busy? Will you save us?";
string l="What are you doing while sending \"";
string m="\"? Are you busy? Will you send \"";
string r="\"?";
ull cal[100005];

ull ksm(int x)
{
	if(x<0) return -1;
	ull ans=1;
	ull m=2;
	while(x>0)
	{
		if(x%2) ans*=m;
		x>>=1;
		m=m*m;
	}
	return ans;
}

//ull lenof(int x)
//{
//	if(x<0) return 0;
//	if(x==0) return c0.size();else return 1LL*c0.size()*ksm(x)+1LL*(1LL*l.size()+m.size()+r.size())*ksm(x-1);
//}

ull lenof(int x)
{
	if(x<0) return 0;
	if(x==0) return 75;
	if(cal[x]) return cal[x];
	return cal[x]=(l.size()+m.size()+1LL*r.size()+1LL*2*lenof(x-1));
}

pair<int,ull> dire(int n,ull k)//-1 out,1 left,2 fn-1(left),3 mid,4 fn-1(right),5 right
{
	ull prev=lenof(n-1);
//	cout<<"kjslaf"<<lenof(0)<<endl;
	if(k<l.size()) return mp(1,k);
	ull s=l.size()+prev;
	if(k<s) return mp(2,k-l.size());
	if(k<s+m.size()) return(mp(3,k-s));
	s+=m.size();
//	cout<<"\nnow:"<<s<<'\n';
	if(k<s+prev) return(mp(4,k-s));
	s+=prev;
	if(k<s+r.size()) return(mp(5,k-s));
	return mp(-1,-1);
}

char find(int n,ull k)
{
	if(n==0)
	{
		if(k>=c0.size()) return '.';else return c0[k];
	}
	pair<int,ull> p=dire(n,k);
	if(p.first==-1) return '.';
	if(p.first==1) return l[p.second];
	if(p.first==2) return find(n-1,p.second);
	if(p.first==3) return m[p.second];
	if(p.first==4) return find(n-1,p.second);
	if(p.first==5) return r[p.second];
	cout<<"Error\n";
}

int main()
{
//	freopen("input.txt","r",stdin);
	int q;
	cin>>q;
	string c="";
	while(q--)
	{
		int n;
		ull k;
		cin>>n>>k;
		k--;
		c+=find(n,k);
	}
	cout<<c;
	return 0;
}
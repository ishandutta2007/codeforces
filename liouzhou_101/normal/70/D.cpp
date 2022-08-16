#include<cstdio>
#include<iostream>
#include<map>

using namespace std;

map<int,int> A,B;

long long det(long long x1,long long y1,long long x2,long long y2,long long x3,long long y3)
{
	return x1*y2-x2*y1+x2*y3-x3*y2+x3*y1-x1*y3;
}

bool check(map<int,int> &A,int x,int y)
{
	map<int,int>::iterator it=A.lower_bound(x);
	if (it==A.end()) return false;
	if (it->first==x)
		return it->second>=y;
	if (it==A.begin()) return false;
	map<int,int>::iterator itp=it--;
	return det(it->first,it->second,x,y,itp->first,itp->second)>=0;
}

void add(map<int,int> &A,int x,int y)
{
	if (check(A,x,y)) return;
	A[x]=y;
	map<int,int>::iterator it,ita,itb;
	it=A.find(x);
	ita=it++;
	while (it!=A.end())
	{
		itb=it++;
		if (it==A.end()) break;
		if (det(ita->first,ita->second,itb->first,itb->second,it->first,it->second)<0) break;
		A.erase(itb);
	}
	while (1)
	{
		it=ita;
		if (it==A.begin()) break;
		ita=it--;
		if (it==A.begin()) break;
		itb=it--;
		if (det(ita->first,ita->second,itb->first,itb->second,it->first,it->second)>0) break;
		A.erase(itb);
	}
}

void add(int x,int y)
{
	add(A,x,y);
	add(B,x,-y);
}

void query(int x,int y)
{
	puts((check(A,x,y)&&check(B,x,-y))?"YES":"NO");
}

int main()
{
	int T;
	cin>>T;
	while (T--)
	{
		int t,x,y;
		scanf("%d%d%d",&t,&x,&y);
		if (t==1)
			add(x,y);
		else
			query(x,y);
	}
	return 0;
}
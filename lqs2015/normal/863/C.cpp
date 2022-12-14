#include<iostream>
using namespace std;
long long k,p,q,o,t,a[5][5],j,pp[5][5],qq[5][5];
pair<long long,long long> tt[55],jj;
void add(long long oo,long long tt)
{
	if (oo==1)
	{
		if (tt==2) t++;
		else if (tt==3) o++;
	}
	else if (oo==2)
	{
		if (tt==1) o++;
		else if (tt==3) t++;
	}
	else
	{
		if (tt==1) t++;
		else if (tt==2) o++;
	}
}
int main()
{
	cin>>k>>p>>q;
	for (int i=1;i<=3;i++)
	{
		for (int h=1;h<=3;h++)
		cin>>pp[i][h];
	}
	for (int i=1;i<=3;i++)
	{
		for (int h=1;h<=3;h++)
		cin>>qq[i][h];
	}
	for (long long i=1;i<=k;i++)
	{
		if (a[p][q]) 
		{
			j=i-a[p][q];
			jj=make_pair(o-tt[a[p][q]].first,t-tt[a[p][q]].second);
			k-=(i-1);
			break;
		}
		a[p][q]=i;
		tt[i]=make_pair(o,t);
		add(p,q);
		int pop=pp[p][q],qoq=qq[p][q];
		p=pop;
		q=qoq;
	}
	if (!j) 
	{
		cout<<o<<" "<<t<<endl;
		return 0;
	}
	o+=(k/j)*jj.first;
	t+=(k/j)*jj.second;
	k=k%j;
	o+=(tt[a[p][q]+k].first-tt[a[p][q]].first);
	t+=(tt[a[p][q]+k].second-tt[a[p][q]].second);
	cout<<o<<" "<<t<<endl;
	return 0;
}
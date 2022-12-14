#include<iostream>
#include<string>
using namespace std;
int n,m,k,t,tt;
string ms,ks;
pair<int,int> a[1111111];
char c,d;
int rn,rp;
void check(char a,char b)
{
	if (a=='P' && b=='S') rn++;
	else if(a=='P' && b=='R') rp++;
	if (a=='R' && b=='S') rp++;
	else if (a=='R' && b=='P') rn++;
	if (a=='S' && b=='R') rn++;
	else if (a=='S' && b=='P') rp++;
}
int main()
{
	cin>>n;
	cin>>ms>>ks;
	m=ms.size();
	k=ks.size();
	t=m*k;
	for (int i=0;i<t;i++)
	{
		c=ms[i%m];
		d=ks[i%k];
		if (c!=d) check(c,d);
		a[i]=make_pair(rn,rp);
	}
	tt=n%t;
	rn=(n/t)*rn+a[tt-1].first;
	rp=(n/t)*rp+a[tt-1].second;
	cout<<rn<<" "<<rp<<endl;
	return 0;
}
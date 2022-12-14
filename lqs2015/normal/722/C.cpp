#include<iostream>
#include<map> 
#include<set>
using namespace std;
map<int,int> all;
multiset<long long> s;
long long seq[111111],a,n;
int main()
{
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a;
		seq[i]=seq[i-1]+a;
	}
	all[0]=n;
	s.insert(-seq[n]);
	for (int i=1;i<=n;i++)
	{
		cin>>a;
		map<int,int>::iterator it=all.lower_bound(a);
		it--;
		int lef=it->first,righ=it->second;
		s.erase(s.find(seq[lef]-seq[righ]));
		all.erase(it);
		if (lef+1<a)
		{
			s.insert(seq[lef]-seq[a-1]);
			all[lef]=a-1; 
		} 
		if (a<righ)
		{
			s.insert(seq[a]-seq[righ]);
			all[a]=righ; 
		}
		if (i==n) cout<<0<<endl;
		else cout<<-*s.begin()<<endl;
	} 
	return 0;
}
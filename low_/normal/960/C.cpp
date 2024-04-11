#include<iostream>
#include<fstream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;
#define int long long
#define mod 1000000007
#define inf 9223372036854775799
#define mn 100005

vector <int> nes={1};

int CNP(int u, int l, int r)
{
	if (u<nes[l]) return l-1;
	if (u>=nes[r]) return r;
	
	int m=(l+r)/2;
	
	if (u>nes[m]) return CNP(u, m+1, r);
	else return CNP(u, l, m);
}

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t=1;
	while (t<=1000000000)
	{
		t=t*2+1;
		nes.push_back(t);
//		cout<<t<<" ";
	}
//	cout<<"\n";
	
	int X, d;
	cin>>X>>d;
	
	d++;
	
	vector <int> ans;
	int temp=1;
	while (X>0)
	{
		int c=CNP(X, 0, nes.size()-1);
	//	cout<<c<<"\n";
		for (int i=0; i<=c; i++) ans.push_back(temp);
		temp+=d;
		X-=nes[c];
	}
	
	cout<<ans.size()<<"\n";
	for (int i=0; i<ans.size(); i++) cout<<ans[i]<<" ";
}
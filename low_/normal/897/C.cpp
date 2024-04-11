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

string F0="What are you doing at the end of the world? Are you busy? Will you save us?";
string Fs="What are you doing while sending \"", Fm="\"? Are you busy? Will you send \"", Fe="\"?";

int L[100005];

char backtrack(int n, int i)
{
	if (n==0) 
	{
		if (i>=F0.size()) return '.';
		else return F0[i];
	}
	
	if (i<Fs.size()) return Fs[i];
	else if (i<Fs.size()+L[n-1]) return backtrack(n-1, i-Fs.size());
	else if (i<Fs.size()+L[n-1]+Fm.size()) return Fm[i-Fs.size()-L[n-1]];
	else if (i<Fs.size()+L[n-1]+Fm.size()+L[n-1]) return backtrack(n-1, i-Fs.size()-L[n-1]-Fm.size());
	else if (i<L[n]) return Fe[i-(Fs.size()+L[n-1]+Fm.size()+L[n-1])];
	else return '.';
}

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	L[0]=F0.length();
	for (int i=1; i<100005; i++) L[i]=min(Fs.size()+L[i-1]+Fm.size()+L[i-1]+Fe.size(), (int)1000000000000000010);
	
	int q, i, n;
	cin>>q;
//	for (int i=0; i<100005; i++) cout<<i<<" "<<L[i]<<"\n";
	while (q>0)
	{
		q--;
		cin>>n>>i;
		cout<<backtrack(n, i-1);
	}
}
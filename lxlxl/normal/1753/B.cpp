#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn = 510000;

int n,X;

int num[maxn];

int main()
{
	ios_base::sync_with_stdio(false);
	
	cin>>n>>X;
	for(int i=1;i<=n;i++)
	{
		int c; cin>>c;
		num[c]++;
	}
	
	int ok=1;
	for(int i=1;i<X;i++)
	{
		num[i+1]+= num[i]/(i+1);
		num[i]%=i+1;
		
		if(num[i]!=0) ok=0;
	}
	
	if(ok) cout<<"Yes\n";
	else cout<<"No\n";
	
	return 0;
}
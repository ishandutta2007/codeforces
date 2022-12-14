#include <bits/stdc++.h>
using namespace std;
bool judge(long long int n)
{
	bool two = true;
	while(n)
	{
		if(n==1) break;
		else if(n%2==0 && n!=1)
		{
			n/=2;
		}else{
			two = false;
			break;
		}
	}
	return two;
}
int find(long long int n)
{
	long long int a = 1;
	while(a<=n)
	{
		a *= 2;
	}
	long long int b = a/2;
	long long int c = abs(n-a);
	long long int d = abs(n-b);
	if(c>d) return b;
	else return a;
	
}
int main()
{
	int t; cin>>t;
	while(t--)
	{
		int n; cin>>n;
		long long int a[n+2]={0};
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			if(judge(a[i])) continue;
			else{
				long long int e = find(a[i]);
				if(e<1e9) a[i] = e;
				else{
					while(e>1e9)
						e /= 2;
					a[i] = e;
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			cout<<a[i]<<" ";
		}
		cout<<endl;
	}
 }
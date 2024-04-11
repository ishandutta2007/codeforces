#include <stdio.h>
#include<iostream>
#include <string>
#include <string.h>
#include <vector>
#include <set>
#include <memory.h>
#include <algorithm>
#include <math.h>
#include <queue>
using namespace std;
#define fin for (i=0; i<n; i++)
typedef long long li;
typedef long double ld;
#define mp make_pair
#define pb push_back
typedef pair <int, int> pi;
typedef vector <int> vi;
const li p=1000000007;
const ld PI=3.14159265358979323846264338327950288419716939937510;
void prepare ()
{
#ifdef _DEBUG
	freopen ("in.txt", "r", stdin);
#endif
}


int main ()
{
	prepare ();
	int n;
	cin>>n;
	int i;
	if (n==1)
	{
		cout<<"1";
		return 0;
	}
	int k=n;
	cout<<n<<" ";
	for (i=2; i<=k; i++)
	{
		while (n%i==0)
		{
			cout<<(n/i)<<" ";
			n/=i;
		}
	}
	return 0;
}
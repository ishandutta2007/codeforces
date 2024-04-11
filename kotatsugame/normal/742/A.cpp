#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<string>
#include<sstream>
#include<iomanip>
#include<utility>
#include<cmath>
#include<set>
#include<list>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<cstring>
using namespace std;
typedef long long int ll;
int main()
{
	int n;
	cin>>n;
	if(n==0)
	{
		cout<<1<<endl;
		return 0;
	}
	n--;
	n%=4;
	int a=8;
	for(int i=0;i<n;i++)a*=8;
	cout<<a%10<<endl;
	return 0;
}
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
#include<cstring>
using namespace std;
typedef long long int ll;
int main()
{
	ll n,k;cin>>n>>k;
	int i=1;
	while(!(k&1))
	{
		k>>=1;
		i++;
	}
	cout<<i<<endl;
	return 0;
}
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
	int n,a,b;cin>>n>>a>>b;
	string s;cin>>s;
	a--;b--;
	cout<<(s[a]==s[b]?0:1)<<endl;
	return 0;
}
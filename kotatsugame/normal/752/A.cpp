#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<vector>
#include<queue>
#include<list>
#include<stack>
#include<map>
#include<utility>
#include<iomanip>

#define fi first
#define se second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long int ll;
typedef pair<int,int> P;

int main()
{
	int n,m,k;cin>>n>>m>>k;
	char c;int a,b;
	if(k%2==0)k--,c='R';
	else c='L';
	k/=2;
	b=k%m+1;
	a=k/m+1;
	cout<<a<<" "<<b<<" "<<c<<endl;
	return 0;
}
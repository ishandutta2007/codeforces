#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn = 1e6 + 10;
int n,m,k,bk[maxn],le[maxn],res;
int main()
{
	cin>>n>>m>>k;
	for (int i=1;i<=n;i++)cin>>bk[i];
	for (int i=1;i<n;i++)le[i] = bk[i + 1] - bk[i] - 1;
	sort(le + 1,le + n,[](int i,int j){return i > j;});
	for (int i=1;i<k;i++) res += le[i];
	cout << bk[n] - bk[1] + 1 - res << endl;
}
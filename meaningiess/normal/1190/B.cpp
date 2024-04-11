#include<bits/stdc++.h>
#define ll long long
#define N 100010
using namespace std;
int a[N];map<int,int> h;
int main()
{
	int n,i,t1=0,mrk=0,p;ll s=0,s1=0;cin>>n;
	for (i=1;i<=n;i++) cin>>a[i],h[a[i]]++;
	sort(a+1,a+n+1);a[0]=-1;
	for (i=1;i<n;i++) if (a[i]==a[i+1]) t1++,p=i;
	if (t1>1) {puts("cslnb");exit(0);}
	if (t1){if (a[p]==a[p-1]+1){puts("cslnb");exit(0);}}
	for (i=1;i<=n;i++) s+=a[i],s1+=i-1; if ((s-s1)%2==0) {puts("cslnb");}else puts("sjfnb");
}
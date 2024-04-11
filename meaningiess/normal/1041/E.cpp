#include<iostream>
using namespace std;
int a[1010],ans[1010];
int main()
{
	int n,i,cur=0,x,y,l1=1,l2=1;cin>>n;
	for (i=1;i<n;i++)
	{
		cin>>x>>y;if (x>y) swap(x,y);a[x]++;
		if (y!=n) {cout<<"NO";return 0;}
	}
	for (i=1;i<n;i++){cur+=a[i];if (cur>i) {cout<<"NO";return 0;}}
	cout<<"YES"<<endl;ans[1]=n;
	for (i=n-1;i;i--)
	{
		if (!a[i]) {while (ans[l2]) l2++;ans[l2]=i;continue;}
		l1+=a[i];ans[l1]=i;
	}
	for (i=1;i<n;i++) cout<<ans[i]<<' '<<ans[i+1]<<endl;
}
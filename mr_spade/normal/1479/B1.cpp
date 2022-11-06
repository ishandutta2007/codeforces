#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,ans;
int a[N];
vector<int> V,C,B,E;
signed main()
{
	int lst,lst1=0,lst2=0;
	register int i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	lst=1;
	for(i=2;i<=n;i++)
		if(a[i]!=a[i-1])
			V.push_back(a[i-1]),C.push_back(i-lst),B.push_back(lst),E.push_back(i-1),lst=i;
	V.push_back(a[n]);C.push_back(n-lst+1);B.push_back(lst),E.push_back(n);
	lst=-1;
	for(i=0;i<(int)V.size();i++)
		if(C[i]>1)
		{
			if(lst==-1)
				ans+=B[i]+1,lst=i;
			else
			{
				if(V[lst]==V[i])
				{
					for(j=E[lst]+1;j<=B[i]-2;j++)
						if(a[j]!=V[i]&&a[j+1]!=V[i])
						{
							ans+=B[i]-E[lst]+1;
							goto end;
						}
					ans+=B[i]-E[lst];
					end:;
				}
				else
					ans+=B[i]-E[lst]+1;
				lst=i;
			}
		}
	if(lst==-1)
		ans+=n;
	else
		ans+=n-E[lst];
	printf("%d\n",ans);
	return 0;
}
#include<iostream>
using namespace std;
void dfs(int n,int i)
{
	if (!n) return;int a=n-(n/2),b=n-(n/3);
	if (a==b) {for (int j=1;j<=a;j++) printf("%d ",i);dfs(n/3,i*3);}
	else {for (int j=1;j<=a;j++) printf("%d ",i);dfs(n/2,i*2);}
}
int main()
{
	int n,i;cin>>n;dfs(n,1);
}
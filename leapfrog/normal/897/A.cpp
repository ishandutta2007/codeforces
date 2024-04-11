//
//  
//
//
//  
//  
//   
//
//
#include<bits/stdc++.h>
using namespace std;
int n,m;char c[10005];
int main()
{
	scanf("%d%d%s",&n,&m,c+1);char o,x;
	for(int i=1,l,r;i<=m;i++) {scanf("%d%d",&l,&r),cin>>o>>x;for(int i=l;i<=r;i++) if(c[i]==o) c[i]=x;}
	return printf("%s\n",c+1),0;
}
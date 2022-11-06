#include<bits/stdc++.h>
#define re register
std::string s1[110],s2[110];
int main()
{
	re int n,m,q,w;
	scanf("%d%d",&n,&m);
	for(re int i=1;i<=n;i++)std::cin>>s1[i];
	for(re int i=1;i<=m;i++)std::cin>>s2[i];
	scanf("%d",&q);
	for(;q--;)
	{
		scanf("%d",&w);
		std::cout<<s1[(w-1)%n+1]+s2[(w-1)%m+1]<<std::endl;
	}
}
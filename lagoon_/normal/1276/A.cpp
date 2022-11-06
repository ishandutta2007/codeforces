#include<bits/stdc++.h>
using namespace std; 
#define re register
int f[10],g[10];
char ss[200100];
vector<int>pp;
int main()
{
	re int n,t;
	scanf("%d",&t);
	for(;t--;)
	{
		scanf("%s",ss+1);
		n=strlen(ss+1);
		pp.clear();
		for(re int i=1;i+2<=n;i++)
		{
			if(ss[i]=='o'&&ss[i+1]=='n'&&ss[i+2]=='e')pp.push_back(i+1),i+=1;
			else if(ss[i]=='t'&&ss[i+1]=='w'&&ss[i+2]=='o')if(i+3<=n&&ss[i+3]=='n')pp.push_back(i+2),i+=2;
			else pp.push_back(i+1),i+=1;
		}
		printf("%d\n",pp.size());
		for(re int i=0;i<pp.size();i++)printf("%d ",pp[i]);puts("");
	}
}
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;

int a[25][25],c[25][25];
bool ans;
int n,m;

void init()
{
  scanf("%d%d",&n,&m);
  for(int i=1;i<=n;i++)
  	 for(int j=1;j<=m;j++)
  		scanf("%d",&c[i][j]);
}

void print()
{
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)printf("%d ",a[i][j]);
    printf("\n");
  }  
}

bool pd()
{
  int ma=0;
  int b[25][25];  
  //print();
  memset(b,0,sizeof(b));
  for(int i=1;i<=n;i++)
  {
    ma=0;
    for(int j=1;j<=m;j++)if(a[i][j]!=j)ma++;
    if(ma>4)return false;
    a[i][0]=ma;ma=0;
    int k;
    for(int j=1;j<=m;j++)
      while(a[i][k=j]!=k && b[i][k]==0){ma++;b[i][k]=1;k=a[i][k];}
    if(ma>2 || ma<a[i][0])return false;
  }
  return true;
}

int main() 
{
	init();
	ans=false;
	for(int p=1;p<=m;p++)
	  for(int q=1;q<=m;q++)
	  {
	    for(int i=1;i<=n;i++)
	    {
	      for(int j=1;j<=m;j++)a[i][j]=c[i][j];
	      a[i][p]=c[i][q];
	      a[i][q]=c[i][p];
	    }
	    ans=ans | pd();
	  }
	if(ans)printf("YES");else printf("NO");
	return 0;
}
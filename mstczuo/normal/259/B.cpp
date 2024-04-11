# include <iostream>
# include <cstdio>
using namespace std;

int a[3][3],s,t;

int main()
{
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			scanf("%d",&a[i][j]),
			s+=a[i][j];
	s=s>>1;
	for(int i=0;i<3;i++){
		t=s;
		for(int j=0;j<3;j++)
			t-=a[i][j];
		a[i][i]=t;
	}
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++)
			printf("%d ",a[i][j]);
		printf("\n");
	}
}
#include<cstdio>
using namespace std;
int T,N;
char B[1<<17];
char A[1<<17];
main(){
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%s",&N,B);
		int p=0;
		for(int i=0;i<N;i++)
		{
			if(p==0)
			{
				A[i]='1';
			}
			else if(p==1)
			{
				if(B[i]=='1')A[i]='1';
				else A[i]='0';
			}
			else
			{
				if(B[i]=='1')A[i]='0';
				else A[i]='1';
			}
			p=B[i]+A[i]-'0'-'0';
			putchar(A[i]);
		}
		putchar(10);
	}
}
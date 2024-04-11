#include<algorithm>
#include<iostream>
using namespace std;
int N,A[1000];
main()
{
	cin>>N;
	for(int i=0;i<N;i++)cin>>A[i];
	sort(A,A+N);
	int L=0,R=N-1;
	for(int i=0;i<N;i++)
	{
		if(i%2==0)printf("%d",A[L++]);
		else printf("%d",A[R--]);
		printf("%c",i+1==N?10:32);
	}
}
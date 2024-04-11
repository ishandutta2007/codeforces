#include <stdio.h>

int N,A,B,K;
char S[200050];

int main()
{
	scanf ("%d %d %d %d %s",&N,&A,&B,&K,S);
	
	int cnt = 0, get = 0;
	for (int i=0;i<N;i++){
		if (S[i] == '0') cnt++;
		else cnt = 0;

		if (cnt == B){
			get++;
			cnt = 0;
		}
	}

	printf ("%d\n",get-A+1);

	cnt = 0, get = get-A+1;
	for (int i=0;i<N;i++){
		if (S[i] == '0') cnt++;
		else cnt = 0;

		if (cnt == B){
			printf ("%d ",i+1);
			if (--get == 0) break;
			cnt = 0;
		}
	}

	return 0;
}
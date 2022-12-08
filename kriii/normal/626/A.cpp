#include <stdio.h>

char S[202];
int sx[202],sy[202];

int main()
{
	int n;
	scanf ("%d%s",&n,S+1);
	for (int i=1;S[i];i++){
		if (S[i] == 'L') sx[i] = 1;
		if (S[i] == 'R') sx[i] = -1;
		if (S[i] == 'D') sy[i] = 1;
		if (S[i] == 'U') sy[i] = -1;
		sx[i] += sx[i-1];
		sy[i] += sy[i-1];
	}

	int cnt = 0;
	for (int i=0;i<n;i++) for (int j=i+1;j<=n;j++) if (sx[i] == sx[j] && sy[i] == sy[j]){
		cnt++;
	}
	printf ("%d\n",cnt);

	return 0;
}
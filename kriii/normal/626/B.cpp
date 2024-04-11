#include <stdio.h>

bool chk[202][202][202];

void go(int r, int g, int b)
{
	if (chk[r][g][b]) return;
	chk[r][g][b] = 1;
	if (r && g) go(r-1,g-1,b+1);
	if (g && b) go(r+1,g-1,b-1);
	if (r && b) go(r-1,g+1,b-1);
	if (r >= 2) go(r-1,g,b);
	if (g >= 2) go(r,g-1,b);
	if (b >= 2) go(r,g,b-1);
}

int main()
{
	int n; char S[202];
	scanf ("%d%s",&n,S);
	int r=0,g=0,b=0;
	for (int i=0;i<n;i++){
		if (S[i] == 'R') r++;
		if (S[i] == 'G') g++;
		if (S[i] == 'B') b++;
	}
	go(r,g,b);
	
	if (chk[0][0][1]) printf ("B");
	if (chk[0][1][0]) printf ("G");
	if (chk[1][0][0]) printf ("R");

	return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define N 500005
int s[N],x[N],y[N];
int X,Y,n,i,j,k,now;
int main()
{
	scanf("%d",&n);
	scanf("%d%d\n",&X,&Y);
	for(i = 1; i <= n; i ++)
		scanf("%c %d%d\n",&s[i],&x[i],&y[i]);
	s[0] = ' ';
	now = 2e9, k = 0;
	for(int i = 1; i <= n; i ++)
		if(x[i] == X && y[i] > Y)
			if(y[i] < now)now = y[i], k = i;
	if(s[k] == 'R' || s[k] == 'Q') {puts("YES");return 0;}
	now = -2e9, k = 0;
	for(int i = 1; i <= n; i ++)
		if(x[i] == X && y[i] < Y)
			if(y[i] > now) now = y[i], k = i;
	if(s[k] == 'R' || s[k] == 'Q') {puts("YES");return 0;}
	now = -2e9, k = 0;
	for(int i = 1; i <= n; i ++)
		if(y[i] == Y && x[i] < X)
			if(x[i] > now) now = x[i], k = i;
	if(s[k] == 'R' || s[k] == 'Q') {puts("YES");return 0;}
	now = 2e9, k = 0;
	for(int i = 1; i <= n; i ++)
		if(y[i] == Y && x[i] > X)
			if(x[i] < now) now = x[i], k = i;
	if(s[k] == 'R' || s[k] == 'Q') {puts("YES");return 0;}
	
	now = 2e9, k = 0;
	for(i = 1; i <= n; i ++)
		if(abs(x[i] - X) == abs(y[i] - Y) && y[i] > Y)
			if(y[i] < now) now = y[i], k = i;
	if(s[k] == 'B' || s[k] == 'Q') {puts("YES"); return 0;}
	now = -2e9, k = 0;
	for(i = 1; i <= n; i ++)
		if(abs(x[i] - X) == abs(y[i] - Y) && y[i] < Y)
			if(y[i] > now) now = y[i], k = i;
	if(s[k] == 'B' || s[k] == 'Q') {puts("YES");return 0;}
	puts("NO");
	return 0;
}
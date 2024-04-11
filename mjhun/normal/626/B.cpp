#include <bits/stdc++.h>
using namespace std;

int a,b,c;
int n;
char s[205];
bool vis[205][205][205];

void go(int a, int b, int c){
	if(vis[a][b][c])return;
	vis[a][b][c]=true;
	if(a>1)go(a-1,b,c);
	if(b>1)go(a,b-1,c);
	if(c>1)go(a,b,c-1);
	if(a&&b)go(a-1,b-1,c+1);
	if(a&&c)go(a-1,b+1,c-1);
	if(b&&c)go(a+1,b-1,c-1);
}

int main(){
	scanf("%d%s",&n,s);
	for(int i=0;i<n;++i){
		if(s[i]=='B')a++;
		if(s[i]=='G')b++;
		if(s[i]=='R')c++;
	}
	go(a,b,c);
	if(vis[1][0][0])putchar('B');
	if(vis[0][1][0])putchar('G');
	if(vis[0][0][1])putchar('R');
	puts("");
	return 0;
}
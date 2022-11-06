#include<bits/stdc++.h>
using namespace std;

char c[300010], c2[300010];
int f[300010];

int main()
{
	scanf("%s", c + 1); 
	int n = strlen(c + 1), cnt = 0, m = 0;
	for(int i=1; i<=n; ++i)
	{
		if(i == 1 || c[i] != c[i-1])
		{
			f[m] = cnt;
			c2[++m] = c[i];
			cnt = 1;
		}
		else ++cnt;
	}
	f[m] = cnt;
	/*
	for(int i=1; i<=m; ++i) cout << c2[i] ;
	cout << "\n";
	for(int i=1; i<=m; ++i) cout << f[i] << " ";
	*/
	for(int i=1; i<=m; ++i)
		if(c2[i] != c2[m-i+1]) return printf("0"), 0;
	for(int i=1; i<=m/2; ++i)
		if(f[i] + f[m+1-i] < 3)  return printf("0"), 0;
	
	
	
	if(f[m/2+1] >= 2)
		cout << f[m/2+1] + 1;
	else cout << 0;
}
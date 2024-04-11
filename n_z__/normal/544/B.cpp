#include <bits/stdc++.h>
using namespace std;
int main() 
{
    int n,k;
    cin>>n>>k;
    if(k>ceil(n*n/2.0))return puts("NO"),0;
    puts("YES");
    int ans=0;
	for(int x=1;x<=n;x++,puts("")) 
	for(int y=1;y<=n;y++) 
	if(ans<k&&!((x+y)%2))putchar('L'),ans++;
	else putchar('S');
}
// 
//  
// 
//  
//   
#include<bits/stdc++.h>
using namespace std;
int n;char c[10005];
inline char chk(int x)
{
	if(x/1000!=4&&x/1000!=7&&x/1000!=0) return 0;
	if(x/100%10!=4&&x/100%10!=7&&x/100%10!=0) return 0;
	if(x/10%10!=4&&x/10%10!=7&&x/10%10!=0) return 0;
	if(x%10!=4&&x%10!=7&&x%10!=0) return 0;
	return 1;
}
int main()
{
	scanf("%d",&n),memset(c,0,sizeof(c));
	for(int i=1;i<=n;i++) if(chk(i)&&!c[i]) for(int j=i;j<=n;j+=i) c[j]=1;
	if(c[n]) return puts("YES"),0;else return puts("NO"),0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2005;
int n,m;
char s[1005][1005];
int b[1005][1005];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++) scanf("%s",s[i]);
    for(int i=1;i<n-1;i++)
    	for(int j=1;j<m-1;j++)
    	{
			int flag=0;
    		for(int k=-1;k<=1;k++)
    			for(int l=-1;l<=1;l++)
    				if(s[i+k][j+l]=='.'&&(k||l)) {flag=1;break;}
    		
    		if(!flag)
    		{
    			for(int k=-1;k<=1;k++)
    				for(int l=-1;l<=1;l++)
    					if(k||l) b[i+k][j+l]=1;
			}
    	}
    for(int i=0;i<n;i++)
    	for(int j=0;j<m;j++)
    		if(s[i][j]=='#'&&(!b[i][j])) {
    			puts("NO");return 0;
			}
	puts("YES");
    return 0;
}
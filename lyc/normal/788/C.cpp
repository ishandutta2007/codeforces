#include<bits/stdc++.h>
using namespace std;
int t,n,p,l,r,a,f[1000000];
queue<int> q;
int main()
{
		scanf("%d%d",&p,&n);l=0,r=0;
        memset(f,0x3f,sizeof(f));
		for (int i=1;i<=n;i++) scanf("%d",&a),f[a-p+1000]=1;
		for(int i = 0; i <= 2000; i++)
	       if (f[i] == 1)
	         q.push(i);
		while (!q.empty())
		{
			l=q.front();
			q.pop();
			for (int i=1;i<=2000;i++) 
			  if (f[i]==1&&f[l+i-1000]==0x3f3f3f3f&&l+i-1000<=2000)
			    f[l+i-1000]=f[l]+1,q.push(l+i-1000);
            if (q.empty()) break;
            //cout<<l<<endl;
	    }
	    if (f[1000]==0x3f3f3f3f) cout<<"-1"; else cout<<f[1000]<<endl;
}
/*
1000 2
1000 1000
*/
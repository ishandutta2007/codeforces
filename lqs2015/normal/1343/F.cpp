#include<bits/stdc++.h>
using namespace std;
int n,test,num[222],ans[222],x,y,ps,pos[222],mn,mx;
vector<int> a[222];
bool flg,used[222],al[222];
int main()
{
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d",&n);
        for (int i=1;i<n;i++) a[i].clear();
        for (int i=1;i<n;i++)
        {
            scanf("%d",&x);
            for (int j=1;j<=x;j++)
            {
                scanf("%d",&y);
                a[i].push_back(y);
            }
        }
        for (int h=1;h<=n;h++)
        {
        	memset(num,0,sizeof(num));ans[1]=h;memset(used,0,sizeof(used));
        	for (int i=1;i<n;i++)
        	{
        		for (int j=0;j<a[i].size();j++)
        		{
        			num[a[i][j]]++;
				}
			}
			flg=0;
	       	for (int i=n;i>1;i--)
	        {
	        	ps=-1;
	            for (int j=1;j<=n;j++)
	            {
	                if (num[j]==1 && j!=h) 
	                {
	                    ps=j;
	                    break;
	                }
	            }
	            if (!~ps) 
	            {
	            	flg=1;
	            	break;
				}
	            ans[i]=ps;
	            for (int j=1;j<n;j++)
	            {
	                if (used[j]) continue;
	                for (int k=0;k<a[j].size();k++)
	                {
	                    if (a[j][k]==ps) 
	                    {
	                        used[j]=1;
	                        for (int h=0;h<a[j].size();h++) num[a[j][h]]--;
	                        break;
	                    }
	                }
	            }
	        }
	        if (flg) continue;
	        for (int i=1;i<=n;i++) pos[ans[i]]=i;
	        memset(al,0,sizeof(al));
	        for (int i=1;i<n;i++)
	        {
	        	mn=1e9;mx=0;
	        	for (int j=0;j<a[i].size();j++)
	        	{
	        		mn=min(mn,pos[a[i][j]]);
	        		mx=max(mx,pos[a[i][j]]);
				}
				if (mx-mn+1!=(int)a[i].size() || al[mx]) 
				{
					flg=1;
					break;
				}
				al[mx]=1;
			}
			if (!flg) break;
		}
        for (int i=1;i<=n;i++) printf("%d ",ans[i]);
        printf("\n");
    }
    return 0;
}
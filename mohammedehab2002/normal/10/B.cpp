#include <iostream>
using namespace std;
int abs(int q)
{
	return (q>0?q:q*-1);
}
int main()
{
	int n,k,a[200][200],s[200][200],used[200][200],x,y,i,j,num,t;
    cin >> n >> k;
    x=(k+1)/2;
	y=(k+1)/2;
    for (i=1;i<=k;i++)
    {
        for (j=1;j<=k;j++)
        a[i][j]=a[i][j-1]+abs(x-i)+abs(y-j);
    }
    for (t=1;t<=n;t++)
    {
        cin >> num;
        int best=1000000000,u=0,v=0;
        for (i=1;i<=k;i++)
        {
            for (j=1;j<=k-num+1;j++)
            {
                if (s[i][j+num-1]-s[i][j-1]==0 && a[i][j+num-1]-a[i][j-1]<best)
                {
                    best = a[i][j+num-1]-a[i][j-1];
					u=i;
					v=j;
				}
			}
		}
        if (best==1000000000) 
		cout << -1 << endl;
		else
        {
            cout << u << " " << v << " " << v+num-1 << endl;
            for (i=v;i<=v+num-1;i++)
            used[u][i] = 1;
            for (i=1;i<=k;i++)
            s[u][i]=s[u][i-1]+used[u][i];
        }
    }
    return 0;
}
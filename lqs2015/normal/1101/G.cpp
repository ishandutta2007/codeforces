#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
struct linear_base
{
    int a[66],mxlog;
    void Insert(int x)
    {
        for (int i=mxlog;i>=0;i--)
        {
            if (x&(1ll<<i))
            {
                if (!a[i]) 
                {
                    a[i]=x;
                    return;
                }
                else x^=a[i];
            }
        }
    }
    bool check(int x)
    {
        for (int i=mxlog;i>=0;i--)
        {
            if (x&(1ll<<i))
            {
                if (!a[i]) return 0;
                else x^=a[i];
            }
        }
        return 1;
    }
    void merge(const linear_base &b) 
    {
        for (int i=mxlog;i>=0;i--) 
        {
            if (b.a[i]) Insert(b.a[i]);
        }
    }
    int findmax()
    {
        int res=0;
        for (int i=mxlog;i>=0;i--) 
        {
            if ((res^a[i])>res) res^=a[i];
        }
        return res;
    }
    int findmin()
    {
        for (int i=0;i<=mxlog;i++)
        {
            if (a[i]) return a[i];
        }
    }
    int findkth(int k)
    {
        int tmp[66],cnt=0,res=0;
        for (int i=0;i<=mxlog;i++)
        {
            for (int j=i-1;j>=0;j--)
            {
                if (a[i]&(1ll<<j)) a[i]^=a[j];
            }
            if (a[i]) tmp[cnt++]=a[i];
        }
        for (int i=0;i<cnt;i++)
        {
            if (k&(1ll<<i)) res^=tmp[i];
        }
        return res;
    }
}l;
int n,a[222222],pre[222222],ans,cnt;
int main()
{
	srand(time(0));
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++) pre[i]=pre[i-1]^a[i];
	l.mxlog=30;
	if (!pre[n])
	{
		printf("-1\n");
		return 0;
	}
	for (int t=1;t<=1;t++)
	{
		random_shuffle(pre+1,pre+n);
		memset(l.a,0,sizeof(l.a));
		cnt=1;l.Insert(pre[n]); 
		for (int i=1;i<n;i++)
		{
			if (l.check(pre[i]) || !pre[i]) continue;
			l.Insert(pre[i]);
			cnt++;
		}
		ans=max(ans,cnt);
	}
	printf("%d\n",ans);
	return Accepted;
}
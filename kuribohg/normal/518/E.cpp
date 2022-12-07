#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=100010;
const int INF=2000000000;
int n,a[MAXN],b[MAXN],sub[MAXN],tot,k;
int getint()
{
    char c=getchar();
    int con=0,f=1;
    while(c!='-'&&c!='?'&&(c<'0'||c>'9')) c=getchar();
    if(c=='?') return INF;
    if(c=='-') f=-f;
    if(c=='-') c=getchar();
    while(c>='0'&&c<='9') con=con*10+c-'0',c=getchar();
    return con*f;
}
int main()
{
    n=getint(),k=getint();
    for(int i=1;i<=n;i++) a[i]=getint();
    for(int T=1;T<=k;T++)
    {
        tot=0;
        for(int i=T;i<=n;i+=k)
            b[++tot]=a[i],sub[tot]=i;
        int r=0;
        b[0]=-INF+1;
        b[++tot]=INF-1;
        while(r<tot)
        {
            int L=b[r],l=r;
            while(b[r+1]==INF&&r+1<=tot) r++;
            r++;
            int R=b[r];
            if(R<=0)
            {
                for(int i=r-1;i>l;i--)
                    b[i]=b[i+1]-1,a[sub[i]]=b[i];
            }
            else if(L>=0)
            {
                for(int i=l+1;i<r;i++)
                    b[i]=b[i-1]+1,a[sub[i]]=b[i];
            }
            else
            {
                int len=r-l-1;
                if(len!=0) b[l+1]=-(len/2),a[sub[l+1]]=b[l+1];
                for(int i=l+2;i<r;i++)
                    b[i]=b[i-1]+1,a[sub[i]]=b[i];
				if(b[r-1]>=b[r])
					for(int i=r-1;i>l;i--)
						b[i]=b[i+1]-1,a[sub[i]]=b[i];
				if(b[l+1]<=b[l])
					for(int i=l+1;i<r;i++)
						b[i]=b[i-1]+1,a[sub[i]]=b[i];
            }
        }
    }
    for(int i=1;i<=n-k;i++)
        if(a[i]>=a[i+k]) {puts("Incorrect sequence");return 0;}
    for(int i=1;i<n;i++)
        printf("%d ",a[i]);
    printf("%d\n",a[n]);
    return 0;
}
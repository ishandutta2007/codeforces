#include<bits/stdc++.h>
using namespace std;
//static char buf[1000000],*p1=buf,*p2=buf;
//#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++
#define pi pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define ls (rt<<1)
#define rs (rt<<1|1)
#define lowbit (x&-x)
const int maxn=1e5+5,M=34005;
inline int read()
{
	char ch=getchar();bool f=0;int x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1)x=-x;return x;
}
inline void print(int x)
{
    static int a[55];int top=0;
    if(x<0) putchar('-'),x=-x;
    do{a[top++]=x%10,x/=10;}while(x);
    while(top) putchar(a[--top]+48);
}
int n,m,l,r,vis[maxn];
struct node 
{
	int x,y,z,id;
}a[maxn],b[maxn];
bool cmp(node a,node b)
{
	return a.x<b.x;
}
bool cmp2(node a,node b)
{
	return a.y<b.y;
}

bool check(int d,int e,int f,int x)
{
	int l=0,r=0,t=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i].z==d)t++;
		if(t==x){l=a[i].x;break;}
	}//cout<<l<<" "<<x<<endl;
	if(t==x)
	{
		t=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i].z==e&&a[i].x>l)t++;
			if(t==x){r=a[i].x;break;}
		}
		if(t==x)
		{
			t=0;
			for(int i=1;i<=n;i++)
			{
				if(a[i].z==f&&a[i].x>r)t++;
				if(t==x){break;}
			}
		//	cout<<l<<" "<<r<<" "<<t<<endl;
			if(t==x)return 1;
		}
		//cout<<"A";
		t=0;
		for(int i=1;i<=n;i++)
		{
			if(b[i].z==e&&b[i].x>l)t++;
			if(t==x){r=b[i].y;break;}
		}
		if(t==x)
		{
			t=0;
			for(int i=1;i<=n;i++)
			{
				if(b[i].z==f&&b[i].x>l&&b[i].y>r)t++;
				if(t==x){break;}
			}
			if(t==x)return 1;
		}
	}
	
	
	
	t=0;
	for(int i=n;i>=1;i--)
	{
		if(a[i].z==d)t++;
		if(t==x){r=a[i].x;break;}
	}
	if(t==x)
	{
		t=0;
		for(int i=1;i<=n;i++)
		{
			if(b[i].z==e&&b[i].x<r)t++;
			if(t==x){l=b[i].y;break;}
		}
		if(t==x)
		{
			t=0;
			for(int i=1;i<=n;i++)
			{
				if(b[i].z==f&&b[i].x<r&&b[i].y>l)t++;
				if(t==x){break;}
			}
			if(t==x)return 1;
		}
	}
	
	
	
	
	
	
	
	
	//cout<<"A";
	t=0;
	for(int i=1;i<=n;i++)
	{
		if(b[i].z==d)t++;
		if(t==x){l=b[i].y;break;}
	}
	if(t==x)
	{
		t=0;
		for(int i=1;i<=n;i++)
		{
			if(b[i].z==e&&b[i].y>l)t++;
			if(t==x){r=b[i].y;break;}
		}
		//cout<<l<<" "<<r<<" "<<x<<" "<<d<<" "<<e<<" "<<f<<endl;
		if(t==x)
		{
			t=0;
			for(int i=1;i<=n;i++)
			{
				if(b[i].z==f&&b[i].y>r)t++;
				if(t==x){break;}
			}
			if(t==x)return 1;
		}
		
		
		
		//cout<<"A";
		
		t=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i].z==e&&a[i].y>l)t++;
			if(t==x){r=a[i].x;break;}
		}
		if(t==x)
		{
			t=0;
			for(int i=1;i<=n;i++)
			{
				if(a[i].z==f&&a[i].y>l&&a[i].x>r)t++;
				if(t==x){break;}
			}
			if(t==x)return 1;
		}
	}
	
	
	t=0;
	for(int i=n;i>=1;i--)
	{
		if(b[i].z==d)t++;
		if(t==x){r=b[i].y;break;}
	}
	
	//cout<<"A";
	if(t==x)
	{
		t=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i].z==e&&a[i].y<r)t++;
			if(t==x){l=a[i].x;break;}
		}//cout<<r<<" "<<l<<endl;
		if(t==x)
		{
			t=0;
			for(int i=1;i<=n;i++)
			{
				if(a[i].z==f&&a[i].y<r&&a[i].x>l)t++;
				if(t==x){break;}
			}//cout<<t<<endl;
			if(t==x)return 1;
		}
	}return 0;
}
bool check2(int x)
{
	//cout<<endl;
	if(check(1,2,3,x))return 1;//cout<<"A";
	if(check(2,1,3,x))return 1;
	if(check(3,1,2,x))return 1;
	if(check(3,2,1,x))return 1;
	if(check(1,3,2,x))return 1;
	if(check(2,3,1,x))return 1;
	return 0;
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)a[i].x=read(),a[i].y=read(),a[i].z=read(),a[i].id=i,b[i]=a[i];
	sort(a+1,a+n+1,cmp),sort(b+1,b+n+1,cmp2);
	
	
	
	//cout<<check2(15000)<<endl;
	
	//return 0;//
	int l=1,r=n/3,res=0;//return 0;
	while(l<=r)
	{
		int mid=l+r>>1;
		if(check2(mid))l=mid+1,res=mid;
		else r=mid-1;
	}
	cout<<res*3<<endl;
 	return 0;
}
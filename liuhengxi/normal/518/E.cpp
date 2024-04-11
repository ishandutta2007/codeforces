#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
#define fail return puts("Incorrect sequence"),0;
using namespace std;
const int N=1e5+5,INF=2000000000;
bool ques;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;((c^48)>9)&&c!='?';c=getchar())if(c=='-')neg=true;
	if(c=='?')ques=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,k,a[N];
bool u[2*N];
int first(int l,int r,int k)
/*l<a_0<a_1<...<a_(k-1)<r  minimize the sum of |a_i|    return a_0*/
{
	int ans=-k/2;
	if(ans<=l)ans=l+1;
	if(ans+k>r)ans=r-k;
	return ans;
}
int main()
{
	read(n);read(k);
	F(i,0,n)
	{
		ques=false;
		read(a[i]);
		if(ques)u[i]=true;
	}
	F(i,0,k)
	{
		int last=i-k;
		for(int j=i;;j+=k)if(!u[j])
		{
			int len=(j-last-k)/k,l,r;
			if(len==0){last=j;if(j>=n)break;continue;}
			if(last<0)l=-INF;else l=a[last];
			if(j>=n)r=INF;else r=a[j];
			a[last+k]=first(l,r,len);
			for(int ii=last+2*k;ii<j;ii+=k)a[ii]=a[ii-k]+1;
			last=j;if(j>=n)break;
		}
	}
	F(i,k,n)if(a[i]<=a[i-k])fail;
	F(i,0,n)printf("%d ",a[i]);
	puts("");
	return 0;
}
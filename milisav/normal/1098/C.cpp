#include<bits/stdc++.h>
using namespace std;
long long n,s;
long long d[200000];
int a[200000];
int ch[200000];
int fd[200000];
long long mt(long long m) {
	long long rt=0;
	long long t=n;
	long long d=1;
	long long p=1;
	while(t>0) {
		if(t<=p) {
			rt+=t*d;
			t=0;
			return rt;
		}
		rt+=p*d;
		d++;
		t-=p;
		p*=m;
	}
	return rt;
}
int binary()
{
	long long l=1;
	long long r=n-1;
	long long m;
	while(l<r) {
		m=(l+r)>>1;
		if(mt(m)>s) l=m+1;
		else r=m;
	}
	return l;
}
int main()
{
	scanf("%lld %lld",&n,&s);
	if(s<2*n-1 || s>n*(n+1)/2) {
		printf("No");
		return 0;
	}
	//cout<<mt(1)<<endl;
	long long k=binary();
	//cout<<k<<endl;
	d[1]=1;
	long long p=2;
	long long ts=1+k;
	for(long long i=2;i<=n;i++) {
		d[i]=d[i-1]+p;
		if(i==ts) {
			ts=1+k*ts;
			p++;
		}
		//cout<<d[i]<<endl;
	}
	a[1]=1;
	s--;
	p=2;
	long long c=2;
	long long m=n-1;
	long long l=1;
	long long r;
	long long t=1;
	fd[1]=1;
	long long mid,m1,m2;
	//cout<<s<<endl;
	while(s>0) {
		l=1;
		r=min(m,t*k);
		while(l<=r) {
			mid=(l+r)>>1;
			m1=(p-1)*m+((mid-m%mid)*d[m/mid]+(m%mid)*d[m/mid+1]);
			m2=(p-1)*m+(mid-1+(m-mid+1)*(m-mid+2)/2);
			//cout<<m<<" "<<p<<" "<<mid<<" "<<m1<<" "<<m2<<" "<<s<<endl;
			if(m1<=s && s<=m2) {
				t=mid;
				l=r+1;
			}
			else {
				if(s>m2) r=mid-1;
				else l=mid+1;
			}
		}
		s-=t*p;
		fd[p]=c;
		for(int i=c;i<c+t;i++) a[i]=p;
		p++;
		m-=t;
		c+=t;
	}
	//cout<<s<<endl;
	//printf("%lld %lld",k,d[n]);
	printf("Yes\n");
	//for(int i=1;i<=n;i++) cout<<a[i]<<" ";
	for(int i=2;i<=n;i++) {
		printf("%d ",fd[a[i]-1]);
		ch[fd[a[i]-1]]++;
		if(ch[fd[a[i]-1]]==k) fd[a[i]-1]++;
	}
	return 0;
}
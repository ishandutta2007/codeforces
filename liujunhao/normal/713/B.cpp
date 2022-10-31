#include<cstdio>
#include<algorithm>
using namespace std;
int n;
template<class T>
void Read(T &x){
	static char c;
	bool f(0);
	while(c=getchar(),c!=EOF)
		if(c=='-')
			f=1;
		else if(c>='0'&&c<='9'){
			x=c-'0';
			while(c=getchar(),c>='0'&&c<='9')
				x=x*10+c-'0';
			ungetc(c,stdin);
			if(f)
				x=-x;
			return;
		}
}
bool solve1(){
	int l=1,r=n,a,b,pos,l1,d1,u1,r1,l2,d2,u2,r2;
	while(l<r){
		int mid((l+r)>>1);
		printf("? %d %d %d %d\n",1,1,n,mid);
		fflush(stdout);
		Read(a);
		printf("? %d %d %d %d\n",1,mid+1,n,n);
		fflush(stdout);
		Read(b);
		if(a==b&&a==1){
			pos=mid;
			break;
		}
		else if(a==b&&a==0)
			return 0;
		else if(a)
			r=mid;
		else
			l=mid+1;
	}
	if(l==r){
		if(l==65536)
			return 0;
		int mid=l;
		printf("? %d %d %d %d\n",1,1,n,mid);
		fflush(stdout);
		Read(a);
		printf("? %d %d %d %d\n",1,mid+1,n,n);
		fflush(stdout);
		Read(b);
		if(a!=1||b!=1)
			return 0;
		else
			pos=l;
	}
	
	l=1,r=n;
	while(l<r){
		int mid((l+r)>>1);
		printf("? %d %d %d %d\n",1,1,mid,pos);
		fflush(stdout);
		Read(a);
		if(a)
			r=mid;
		else
			l=mid+1;
	}
	u1=l;
	l=1,r=u1;
	while(l<r){
		int mid((l+r)>>1);
		printf("? %d %d %d %d\n",mid+1,1,u1,pos);
		fflush(stdout);
		Read(a);
		if(a)
			l=mid+1;
		else
			r=mid;
	}
	d1=l;
	l=1,r=pos;
	while(l<r){
		int mid((l+r)>>1);
		printf("? %d %d %d %d\n",d1,mid+1,u1,pos);
		fflush(stdout);
		Read(a);
		if(a)
			l=mid+1;
		else
			r=mid;
	}
	l1=r;
	l=l1,r=pos;
	while(l<r){
		int mid((l+r)>>1);
		printf("? %d %d %d %d\n",d1,l1,u1,mid);
		fflush(stdout);
		Read(a);
		if(a)
			r=mid;
		else
			l=mid+1;
	}
	r1=l;
	l=1,r=n;
	while(l<r){
		int mid((l+r)>>1);
		printf("? %d %d %d %d\n",1,pos+1,mid,n);
		fflush(stdout);
		Read(a);
		if(a)
			r=mid;
		else
			l=mid+1;
	}
	u2=l;
	l=1,r=u2;
	while(l<r){
		int mid((l+r)>>1);
		printf("? %d %d %d %d\n",mid+1,pos+1,u2,n);
		fflush(stdout);
		Read(a);
		if(a)
			l=mid+1;
		else
			r=mid;
	}
	d2=l;
	l=pos+1,r=n;
	while(l<r){
		int mid((l+r)>>1);
		printf("? %d %d %d %d\n",d2,mid+1,u2,n);
		fflush(stdout);
		Read(a);
		if(a)
			l=mid+1;
		else
			r=mid;
	}
	l2=l;
	l=l2,r=n;
	while(l<r){
		int mid((l+r)>>1);
		printf("? %d %d %d %d\n",d2,l2,u2,mid);
		fflush(stdout);
		Read(a);
		if(a)
			r=mid;
		else
			l=mid+1;
	}
	r2=l;
	printf("! %d %d %d %d %d %d %d %d\n",d1,l1,u1,r1,d2,l2,u2,r2);
	fflush(stdout);
	return 1;
}
void solve2(){
	int l=1,r=n,a,b,pos,l1,d1,u1,r1,l2,d2,u2,r2;
	while(l<r){
		int mid((l+r)>>1);
		printf("? %d %d %d %d\n",1,1,mid,n);
		fflush(stdout);
		Read(a);
		printf("? %d %d %d %d\n",mid+1,1,n,n);
		fflush(stdout);
		Read(b);
		if(a==b&&a==1){
			pos=mid;
			break;
		}
		else if(a==b&&a==0)
			return;
		else if(a)
			r=mid;
		else
			l=mid+1;
	}
	if(l==r){
		printf("? %d %d %d %d\n",1,1,l,n);
		fflush(stdout);
		Read(a);
		printf("? %d %d %d %d\n",l+1,1,1,n);
		fflush(stdout);
		Read(b);
		if(a!=1||b!=1)
			return;
			else
		pos=l;
	}
	
	l=1,r=n;
	while(l<r){
		int mid((l+r)>>1);
		printf("? %d %d %d %d\n",1,1,pos,mid);
		fflush(stdout);
		Read(a);
		if(a)
			r=mid;
		else
			l=mid+1;
	}
	r1=l;
	l=1,r=r1;
	while(l<r){
		int mid((l+r)>>1);
		printf("? %d %d %d %d\n",1,mid+1,pos,r1);
		fflush(stdout);
		Read(a);
		if(a)
			l=mid+1;
		else
			r=mid;
	}
	l1=l;
	l=1,r=pos;
	while(l<r){
		int mid((l+r)>>1);
		printf("? %d %d %d %d\n",mid+1,l1,pos,r1);
		fflush(stdout);
		Read(a);
		if(a)
			l=mid+1;
		else
			r=mid;
	}
	d1=r;
	l=d1,r=pos;
	while(l<r){
		int mid((l+r)>>1);
		printf("? %d %d %d %d\n",d1,l1,mid,r1);
		fflush(stdout);
		Read(a);
		if(a)
			r=mid;
		else
			l=mid+1;
	}
	u1=l;
	l=1,r=n;
	while(l<r){
		int mid((l+r)>>1);
		printf("? %d %d %d %d\n",pos+1,1,n,mid);
		fflush(stdout);
		Read(a);
		if(a)
			r=mid;
		else
			l=mid+1;
	}
	r2=l;
	l=1,r=r2;
	while(l<r){
		int mid((l+r)>>1);
		printf("? %d %d %d %d\n",pos+1,mid+1,n,r2);
		fflush(stdout);
		Read(a);
		if(a)
			l=mid+1;
		else
			r=mid;
	}
	l2=l;
	l=pos+1,r=n;
	while(l<r){
		int mid((l+r)>>1);
		printf("? %d %d %d %d\n",mid+1,l2,n,r2);
		fflush(stdout);
		Read(a);
		if(a)
			l=mid+1;
		else
			r=mid;
	}
	d2=l;
	l=d2,r=n;
	while(l<r){
		int mid((l+r)>>1);
		printf("? %d %d %d %d\n",d2,l2,mid,r2);
		fflush(stdout);
		Read(a);
		if(a)
			r=mid;
		else
			l=mid+1;
	}
	u2=l;
	printf("! %d %d %d %d %d %d %d %d\n",d1,l1,u1,r1,d2,l2,u2,r2);
	fflush(stdout);
}
int main()
{
	Read(n);
	if(!solve1())
		solve2();
}
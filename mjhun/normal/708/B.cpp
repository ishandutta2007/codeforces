#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;

typedef long long ll;

int inv(ll r){
	int s=1,e=10000001;
	while(e-s>1){
		int m=(s+e)/2;
		if(1LL*(m-1)*(m-2)/2>=r){
			e=m;
		}
		else s=m;
	}
	if(1LL*s*(s-1)/2==r)return s;
	return -1;
}

char r[1<<20];

int main(){
	int a00,a01,a10,a11;
	scanf("%d%d%d%d",&a00,&a01,&a10,&a11);
	ll w=1LL*a00+a01+a10+a11;
	int n=inv(w);
	if(n<0)puts("Impossible");
	else if(n==1)puts("1");
	else if(!a00&&!a01&&!a10){
		int n1=inv(a11);
		if(n1<0)puts("Impossible");
		else {
			fore(i,0,n1)putchar('1');
			puts("");
		}
	}
	else if(!a01&&!a10&&!a11){
		int n0=inv(a00);
		if(n0<0)puts("Impossible");
		else {
			fore(i,0,n0)putchar('0');
			puts("");
		}
	}
	else {
		//printf("n %d\n",n);
		int n0=inv(a00);
		//printf("n0 %d\n",n0);
		int n1=inv(a11);
		//printf("n1 %d\n",n1);
		if(n0<0||n1<0||n0+n1!=n)puts("Impossible");
		else {
			if(!n0&&!n1)puts("Impossible");
			else if(!n0){
				if(a01||a10)puts("Impossible");
				else {
					fore(i,0,n1)putchar('1');
					puts("");
				}
			}
			else if(!n1){
				if(a01||a10)puts("Impossible");
				else {
					fore(i,0,n0)putchar('0');
					puts("");
				}
			}
			else {
				r[n]=0;
				// n1 <= n0 tq sum=a01
				int q=a01/n0,m=a01%n0;
				if(q>n1||q==n1&&m)puts("Impossible");
				else {
					for(int i=n-1;i>=n-q;--i)r[i]='1';
					int up=n1-q-(m>0);
					if(up<0)puts("Impossible");
					else {
						for(int i=0;i<up;++i)r[i]='1';
						for(int i=up;i<n-q;++i)r[i]='0';
						if(m){
							r[up+m]='1';
						}
						puts(r);
					}
				}
			}
		}
	}
	return 0;
}
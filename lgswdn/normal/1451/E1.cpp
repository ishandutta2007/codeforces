#include<bits/stdc++.h>
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
#define per(i,a,b) for(register int i=(a);i>=(b);i--)
using namespace std;
const int N=1e6+9;

inline int read() {
    register int x=0, f=1; register char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+c-48,c=getchar();}
    return x*f;
}

int query(int i,int j,int opt) {
	if(opt==1) printf("AND %d %d\n",i,j);
	else if(opt==2) printf("OR %d %d\n",i,j);
	else if(opt==3) printf("XOR %d %d\n",i,j);
	fflush(stdout);
	return read();
}
bool bit(int s,int i) {
	return (1<<i)&s;
}
int calc(int x,int xorx,int ret=0) {
	rep(h,0,16) {
		int r=(1<<h);
		if(bit(x,h)&&!bit(xorx,h)) ret+=r;
		else if(bit(xorx,h)&&!bit(x,h)) ret+=r;
	}
	return ret;
}
int n,a[N];

int main() {
	n=read();
	int and12=query(1,2,1),xor12=query(1,2,3),and13=query(1,3,1),xor13=query(1,3,3),and23=query(2,3,1);
	rep(h,0,16) {
		int r=(1<<h);
		if(bit(and12,h)) {
			a[1]+=r, a[2]+=r;
			if(bit(and13,h)) a[3]+=r;
		} else {
			if(!bit(xor12,h)) {
				if(bit(xor13,h)) a[3]+=r;
			} else {
				if(bit(and13,h)) {
					a[1]+=r, a[3]+=r;
				} else {
					if(!bit(xor13,h)) {
						a[2]+=r;
					} else {
						if(bit(and23,h)) {
							a[2]+=r, a[3]+=r;
						} else {
							a[1]+=r;
						}
					}
				}
			}
		}
	}
	rep(i,4,n) {
		int xor1i=query(1,i,3);
		a[i]=calc(a[1],xor1i);
	}
	cout<<"! ";
	rep(i,1,n) printf("%d ",a[i]);
	return 0;
} //
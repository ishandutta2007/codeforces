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
int n,a[N],x[N],cnt[N],rp=-1;

int main() {
	n=read();
	rep(i,2,n) x[i]=query(1,i,3), cnt[x[i]]++;
	cnt[0]++;
	rep(i,0,n) if(cnt[i]>1) {rp=i; break;}
	if(rp!=-1) {
		vector<int>vec;
		rep(i,1,n) if(x[i]==rp) vec.push_back(i);
		int res=query(vec[0],vec[1],1);
		a[1]=calc(res,x[vec[0]]);
		rep(i,2,n) a[i]=calc(a[1],x[i]);
		putchar('!');
		rep(i,1,n) printf(" %d",a[i]);
	}
	else {
		rep(i,1,n) if(x[i]==n-1) {rp=i; break;}
		int tp=(rp==2 ? 3 : 2);
		int and1t=query(1,tp,1),andrt=query(rp,tp,1);
		rep(h,0,30) {
			int g=(1<<h);
			if(bit(and1t,h)) {
				a[1]+=g;
			} else {
				if(!bit(x[tp],h)) {
					a[rp]+=g;
				} else {
					if(!bit(andrt,h)) {
						a[1]+=g;
					} else {
						a[tp]+=g, a[rp]+=g;
					}
				}
			}
		}
		rep(i,2,n) a[i]=calc(a[1],x[i]);
		putchar('!');
		rep(i,1,n) printf(" %d",a[i]);
	}
	return 0;
}//
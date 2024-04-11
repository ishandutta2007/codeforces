#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=1e5+10,rev[10]={0,1,5,0,0,2,0,0,8,0};
inline int qr(){
	int in=0;char ch;
	while(!isdigit(ch=getchar()));
	do in=(in<<1)+(in<<3)+(ch^48);while(isdigit(ch=getchar()));
	return in;
}
int h,hh,m,mm,t;
inline int rvs(int k){
	int tmp1=k/10,tmp2=k%10;
	return rev[tmp2]*10+rev[tmp1];
}
inline bool check(int k,int lim){
	int tmp1=k/10,tmp2=k%10;
	if((tmp1&&!rev[tmp1])||(tmp2&&!rev[tmp2]))return false;
	return rvs(k)<lim;
}
int main(){
	t=qr();
	while(t--){
		h=qr(),m=qr();
		hh=qr(),mm=qr();
		while(!check(hh,m)||!check(mm,h)){
			++mm;
			if(mm>=m)mm=0,++hh;
			if(hh>=h)hh=0;
		}
		if(hh<10)putchar(48);
		printf("%d:",hh);
		if(mm<10)putchar(48);
		printf("%d\n",mm);
	}
	return 0;
}
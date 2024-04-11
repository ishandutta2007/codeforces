#include<cmath>
#include<cctype>
#include<cstdio>
#include<vector>
#define ri register int
typedef long long ll;
static char pbuf[1000000],*p1=pbuf,*p2=pbuf,obuf[1000000],*o=obuf;
#define getchar() p1==p2&&(p2=(p1=pbuf)+fread(pbuf,1,1000000,stdin),p1==p2)?EOF:*p1++
#define putchar(x) (o-obuf<1000000)?(*o++=(x)):(fwrite(obuf,o-obuf,1,stdout),o=obuf,*o++=(x))
inline int qr(){
	ri in=0;register char ch;
	while(!isdigit(ch=getchar()));
	do in=(in<<1)+(in<<3)+(ch^48);while(isdigit(ch=getchar()));
	return in;
}
void qw(ll out){
	if(out>9)qw(out/10);
	putchar(out%10|48);
}
const int maxa=2e7+10;
int c,d,_div[maxa],t,x;
std::vector<int>pri;
ll ans;
int main(){
	for(ri i=2;i<20000001;++i){
		if(!_div[i])_div[i]=1,pri.push_back(i);
		for(ri j=0;j<pri.size()&&i*pri[j]<20000001;++j){
			if(i%pri[j]==0){_div[i*pri[j]]=_div[i];break;}
			_div[i*pri[j]]=_div[i]+1;
		}
	}
	t=qr();
	while(t--){
		c=qr(),d=qr(),x=qr();
		ri r=sqrt(x);
		ans=0;
		for(ri i=1;i<r;++i)
			if(x%i==0){
				if((d+i)%c==0)ans+=(1<<_div[(d+i)/c]);
				if((d+x/i)%c==0)ans+=(1<<_div[(d+x/i)/c]);
			}
		if(x%r==0){
			if((d+r)%c==0)ans+=(1<<_div[(d+r)/c]);
			if(r*r!=x&&(d+x/r)%c==0)ans+=(1<<_div[(d+x/r)/c]);
		}
		qw(ans),putchar(10);
	}
	fwrite(obuf,o-obuf,1,stdout);
	return 0;
}
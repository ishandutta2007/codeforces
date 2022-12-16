#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#if (!defined(__cplusplus) || __cplusplus > 201103)
/**
 * Use scanner in c++14, c++17 or c++20!
 */
template<class T>
struct Scanner{
	int value;
	Scanner(){
		value=0;
		int ch;
		while(isdigit(ch=getchar())){
			value=value*10+(ch^'0');
		}
	}
};
Scanner<int> qaq;
#else
#endif

LL ds(LL x){
	// cerr<<__FUNCTION__<<endl;
	int c=0;
	while(x>0){
		c++;
		x/=10;
	}
	return c;
}
LL dg(LL x,int i){
	// cerr<<__FUNCTION__<<" "<<x<<" "<<i<<endl;
	int q=ds(x)-i;
	while(q--){
		x/=10;
	}
	return x%10;
}
LL cnt(LL x){
	LL ans=0;
	LL c=1;
	LL p=9;
	while(x>0){
		LL r=min(p,x);
		x-=r;
		ans+=c*r;
		c++;
		p*=10;
	}
	return ans;
}
LL sum(LL a,LL b){
	return (a+b)*(b-a+1)/2;
}
LL cntpf(LL x){
	// cerr<<__FUNCTION__<<" "<<x<<endl;
	LL ans=0;
	LL c=1;
	LL p=9;
	while(x>0){
		LL r=min(p,x);
		ans+=c*sum(x-r+1,x);
		x-=r;
		c++;
		p*=10;
	}
	// cerr<<ans<<endl;
	return ans;
}
LL maxSmallThan(LL func(LL),LL v){
	LL l=0,r=1;
	while(func(r)<v){
		r=r*1.2+1;
	}
	// cerr<<"r="<<r<<" v="<<v<<endl;
	while(l<r){
		LL mid=(l+r+1)>>1;
		if(func(mid)<v){
			l=mid;
		}
		else{
			r=mid-1;
		}
	}
	// cerr<<"mS="<<l<<endl;
	return l;
}
LL work(LL x){
	LL a=maxSmallThan(cntpf,x);
	x-=cntpf(a);
	LL b=maxSmallThan(cnt,x);
	x-=cnt(b);
	// cerr<<"b="<<b<<endl;
	return dg(b+1,x);
}
int main(){
	int q;
	scanf("%d",&q);
	while(q--){
		LL c;
		cin>>c;
		cout<<work(c)<<endl;
	}
	return 0;
}
#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef __int128 bi;
int const N=233;
int n,p,q,a[N];
bi gcd(bi a,bi b){
	return b?gcd(b,a%b):a;
}
struct frac{
	bi x,y;
	void upd(){
		bi g=__gcd(x,y);x/=g,y/=g;
		if(y<0)x=-x,y=-y;
	}
	frac(bi a=0,bi b=1):x(a),y(b){upd();}
	frac inv()const{
		return{y,x};
	}
	frac operator+(const frac&rhs)const{
		frac res={x*rhs.y+y*rhs.x,y*rhs.y};
		return res.upd(),res;
	}
	frac operator-(const frac&rhs)const{
		return*this+rhs*-1;
	}
	frac operator*(const frac&rhs)const{
		frac res={x*rhs.x,y*rhs.y};
		return res.upd(),res;
	}
	frac operator/(const frac&rhs)const{
		return(*this)*rhs.inv();
	}
	int operator<(const frac&rhs)const{
		return(!rhs.y&&y)||x*rhs.y<y*rhs.x;
	}
	int operator>(const frac&rhs)const{
		return rhs<*this;
	}
	int operator==(const frac&rhs)const{
		return!(*this<rhs)&&!(rhs<*this);
	}
	int operator<=(const frac&rhs)const{
		return*this<rhs||*this==rhs;
	}
	int operator>=(const frac&rhs)const{
		return*this>rhs||*this==rhs;
	}
	frac&operator+=(const frac&rhs){
		return(*this)=(*this)+rhs;
	}
	frac&operator-=(const frac&rhs){
		return(*this)=(*this)-rhs;
	}
	frac&operator*=(const frac&rhs){
		return(*this)=(*this)*rhs;
	}
	frac&operator/=(const frac&rhs){
		return(*this)=(*this)/rhs;
	}
};
frac t,cur;
signed main(){
	ios::sync_with_stdio(0);
	cin>>p>>q>>n;
	for(int i=1;i<=n;i++)
	    cin>>a[i];
	t=frac(p,q),cur=a[n];
	for(int i=n-1;i>=1;i--){
	    cur=cur.inv()+a[i];
	    if(cur.y>q)
	        cout<<"NO\n",exit(0);
	}
	cout<<(cur==t?"YES\n":"NO\n");
}
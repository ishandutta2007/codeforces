#include<bits/stdc++.h>
using namespace std;
#define ri int
typedef long double ll;
const int maxn=1e5+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
ll ans=-1,tmp,x,y,z;
string s;
inline void calc(ll x,ll y,ll z,string X,string Y,string Z){
	if((tmp=log(x)*pow(y,z))>ans)ans=tmp,s=X+"^"+Y+"^"+Z;
	if((tmp=log(x)*pow(z,y))>ans)ans=tmp,s=X+"^"+Z+"^"+Y;
	if((tmp=log(x)*y*z)>ans)ans=tmp,s="("+X+"^"+Y+")^"+Z;
}
int main(){
	scanf("%Lf%Lf%Lf",&x,&y,&z);
	calc(x,y,z,"x","y","z");
	calc(y,x,z,"y","x","z");
	calc(z,x,y,"z","x","y");
	cout<<s;
	return 0;
}
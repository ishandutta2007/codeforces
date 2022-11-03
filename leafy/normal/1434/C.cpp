#include<bits/stdc++.h>
using namespace std;
typedef __int128 ll;
#define int __int128
inline int read(){
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)) s=s*10+ch-'0',ch=getchar();
	return s*f; 
}
int a,b,c,d;
inline int C2(int x){
	return x*(x-1)/2;
}
inline int calc(int x){
	int pre=((x-1)*d+1-c-1)/d+1;
	if((pre-1)*d+1+c>(x-1)*d+1) pre--;
	if(pre<0) pre=0;
	//cout<<pre<<endl;
	int t=C2(x-pre)*d;
	int h=pre*b*c+t*b;
	return a*x-h;
}
signed main(){
	int t=read();
	while(t--){
		a=read(),b=read(),c=read(),d=read();
		ll l=1,r=1e9,ans=0;
		//for(int i=1;i<=10;i++) cout<<calc(i)<<endl;
		for(int i=1;i<=100;i++){
			ll lmid=l+(r-l)/3,rmid=r-(r-l)/3;
			if(calc(lmid)>calc(rmid)) r=rmid;
			else l=lmid;
		}
		if(calc(r+1)>calc(r)) {
			puts("-1");
			continue;
		}
		for(int i=l;i<=r;i++){
			ans=max(ans,calc(i));
		}
		printf("%lld\n",(long long)ans);
	}
	return 0;
}
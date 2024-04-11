#include<bits/stdc++.h>
const int N=4000,mod=1e9+7;
int n,m,p,l,h=1,a[N],r[N];
char s[N];
struct z{
	int x;
	z(int t=-1):x(t){}
	friend inline z operator*(z a,z b){return (long long)a.x*b.x%mod;}
	friend inline z operator-(z a,z b){return (a.x-=b.x)<0?a.x+mod:a.x;}
	friend inline z operator+(z a,z b){return (a.x+=b.x)>=mod?a.x-mod:a.x;}
}f[N][N][2][2];
z calc(int k){
	if(k<0)return z(0);
	if(k<p)return z((long long)(k+1)*(k+2)/2%mod);
	return z(((long long)p*p-(long long)(p*2-k-1)*(p*2-k-2)/2)%mod);
}
z calc(int l,int r){return l<=r?calc(r)-calc(l-1):z(0);}
z dp(int i,int j,bool ep,bool fl){
	if(i==n+1)return z(fl==0&&j>=m);
	if(~f[i][j][ep][fl].x)return f[i][j][ep][fl];
	z res=0;
	if(ep){
		if(fl){
			res=res+dp(i+1,j,1,0)*calc(r[i]+p,r[i]+p)+dp(i+1,j+1,1,1)*calc(r[i]+p-1,r[i]+p-1);
			res=res+dp(i+1,j,0,0)*calc(p,r[i]+p-1)+dp(i+1,j+1,0,1)*calc(p-1,r[i]+p-2);
		}else{
			res=res+dp(i+1,j,1,0)*calc(r[i],r[i])+dp(i+1,j+1,1,1)*calc(r[i]-1,r[i]-1);
			res=res+dp(i+1,j,0,0)*calc(r[i]-1)+dp(i+1,j+1,0,1)*calc(r[i]-2);
		}
	}else{
		if(fl){
			res=res+dp(i+1,j,0,0)*calc(p,2*p-1)+dp(i+1,j+1,0,1)*calc(p-1,2*p-2);
		}else{
			res=res+dp(i+1,j,0,0)*calc(p-1)+dp(i+1,j+1,0,1)*calc(p-2);
		}
	}
	return f[i][j][ep][fl]=res;
}
int main(){
#ifdef memset0
	freopen("1.in","r",stdin);
#endif
	scanf("%d%d%s",&p,&m,s+1),l=strlen(s+1);
	for(int i=1;i<=l;i++)s[i]-='0';
	while(h<=l){
		long long lst=0;
		for(int i=h;i<=l;i++){
			lst=lst*10+s[i];
			s[i]=lst/p,lst%=p;
		}
		while(h<=l&&!s[h])h++;
		r[++n]=lst;
	}
	// for(int i=1;i<=n;i++)printf("%d%c",r[i]," \n"[i==n]);
	std::reverse(r+1,r+n+1);
	printf("%d\n",dp(1,0,1,0).x);
}
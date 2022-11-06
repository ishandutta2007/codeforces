#include<bits/stdc++.h>

#define ll long long
using namespace std;

ll f[25][2][2]; char s[25];

	bool ok(int i,int j,int x){i--;
		if (4*i<=x && 4*i+3>=x){
			x-=4*i;
			if (j>>x&1) return 1; else return 0;
		} else return 1;
	}
struct nnn{
	int len,a[25];
	void init(){
		memset(a,0,sizeof(a));
		scanf("%s",s);
		int i; len=strlen(s);
		for (i=0; i<len; i++) a[len-i]=(s[i]<='9')?s[i]-'0':s[i]-'a'+10;
	}
	void jianyi(){
		a[1]--;int i;
		for (i=1; i<=15; i++) if (a[i]<0){
			a[i]+=16; a[i+1]--;
		}
		for (len=16; len>1 && a[len]==0; len--);
	}
	ll calc(int x){
		if (x>=len*4) return 0;
		int i,j,u,v;
		memset(f,0,sizeof(f));
		for (i=0; i<=x; i++) if (ok(1,i,x)){
			if (i<=a[1]) f[1][0][x==i]++;
			f[1][1][x==i]++;
		}
		for (i=2; i<=len; i++){
			for (j=0; j<=x; j++) if (ok(i,j,x))
				for (u=(j<=a[i])?0:1; u<2; u++)
					for (v=0; v<2; v++){
						if (v==1 || v==0 && j!=x) f[i][u][v]+=f[i-1][u|(j<a[i])][v];
						if (j==x && v==1) f[i][u][v]+=f[i-1][u|(j<a[i])][0];
					}
		}
		//cout<<x<<' '<<f[len][0][1]<<endl;
		return f[len][0][1];
	}
}l,lll,r;
int main(){
	int cas;scanf("%d",&cas);
	while (cas--){
		l.init(); r.init();
		ll ans=0; lll=l; if (l.len>1 || l.a[1]>1) lll.jianyi();
		int i;
		for (i=0; i<16; i++){
			if (l.len==1 && l.a[1]==0) 
				ans+=r.calc(i);
				else ans+=(r.calc(i)-lll.calc(i));
		}
		printf("%lld\n",ans);
	}
	return 0;
}
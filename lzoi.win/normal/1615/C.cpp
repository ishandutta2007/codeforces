#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=1e5+5,INF=0x3fffffff;
int n,a,b,c,d;
char s[MAXN],t[MAXN];
int Calc(int a,int b,int c,int d){
	int res=0;
	while(b||c){
		if(!b) return INF;
		swap(a,b);
		swap(c,d);
		a--;
		b++;
		res++;
		//if(!b&&!c) return res;
		if(!d) return INF;
		swap(a,b);
		swap(c,d);
		c--;
		d++;
		res++;
	}
	return res;
}
int main(){
	//freopen("in","r",stdin);
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d",&n);
		a=b=c=d=0;
		scanf("%s%s",s+1,t+1);
		for(int i=1; i<=n; i++){
			if(s[i]=='0'&&t[i]=='0') a++;
			if(s[i]=='1'&&t[i]=='0') b++;
			if(s[i]=='0'&&t[i]=='1') c++;
			if(s[i]=='1'&&t[i]=='1') d++;
		}
		int ans=min(Calc(a,b,c,d),d?Calc(b,a,d-1,c+1)+1:INF);
		if(ans==INF) ans=-1;
		printf("%d\n",ans);
	}
	return 0;
}
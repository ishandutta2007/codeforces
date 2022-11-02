#include<cstdio>
#include<cstring>
#include<set>
using namespace std;
const int N=2e5+5;
char s[N];
int cnt1,cnt2,cnt3;
int a,b,c,d,n;
inline int Read(){
	char ch;
	int f=1;
	while((ch=getchar())<'0'||ch>'9')
		if(ch=='-') f=-1;
	int x=ch^48;
	while((ch=getchar())>='0'&&ch<='9')
		x=(x<<3)+(x<<1)+(ch^48);
	return x*f;
}
multiset<int>cnta,cntb;
int all;
inline void Solve(){
	cnt1=0,cnt2=0;
	for(int i=1;i<=n;i++)
		if(s[i]=='A') cnt1++;
		else cnt2++;
	if(cnt1!=a+c+d){
		puts("NO");
		return ;
	}
	cnta.clear();
	cntb.clear();
	all=0;
	for(int l=1,r;l<=n;l=r+1){
		r=l;
		if(s[l]!='A'||s[l-1]=='B') continue ;
		while(r<n&&s[r+1]!=s[r]) r++;
		if((r-l+1)%2==1) all+=(r-l+1)/2;
		else cnta.insert((r-l+1)/2);
	}
	for(int l=1,r;l<=n;l=r+1){
		r=l;
		if(s[l]!='B'||s[l-1]=='A') continue ;
		while(r<n&&s[r+1]!=s[r]) r++;
		if((r-l+1)%2==1) all+=(r-l+1)/2;
		else cntb.insert((r-l+1)/2);
	}
	for(multiset<int>::iterator it=cnta.begin();it!=cnta.end();it++){
		c-=(*it);
		if(c<0){
			cntb.insert(-c-1);
			c=0;
		}
	}
	for(multiset<int>::iterator it=cntb.begin();it!=cntb.end();it++){
		d-=(*it);
		if(d<0){
			c-=(-d-1);
			d=0;
		}
	}
	if(c<0) c=0;
	if(all>=c+d) puts("YES");
	else puts("NO");
	return ;
}
int T;
int main(){
	for(T=Read();T;T--){
		a=Read();
		b=Read();
		c=Read();
		d=Read();
		n=a+b+2*c+2*d;
		scanf("%s",s+1);
		Solve();
	}
	return 0;
}
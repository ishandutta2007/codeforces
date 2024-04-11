#include<cstdio>
#include<algorithm>
using namespace std;
#define MAXN 1000
int a[MAXN+10],cnt[MAXN+10],ans,n;;
void Read(int &x){
	char c;
	while(c=getchar(),c!=EOF)
		if(c>='0'&&c<='9'){
			x=c-'0';
			while(c=getchar(),c>='0'&&c<='9')
				x=x*10+c-'0';
			ungetc(c,stdin);
			return;
		}
}
void read(){
	Read(n);
	for(int i=1;i<=n;i++)
		Read(a[i]),cnt[a[i]]++;
}
void solve(){
	int i,ret;
	bool f;
	while(1){
		f=0;
		ret=-1;
		for(i=1;i<=1000;i++){
			if(cnt[i])
				ret++,f=1,cnt[i]--;
		}
		if(!f)
			break;
		ans+=ret;
	}
}
int main()
{
	read();
	solve();
	printf("%d\n",ans);
}
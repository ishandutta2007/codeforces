#include<cstdio>
#include<algorithm>
#define MAXN 100
using namespace std;
void Read(int &x){
	char c;
	bool f(0);
	while(c=getchar(),c!=EOF){
		if(c=='-')
			f=1;
		else if(c>='0'&&c<='9'){
			x=c-'0';
			while(c=getchar(),c>='0'&&c<='9')
				x=x*10+c-'0';
			ungetc(c,stdin);
			if(f)
				x=-x;
			return;
		}
	}
}
pair<int,int>a[MAXN+10];
int ans,n,d[MAXN+10];
bool vis[MAXN+10];
void read(){
	Read(n);
	int i;
	for(i=1;i<=n;i++)
		Read(a[i].first),Read(d[i]),a[i].second=i;
}
inline bool cmp(pair<int,int>a,pair<int,int>b){
	if(a.first==b.first)
		return a.second<b.second;
	return a.first>b.first;
}
void solve(){
	int i,j,k;
	sort(a+1,a+n+1,cmp);
	for(i=1;i<=n;i++){
		for(j=n;j;j--){
			if(!vis[a[j].second]&&d[a[j].second]>=0){
				a[j].first+=d[a[j].second];
				vis[a[j].second]=1;
				pair<int,int>t=a[j];
				for(k=j-1;k&&cmp(t,a[k]);k--)
					a[k+1]=a[k],ans++;
				a[k+1]=t;
				break;
			}
		}
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(!vis[a[j].second]){
				vis[a[j].second]=1;
				a[j].first+=d[a[j].second];
				pair<int,int>t=a[j];
				for(k=j+1;k<=n&&cmp(a[k],t);k++)
					a[k-1]=a[k],ans++;
				a[k-1]=t;
				break;
			}
		}
	}
	printf("%d\n",ans);
}
int main()
{
	read();
	solve();
}
#include<cstdio>
#include<algorithm>
#define MAXN 200000
using namespace std;
typedef pair<int,int>pii;
pii a[MAXN+10];
int n;
long long ans;
void Read(int &x){
	char c;
	bool f=0;
	while(c=getchar(),c!=EOF){
		if(c=='-')
			f=1;
		if(c>='0'&&c<='9'){
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
void read(){
	Read(n);
	int i;
	for(i=1;i<=n;i++)
		Read(a[i].first),Read(a[i].second);
}
bool cmp(pii a,pii b){
	if(a.second==b.second)
		return a.first<b.first;
	return a.second<b.second;
}
void solve(){
	sort(a+1,a+n+1,cmp);
	int i,j,k,cnt;
	long long ret;
	for(i=1;i<=n;){
		for(j=i+1;j<=n&&a[j].second==a[j-1].second;j++);
		ans+=1ll*(j-i)*(j-i-1)/2;
		i=j;
	}
	pii t;
	sort(a+1,a+n+1);
	for(i=1;i<=n;){
		ret=0;
		j=lower_bound(a+1,a+n+1,make_pair(a[i].first+1,-0x7fffffff))-a;
		k=i;
		while(k<j){
			cnt=1;
			for(k++;a[k]==a[k-1]&&k<j;k++)
				cnt++;
			ret+=1ll*cnt*(j-i-cnt);
		}
		ans+=ret/2;
		i=j;
	}
}
int main()
{
	read();
	solve();
	printf("%I64d",ans);
}
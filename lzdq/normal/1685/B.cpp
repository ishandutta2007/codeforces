#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5;
int n,a,b,c,d,cnt[2];
char s[MAXN];
int x[MAXN],y[MAXN];
bool Calc(){
	cnt[0]=cnt[1]=0;
	for(int i=1; i<=n; i++){
		s[i]-='A';
		cnt[s[i]]++;
	}
	if(cnt[0]!=a+c+d||cnt[1]!=b+c+d) return 0;
	int sum=0;
	*x=*y=0;
	for(int i=1; i<=n; i++){
		int j=i;
		while(j<n&&s[j]!=s[j+1]) j++;
		int len=j-i+1;
		if(len&1) sum+=len/2;
		else{
			sum+=len/2-1;
			if(s[i]==0) x[++*x]=len/2;
			else y[++*y]=len/2;
		}
		i=j;
	}
	sort(x+1,x+*x+1);
	sort(y+1,y+*y+1);
	for(int i=1,j=0; i<=*x; i++){
		j+=x[i];
		if(j>c) break;
		sum++;
	}
	for(int i=1,j=0; i<=*y; i++){
		j+=y[i];
		if(j>d) break;
		sum++;
	}
	return sum>=c+d;
}
int main(){
	//freopen("in1.txt","r",stdin);
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d%d%d%d",&a,&b,&c,&d);
		scanf("%s",s+1);
		n=strlen(s+1);
		if(Calc()) puts("YES");
		else puts("NO");
	}
	return 0;
}
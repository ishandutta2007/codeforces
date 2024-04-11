#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5;
int n,m;
int ans1,ans2;
map<int,int> tot;
int main(){
	//freopen("in1.txt","r",stdin);
	int _; scanf("%d",&_);
	while(_--){
		ans1=ans2=0;
		tot.clear();
		scanf("%d",&n);
		for(int i=1; i<=n; i++){
			int a; scanf("%d",&a);
			int b=1;
			for(int k=2;k*k<=a;k++){
				while(a%(k*k)==0) a/=k*k;
				if(a%k==0) b*=k,a/=k;
			}
			if(a>1) b*=a;
			//printf("b %d\n",b);
			tot[b]++;
			ans1=max(ans1,tot[b]);
		}
		for(map<int,int>::iterator it=tot.begin();it!=tot.end();it++){
			int a=it->first,b=it->second;
			if(a==1||b%2==0) ans2+=b;
		}
		ans2=max(ans2,ans1);
		scanf("%d",&m);
		while(m--){
			ll w;
			scanf("%lld",&w);
			if(w) printf("%d\n",ans2);
			else printf("%d\n",ans1);
		}
	}
	return 0;
}
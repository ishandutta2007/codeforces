#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
using namespace std;
typedef long long ll;

bool isp[1024];
vector<int> p;

int main(){
	memset(isp,true,sizeof(isp));isp[0]=isp[1]=false;
	fore(i,2,1024){
		if(isp[i]){
			p.pb(i);
			for(int j=i+i;j<1024;j+=i)isp[j]=false;
		}
	}
	//printf("%d\n",SZ(p));
	int tn;
	scanf("%d",&tn);
	while(tn--){
		int a,b;
		scanf("%d%d",&a,&b);
		bool r=true;
		for(int x:p){
			int na=0,nb=0;
			while(a%x==0){na++;a/=x;}
			while(b%x==0){nb++;b/=x;}
			if((na+nb)%3){r=false;break;}
			int k=(na+nb)/3;
			if(max(na,nb)>2*k||min(na,nb)<k){r=false;break;}
		}

		r=r&&(1LL*a*a==b||1LL*b*b==a);
		puts(r?"Yes":"No");
	}
	return 0;
}
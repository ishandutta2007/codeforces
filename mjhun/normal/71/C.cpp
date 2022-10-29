#include <cstdio>
#include <vector>
using namespace std;

vector<int> pr;
vector<int> ps;
bool val[100005];

int main(){
	int n,m,i,j,k,a,p;
	bool r=false,c;
	scanf("%d",&n);
	for(i=0;i<n;++i){
		scanf("%d",&k);
		if(k)val[i]=true;
	}
	m=n;j=2;
	pr.push_back(-1);
	while(m!=1){
		for(i=j;i<=m&&m%i!=0;++i);
		j=i;
		pr.push_back(i);
		m/=i;
	}
	if(pr.size()>2&&pr[1]==2&&pr[2]==2)ps.push_back(4);
	for(i=1;i<pr.size();++i){
		if(pr[i]!=pr[i-1]&&pr[i]!=2)ps.push_back(pr[i]);
	}
	for(i=0;!r&&i<ps.size();++i){
		p=ps[i];
		a=n/p;
		for(j=0;!r&&j<a;++j){
			c=val[j];
			for(k=(j+a)%n;c&&k!=j;k=(k+a)%n){
				c=val[k];
			}
			r=c;
		}
	}
	puts(r?"YES":"NO");
	return 0;
}
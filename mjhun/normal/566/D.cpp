#include <cstdio>
#include <set>
#include <vector>
using namespace std;

int uf[200005];
int n,q;
set<int> w;
vector<int> v;

int f(int x){
	if(uf[x]==x)return x;
	return uf[x]=f(uf[x]);
}

void u(int x,int y){
	uf[f(x)]=f(y);
}

int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;++i){
		uf[i]=i;
		w.insert(i);
	}
	while(q--){
		int t,x,y;
		scanf("%d%d%d",&t,&x,&y);
		if(t==1){
			u(x,y);
		}
		else if(t==2){
			set<int>::iterator it2=w.lower_bound(y);int l=*it2;
			for(set<int>::iterator it=w.lower_bound(x);;++it){
				u(x,*it);
				if(it==it2)break;
				v.push_back(*it);
			}
			for(int i=0;i<v.size();++i){
				w.erase(v[i]);
			}
			v.clear();
		}
		else{
			printf("%s\n",f(x)==f(y)?"YES":"NO");
		}
	}
	return 0;
}
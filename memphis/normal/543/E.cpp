#include<cstdio>
#include<algorithm>
#include<vector>
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define dep(i,x,y) for(int i=x;i>=y;--i)
using namespace std;
const int S=700;
const int E=470;
const int N=200005;
const int inf=0x3f3f3f3f;

vector<int> smn[E],sv[E],sinc[E],sdec[E],inc[N],dec[N];
int n,m,a[N],c[N],q,l,r,x,las;

inline bool cmp1(const int &i,const int &j){
	return a[i]<a[j];
}
inline int belong(int x){
	return (x-1)/S+1;
}

inline int lower(vector<int> *u){
	if(!u->size()) return 0;
	if(*(u->end()-1)<x) return u->size();
	return lower_bound(u->begin(),u->end(),x)-u->begin();
}

int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n) scanf("%d",a+i),c[i]=i;
	sort(c+1,c+1+n,cmp1);
	dep(i,belong(n),1) smn[i].push_back(0),sv[i].push_back(-1);
	rep(v,1,n){
		int i=c[v];
		int j=max(1,i-m+1);
		int be=belong(j);
		int tot=0,mn=inf;
		inc[j].push_back(a[i]);
		sinc[be].push_back(a[i]);
		for(int k=(be-1)*S+1;k<=be*S;k++){
			tot+=inc[k].size();
			tot-=dec[k].size();
			if(tot<mn) mn=tot;
		}
		if(mn!=smn[be][smn[be].size()-1]){
			sv[be].push_back(a[i]);
			smn[be].push_back(mn);
		}
		if(i==n) continue;
		j=i+1;
		be=belong(j);
		tot=0,mn=inf;
		dec[j].push_back(a[i]);
		sdec[be].push_back(a[i]);
		for(int k=(be-1)*S+1;k<=be*S;k++){
			tot+=inc[k].size();
			tot-=dec[k].size();
			if(tot<mn) mn=tot;
		}
		if(mn!=smn[be][smn[be].size()-1]){
			sv[be].push_back(a[i]);
			smn[be].push_back(mn);
		}
	}
	scanf("%d",&q);
	while(q--){
		scanf("%d%d%d",&l,&r,&x);
		x^=las;
		int tot=0,mn=inf;
		int be=belong(l);
		rep(i,1,be-1){
			tot+=lower(sinc+i);
			tot-=lower(sdec+i);
		}
		if(r-l+1<=S){
			rep(i,(be-1)*S+1,l-1){	
				tot+=lower(inc+i);
				tot-=lower(dec+i);
			}
			rep(i,l,r){
				tot+=lower(inc+i);
				tot-=lower(dec+i);
				if(mn>tot) mn=tot;
			}
		}
		else{
			int tmp=tot;
			tot+=lower(sinc+be);
			tot-=lower(sdec+be);
			int ce=belong(r);
			int v;
			rep(i,be+1,ce-1){
				v=smn[i][lower(sv+i)-1];
				if(mn>v+tot) mn=v+tot;
				tot+=lower(sinc+i);
				tot-=lower(sdec+i);
			}
			if(mn>tot+smn[ce][lower(sv+ce)-1])
			rep(i,(ce-1)*S+1,r){
				tot+=lower(inc+i);
				tot-=lower(dec+i);
				if(mn>tot) mn=tot;
			}
			tot=tmp;
			if(mn>tot+smn[be][lower(sv+be)-1]){
				rep(i,(be-1)*S+1,l-1){	
					tot+=lower(inc+i);
					tot-=lower(dec+i);
				}
				rep(i,l,be*S){
					tot+=lower(inc+i);
					tot-=lower(dec+i);
					if(mn>tot) mn=tot;
				}
			}
		}
		las=mn;
		printf("%d\n",mn);
	}
}
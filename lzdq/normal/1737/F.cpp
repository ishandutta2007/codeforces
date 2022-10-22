#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cassert>
using namespace std;
typedef vector<int> Poly;
int n,m,_b[20],b[20];
int id[20];
inline bool cmp(int x,int y){
	return _b[x]>_b[y];
}
vector<Poly> ap,aq;
int main(){
	//freopen("in","r",stdin);
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d",&m);
		for(int i=0; i<m; i++)
			scanf("%d",_b+i),id[i]=i;
		sort(id,id+m,cmp);
		for(int i=0; i<m; i++)
			b[i]=_b[id[i]];
		if(b[0]>=4||m>=2&&b[0]>=3&&b[1]>=2||m>=3&&b[2]>=2){
			puts("-1");
			continue;
		}
		if(b[0]==3){
			ap={Poly{0},Poly{3},Poly{1},Poly{2}};
			for(int k=1; k<m; k++){
				aq=ap;
				for(Poly i:ap)
					aq.push_back(i);
				for(int i=0; i<1<<k+1; i++){
					aq[i].push_back(i&1);
					aq[i+(1<<k+1)].push_back((i^1)&1);
				}
				swap(aq[1<<k],aq[1<<k+1]);
				swap(ap,aq);
			}
		}else{
			int k=0;
			while(k<m&&b[k]==2) k++;
			if(k==0) ap={
				Poly{}
			};
			if(k==1) ap={
				Poly{0},
				Poly{2},
				Poly{1},
			};
			if(k==2) ap={
				Poly{0,0},
				Poly{2,2},
				Poly{0,1},
				Poly{2,1},
				Poly{0,2},
				Poly{1,1},
				Poly{2,0},
				Poly{1,2},
				Poly{1,0},
			};
			for(; k<m; k++){
				aq=ap;
				reverse(ap.begin(),ap.end());
				for(Poly i:ap)
					aq.push_back(i);
				for(int i=0; i<aq.size(); i++)
					aq[i].push_back((i^1)&1);
				aq.front().back()=0;
				aq.back().back()=1;
				swap(ap,aq);
			}
		}
		for(int i=1; i<ap.size(); i++){
			Poly p(m);
			for(int j=0; j<m; j++)
				p[id[j]]=ap[i][j];
			for(int j:p) printf("%d ",j);
			puts("");
		}
	}
	return 0;
}
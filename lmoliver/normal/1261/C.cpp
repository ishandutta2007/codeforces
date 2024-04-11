#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1001001;
bool s[N];
typedef pair<int,int> P;
typedef vector<P> VP;
int n,m;
template<bool CH,bool NOCHECK=false>
VP f(int x,int y){
	VP res;
	for(P p:VP{
		{x-1,y-1},
		{x-1,y},
		{x-1,y+1},
		{x,y-1},
		{x,y+1},
		{x+1,y-1},
		{x+1,y},
		{x+1,y+1},
	}){
		if((NOCHECK||(p.first>=0&&p.first<n&&p.second>=0&&p.second<m))&&s[p.first*m+p.second]==CH){
			res.push_back(p);
		}
	}
	return res;
}
int dis[N];
void init(){
	queue<P> q;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(!s[i*m+j]){
				dis[i*m+j]=0;
				q.push(P{i,j});
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(s[i*m+j]&&(i==0||i==n-1||j==0||j==m-1)){
				s[i*m+j]=false;
				dis[i*m+j]=1;
				q.push(P{i,j});
			}
		}
	}
	while(!q.empty()){
		P p=q.front();
		q.pop();
		int x=p.first;
		int y=p.second;
		// cerr<<x<<" "<<y<<" "<<dis[x*m+y]<<endl;
		for(P p:f<true>(x,y)){
			dis[p.first*m+p.second]=dis[x*m+y]+1;
			s[p.first*m+p.second]=false;
			q.push(p);
		}
	}
}
P tmp[N];
int tt;
bool test(int t){
	memset(s,false,sizeof(s));
	tt=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(dis[i*m+j]>t){
				tmp[tt++]=P{i,j};
				s[i*m+j]=true;
			}
		}
	}
	if(tt==0){
		return false;
	}
	int h=0;
	for(int i=0;i<t;i++){
		int t=tt;
		for(int j=h;j!=t;j++){
			const P p=tmp[j];
			for(const P &r:f<false>(p.first,p.second)){
				s[r.first*m+r.second]=true;
				tmp[tt++]=r;
			}
		}
		h=t;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			int id=i*m+j;
			if(dis[id]>=1&&!s[id]){
				return false;
			}
		}
	}
	return true;
}
int main(){
	scanf("%d%d",&n,&m);
	memset(s,false,sizeof(s));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			char ch;
			do{
				ch=getchar();
			}while(isspace(ch));
			s[i*m+j]=ch=='X';
		}
	}
	memset(dis,-1,sizeof(dis));
	init();
	// for(int i=0;i<n;i++){
	// 	for(int j=0;j<m;j++){
	// 		cerr<<dis[i*m+j]<<" ";
	// 	}
	// 	cerr<<endl;
	// }
	int l=0,r=1000;
	// for(int i=0;i<n;i++){
	// 	for(int j=0;j<m;j++){
	// 		r=max(r,dis[i*m+j]-1);
	// 	}
	// }
	while(l<r){
		int mid=(l+r+1)>>1;
		if(test(mid)){
			l=mid;
		}
		else{
			r=mid-1;
		}
	}
	printf("%d\n",l);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			putchar(dis[i*m+j]>l?'X':'.');
		}
		printf("\n");
	}
	return 0;
}
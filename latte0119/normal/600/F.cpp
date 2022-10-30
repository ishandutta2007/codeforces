#include<bits/stdc++.h>
using namespace std;


#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

template<class A,class B>
ostream& operator<<(ostream& ost,const pair<A,B>&p){
	ost<<"{"<<p.first<<","<<p.second<<"}";
	return ost;
}

template<class T>
ostream& operator<<(ostream& ost,const vector<T>&v){
	ost<<"{";
	for(int i=0;i<v.size();i++){
		if(i)ost<<",";
		ost<<v[i];
	}
	ost<<"}";
	return ost;
}


struct EdgeColoringOfBipartiteGraph{
	int N;
	vector<int>X,Y;
	
	int M;
	EdgeColoringOfBipartiteGraph(int n,vector<int>&x,vector<int>&y):N(n),X(x),Y(y){}

	void swapColor(int v,int cx,int cy,vector<vector<int>>&col){
		if(col[v][cx]!=-1){
			swapColor(col[v][cx],cy,cx,col);
		}
		swap(col[v][cx],col[v][cy]);
	}
	vector<int>coloring(){
		int M=X.size();
		vector<int>deg(N);
		for(int i=0;i<M;i++){
			deg[X[i]]++;
			deg[Y[i]]++;
		}
		int D=*max_element(deg.begin(),deg.end());
		vector<vector<int>>col(N,vector<int>(D,-1));

		for(int e=0;e<M;e++){
			int x=X[e];
			int y=Y[e];

			bool ok=false;
			for(int i=0;i<D;i++){
				if(col[x][i]==-1&&col[y][i]==-1){
					ok=true;
					col[x][i]=y;
					col[y][i]=x;
					break;
				}
			}
			if(ok)continue;

			int cx,cy;
			rep(i,D){
				if(col[y][i]==-1)cx=i;
				if(col[x][i]==-1)cy=i;
			}
			swapColor(x,cx,cy,col);
			col[x][cx]=y;
			col[y][cx]=x;
		}

		vector<int>ans(M);
		for(int i=0;i<M;i++){
			for(int j=0;j<D;j++)if(col[X[i]][j]==Y[i])ans[i]=j;
		}
		return ans;
	}
};

signed main(){
	int A,B,M;
	scanf("%d%d%d",&A,&B,&M);
	int N=A+B;
	vector<int>X(M),Y(M);
	rep(i,M){
		scanf("%d%d",&X[i],&Y[i]);
		X[i]--;Y[i]--;
		Y[i]+=A;
	}
	
	EdgeColoringOfBipartiteGraph ukuchang(N,X,Y);

	auto ans=ukuchang.coloring();
	int D;
	if(ans.size()==0)D=0;
	else D=*max_element(all(ans))+1;
	printf("%d\n",D);
	rep(i,M){
		if(i)printf(" ");
		printf("%d",ans[i]+1);
	}puts("");
	return 0;
}
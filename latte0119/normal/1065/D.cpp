#include<bits/stdc++.h>
using namespace std;

#define int long long

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


const int INF=1001001001;
int N;
int memo[100][10][10][3][200];

int A[11][11];



struct State{
	int cur;
	int y,x;
	int t;
	int num;
	int dist;
};

int dy[]={1,2,2,1,-1,-2,-2,-1};
int dx[]={-2,-1,1,2,2,1,-1,-2};

signed main(){
	cin>>N;
	fill_n(****memo,100*10*10*3*200,INF);
	queue<State>que;
	rep(i,N)rep(j,N){
		cin>>A[i][j];
		A[i][j]--;
		if(A[i][j]==0){
			rep(k,3){
				memo[0][i][j][k][0]=0;
				que.push((State){0,i,j,k,0,0});
			}
		}
	}

	auto f=[&](int cur,int y,int x,int t,int num,int dist)->void{
		if(y<0||y>=N||x<0||x>=N)return;
		if(num==200)return;
		if(memo[cur][y][x][t][num]!=INF)return;
		memo[cur][y][x][t][num]=dist;
		que.push((State){cur,y,x,t,num,dist});
	};

	pint ans(INF,INF);
	while(que.size()){
		State s=que.front();
		que.pop();
		int cur=s.cur;
		int y=s.y;
		int x=s.x;
		int t=s.t;
		int num=s.num;
		int dist=s.dist;

		if(cur==N*N-1)chmin(ans,pint(s.dist,s.num));

		if(A[y][x]==cur+1)f(cur+1,y,x,t,num,dist);
		rep(k,3)f(cur,y,x,k,num+1,dist+1);

		if(t==0){
			rep(d,8){
				f(cur,y+dy[d],x+dx[d],t,num,dist+1);
			}
		}
		if(t==1){
			rep(nx,N)f(cur,y,nx,t,num,dist+1);
			rep(ny,N)f(cur,ny,x,t,num,dist+1);
		}
		if(t==2){
			for(int d=-10;d<=10;d++){
				f(cur,y+d,x+d,t,num,dist+1);
				f(cur,y+d,x-d,t,num,dist+1);
			}
		}
	}

	cout<<ans.fi<<" "<<ans.se<<endl;
	return 0;
}
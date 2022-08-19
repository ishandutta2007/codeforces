#include <bits/stdc++.h>
using namespace std;

using ll=int64_t;
#define int ll

#define FOR(i,a,b) for(int i=int(a);i<int(b);i++)
#define REP(i,b) FOR(i,0,b)
#define MP make_pair
#define PB push_back
#define ALL(x) x.begin(),x.end()
#define REACH cerr<<"reached line "<<__LINE__<<endl
#define DMP(x) cerr<<"line "<<__LINE__<<" "<<#x<<":"<<x<<endl
#define ZERO(x) memset(x,0,sizeof(x))

using pi=pair<int,int>;
using vi=vector<int>;
using ld=long double;

template<class T,class U>
ostream& operator<<(ostream& os,const pair<T,U>& p){
	os<<"("<<p.first<<","<<p.second<<")";
	return os;
}

template<class T>
ostream& operator <<(ostream& os,const vector<T>& v){
	os<<"[";
	REP(i,(int)v.size()){
		if(i)os<<",";
		os<<v[i];
	}
	os<<"]";
	return os;
}

int read(){
	int i;
	scanf("%" SCNd64,&i);
	return i;
}

void printSpace(){
	printf(" ");
}

void printEoln(){
	printf("\n");
}

void print(int x,int suc=1){
	printf("%" PRId64,x);
	if(suc==1)
		printEoln();
	if(suc==2)
		printSpace();
}

string readString(){
	static char buf[3341000];
	scanf("%s",buf);
	return string(buf);
}

char* readCharArray(){
	static char buf[3341000];
	static int bufUsed=0;
	char* ret=buf+bufUsed;
	scanf("%s",ret);
	bufUsed+=strlen(ret)+1;
	return ret;
}

template<class T,class U>
void chmax(T& a,U b){
	if(a<b)
		a=b;
}

template<class T,class U>
void chmin(T& a,U b){
	if(b<a)
		a=b;
}

template<class T>
T Sq(const T& t){
	return t*t;
}

const int inf=LLONG_MAX/3;

struct Waf{
	int cost,last;
	bool operator<(const Waf&rhs)const{
		return cost<rhs.cost;
	}
};

void Check(int ans,vi p,vi mv){
	int n=p.size(),cost=0;
	for(auto x:mv){
		int w=min(p[x],p[x+1]);
		p[x]-=w;
		p[x+1]-=w;
		cost+=w;
	}
	assert(ans==cost);
	REP(i,n-1)
		assert(p[i]==0||p[i+1]==0);
}

void Answer(vi mv){
	print(mv.size());
	for(auto x:mv)
		print(x+1);
	exit(0);
}

void CheckAndAnswer(int ans,vi p,vi mv){
	int n=p.size(),cost=0;
	vi res;
	for(auto x:mv){
		int w=min(p[x],p[x+1]);
		p[x]-=w;
		p[x+1]-=w;
		cost+=w;
		if(w)res.PB(x);
	}
	assert(ans==cost);
	REP(i,n-1)
		assert(p[i]==0||p[i+1]==0);
	Answer(res);
}

const int Nmax=300010;
Waf dp[Nmax][2][2];

int encode(int a,int b,int c){
	return	(a*2+b)*2+c;
}
void decode(int x,int&a,int&b,int&c){
	c=x%2;x/=2;
	b=x%2;x/=2;
	a=x;
}

signed main(){
	int n=read();
	vi p(n);REP(i,n)p[i]=read();
	
	REP(i,2)REP(j,2)dp[0][i][j].last=-1;
	
	Waf z[2][2];
	REP(i,2)REP(j,2)z[i][j]=Waf{inf,0};
	
	REP(x,n){
		REP(i,2)z[x%2][i].cost+=p[x];
		REP(i,2)REP(j,2)dp[x+1][i][j].cost=inf;
		
		//len=1
		REP(i,2){
			int cost=dp[x][i][0].cost;
			chmin(dp[x+1][1][1],Waf{cost,encode(x,i,0)});
		}
		
		//len=2
		if(x>=1){
			int s=p[x-1]>p[x],t=p[x-1]<p[x];
			REP(i,2)REP(j,2){
				int cost=dp[x-1][i][j].cost+min(p[x-1],p[x]);
				if(j+s<=1)chmin(dp[x+1][s][t],Waf{cost,encode(x-1,i,j)});
			}
		}
		
		//len=3
		if(x>=2){
			{
				int a=p[x-2],b=p[x-1],c=p[x],d=0;
				{
					int w=min(a,b);
					a-=w;
					b-=w;
					d+=w;
				}
				{
					int w=min(b,c);
					b-=w;
					c-=w;
					d+=w;
				}
				int s=bool(a),t=bool(c);
				REP(i,2)REP(j,2){
					int cost=dp[x-2][i][j].cost+d;
					if(j+s<=1)chmin(dp[x+1][s][t],Waf{cost,encode(x-2,i,j)});
				}
			}
			{
				int a=p[x-2],b=p[x-1],c=p[x],d=0;
				{
					int w=min(b,c);
					b-=w;
					c-=w;
					d+=w;
				}
				{
					int w=min(a,b);
					a-=w;
					b-=w;
					d+=w;
				}
				int s=bool(a),t=bool(c);
				REP(i,2)REP(j,2){
					int cost=dp[x-2][i][j].cost+d;
					if(j+s<=1)chmin(dp[x+1][s][t],Waf{cost,encode(x-2,i,j)});
				}
			}
		}
		
		//len>=4
		if(x>=3){
			int s=p[x-1]<p[x];
			REP(i,2)REP(j,2)chmin(dp[x+1][j][s],z[i][j]);
		}
		
		//add to a
		if(2<=x){
			REP(i,2)REP(j,2)REP(k,2){
				int cost=dp[x-2][i][j].cost;
				FOR(y,x-2,x+1)if(k==y%2)cost+=p[y];
				Waf w=Waf{cost,encode(x-2,i,j)};
				if(p[x-2]<=p[x-1])chmin(z[k][0],w);
				else if(j==0)chmin(z[k][1],w);
			}
		}
	}
	int a=n,b=0,c=0;
	REP(i,2)REP(j,2)if(dp[n][i][j]<dp[a][b][c]){
		b=i;
		c=j;
	}
	int minCost=dp[a][b][c].cost;
	//DMP(minCost);
	vi mv;
	while(a){
		int d,e,f;
		decode(dp[a][b][c].last,d,e,f);
		//cerr<<dp[a][b][c].cost<<endl;
		//cerr<<vi{a,b,c,d,e,f}<<endl;
		vi pos;
		FOR(i,d+1,a)pos.PB(i-1);
		if(b==1)reverse(ALL(pos));
		if(b==0&&c==0){
			int tmp=pos.back();
			pos.pop_back();
			pos.insert(pos.begin(),tmp);
		}
		mv.insert(mv.end(),ALL(pos));
		assert(f+b<=1);
		a=d;b=e;c=f;
	}
	//Check(minCost,p,mv);
	//Answer(mv);
	CheckAndAnswer(minCost,p,mv);
}
#include <bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll

#define FOR(i,a,b) for(int i=int(a);i<int(b);i++)
#define REP(i,b) FOR(i,0,b)
#define MP make_pair
#define PB push_back
#define ALL(x) x.begin(),x.end()
#define REACH cerr<<"reached line "<<__LINE__<<endl
#define DBG(x) cerr<<"line "<<__LINE__<<" "<<#x<<":"<<x<<endl

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
	scanf("%lld",&i);
	return i;
}

void printSpace(){
	printf(" ");
}

void printEoln(){
	printf("\n");
}

void print(int x,int suc=1){
	printf("%lld",x);
	if(suc==1)
		printEoln();
	if(suc==2)
		printSpace();
}

string readString(){
	static char buf[3341919];
	scanf("%s",buf);
	return string(buf);
}

char* readCharArray(){
	static char buf[3341919];
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
	if(a>b)
		a=b;
}

template<class T>
T Sq(const T& t){
	return t*t;
}

const int inf=LLONG_MAX/3;

const int HWmax=364;
int buf[HWmax][HWmax];
bool has[HWmax][HWmax];
bool go[2][8][HWmax][HWmax];
bool vis[HWmax][HWmax];

signed main(){
	int n=read();
	int cx=HWmax/2,cy=HWmax/2;
	go[0][0][cy][cx]=true;
	has[cy][cx]=true;
	int dx[]={0,1,1,1,0,-1,-1,-1};
	int dy[]={-1,-1,0,1,1,1,0,-1};
	int w=0;
	REP(_,n){
		int t=read();
		if(_)t++;
		REP(k,8){
			memset(buf,0,sizeof(buf));
			REP(i,HWmax)REP(j,HWmax)if(go[w][k][i][j]){
				buf[i][j]+=1;
				buf[i+dy[k]*t][j+dx[k]*t]+=-1;
				assert(0<=i+dy[k]*t&&i+dy[k]*t<HWmax);
				assert(0<=j+dx[k]*t&&j+dx[k]*t<HWmax);
			}
			memset(vis,0,sizeof(vis));
			function<int(int,int)> set;
			set=[&](int y,int x){
				if(y<0||HWmax<=y||x<0||HWmax<=x)
					return 0LL;
				if(vis[y][x])
					return buf[y][x];
				vis[y][x]=true;
				return buf[y][x]+=set(y-dy[k],x-dx[k]);
			};
			REP(i,HWmax)REP(j,HWmax)
				if(set(i,j))
					has[i][j]=true;
		}
		memset(go[w^1],0,sizeof(go[w^1]));
		REP(k,8)REP(i,HWmax)REP(j,HWmax)if(go[w][k][i][j]){
				assert(0<=i+dy[k]*(t-1)&&i+dy[k]*(t-1)<HWmax);
				assert(0<=j+dx[k]*(t-1)&&j+dx[k]*(t-1)<HWmax);
				go[w^1][(k+1)%8][i+dy[k]*(t-1)][j+dx[k]*(t-1)]=true;
				go[w^1][(k+7)%8][i+dy[k]*(t-1)][j+dx[k]*(t-1)]=true;
			}
		w^=1;
	}
	int ans=0;
	REP(i,HWmax)REP(j,HWmax)
		if(has[i][j])
			ans++;
	cout<<ans<<endl;
}
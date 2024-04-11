#include <bits/stdc++.h>
#include <type_traits>
using namespace std;

using ll=int64_t;
//#define int ll

#define FOR(i,a,b) for(int i=int(a);i<int(b);i++)
#define REP(i,b) FOR(i,0,b)
#define MP make_pair
#define PB push_back
#define EB emplace_back
#define ALL(x) x.begin(),x.end()
auto& errStream=cerr;
#ifdef LOCAL
#define cerr (cerr<<"-- line "<<__LINE__<<" -- ")
#else
class CerrDummy{}cerrDummy;
template<class T>
CerrDummy& operator<<(CerrDummy&cd,const T&){
	return cd;
}
using charTDummy=char;
using traitsDummy=char_traits<charTDummy>;
CerrDummy& operator<<(CerrDummy&cd,basic_ostream<charTDummy,traitsDummy>&(basic_ostream<charTDummy,traitsDummy>&)){
	return cd;
}
#define cerr cerrDummy
#endif
#define REACH cerr<<"reached"<<endl
#define DMP(x) cerr<<#x<<":"<<x<<endl
#define ZERO(x) memset(x,0,sizeof(x))
#define ONE(x) memset(x,-1,sizeof(x))

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
	os<<"{";
	REP(i,(int)v.size()){
		if(i)os<<",";
		os<<v[i];
	}
	os<<"}";
	return os;
}

ll read(){
	ll i;
	scanf("%"  SCNd64,&i);
	return i;
}

void printSpace(){
	printf(" ");
}

void printEoln(){
	printf("\n");
}

void print(ll x,int suc=1){
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

#define CAPITAL
void Yes(bool ex=true){
	#ifdef CAPITAL
	cout<<"YES"<<endl;
	#else
	cout<<"Yes"<<endl;
	#endif
	//if(ex)exit(0);
}
void No(bool ex=true){
	#ifdef CAPITAL
	cout<<"NO"<<endl;
	#else
	cout<<"No"<<endl;
	#endif
	//if(ex)exit(0);
}

const ll infLL=LLONG_MAX/3;

#ifdef int
const int inf=infLL;
#else
const int inf=INT_MAX/2-100;
#endif

const int Nmax=1000010;
char s[Nmax],a[Nmax],b[Nmax],ans[Nmax];
const int Kmax=26;
int n,k,perm[Kmax],tmpPerm[Kmax];
bool used[Kmax],tmpUsed[Kmax];

bool Check(){
	REP(i,n){
		ans[i]=char(perm[s[i]-'a']+'a');
	}
	ans[n]=0;
	if(strcmp(a,ans)<=0&&strcmp(ans,b)<=0){
		Yes(0);
		int cur=0;
		REP(i,k){
			if(perm[i]==-1){
				while(used[cur])cur++;
				perm[i]=cur;
				used[cur]=1;
			}
			printf("%c",char(perm[i]+'a'));
		}
		printf("\n");
		return true;
	}
	return false;
}

bool Go(int i,bool large){
	int cur=large?k-1:0;
	while(i<n){
		int j=s[i]-'a';
		if(perm[j]==-1){
			while(used[cur]){
				if(large)
					cur--;
				else
					cur++;
				assert(0<=cur&&cur<k);
			}
			perm[j]=cur;
			used[cur]=1;
		}
		i++;
	}
	return Check();
}

void Solve(){
	ONE(perm);
	ZERO(used);
	k=read();
	scanf("%s",s);
	n=strlen(s);
	scanf("%s",a);
	scanf("%s",b);
	int i=0;
	while(i<n&&a[i]==b[i]){
		int j=s[i]-'a';
		if(perm[j]==-1){
			int z=a[i]-'a';
			if(used[z]){
				No(0);
				return;
			}
			perm[j]=z;
			used[z]=1;
		}else{
			if(char(perm[j]+'a')!=a[i]){
				No(0);
				return;
			}
		}
		i++;
	}
	if(i==n){
		if(!Check()){
			No(0);
		}
		return;
	}
	int x=a[i]-'a',y=b[i]-'a';
	FOR(z,x,y+1){
		if(perm[s[i]-'a']!=-1){
			if(perm[s[i]-'a']!=z)
				continue;
		}else{
			if(used[z])
				continue;
		}
		memcpy(tmpPerm,perm,sizeof(perm));
		memcpy(tmpUsed,used,sizeof(used));
		if(perm[s[i]-'a']==-1){
			perm[s[i]-'a']=z;
			used[z]=1;
		}
		if(Go(i+1,z==x))return;
		memcpy(perm,tmpPerm,sizeof(tmpPerm));
		memcpy(used,tmpUsed,sizeof(tmpUsed));
	}
	No(0);
}

signed main(){
	int t=read();
	REP(_,t){
		Solve();
	}
}
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<random>
#include<chrono>
#include<vector>
#include<cassert>
using namespace std;
typedef long long ll;
typedef vector<int> Poly;
int n,m;
Poly lft;
inline void shuf(Poly &p){
	shuffle(p.begin(),p.end(),default_random_engine(chrono::system_clock::now().time_since_epoch().count()));
}
bool Ask(Poly &p){
	printf("? %d",(int)(p.size()));
	for(int i:p) printf(" %d",i);
	puts("");
	fflush(stdout);
	static char s[10];
	scanf("%s",s);
	return s[0]=='Y';
}
bool Ans(int x){
	printf("! %d\n",x);
	fflush(stdout);
	static char s[10];
	scanf("%s",s);
	return s[1]==')';
}
int main(){
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
		lft.push_back(i);
	while((m=lft.size())>=3){
		shuf(lft);
		Poly a(lft.begin(),lft.begin()+m/3),b(lft.begin()+m/3,lft.begin()+m*2/3),c(lft.begin()+m*2/3,lft.end());
		bool x=Ask(a),y,z;
		if(x){
			y=Ask(b);
			if(y) c.clear();
			else b.clear();
		}else{
			y=Ask(a);
			if(y){
				z=Ask(b);
				if(z) c.clear();
				else b.clear();
			}else a.clear();
		}
		lft.clear();
		for(int i:a) lft.push_back(i);
		for(int i:b) lft.push_back(i);
		for(int i:c) lft.push_back(i);
	}
	if(!Ans(lft[0])) assert(Ans(lft[1]));
	return 0;
}
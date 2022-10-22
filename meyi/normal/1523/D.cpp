#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=2e5+10,mod=998244353;
#define pb push_back
mt19937 rnd;
int ans1,b[maxn],f[maxn],m,n,p;
string ans2,e,s[maxn];
set<string>ft;
map<string,bool>vis;
inline void wtf(){
	ri x=(rnd()+rand())%500;
	while(x--)rnd(),rand();
}
int main(){
	srand(time(0));
	rnd.seed(time(0)+rand());
	clock_t st=clock();
	scanf("%d%d%d",&n,&m,&p);
	for(ri i=1;i<(1<<p);++i)b[i]=b[i-(i&-i)]+1;
	uniform_int_distribution<int>lim(1,n);
	for(ri i=1;i<=n;++i)cin>>s[i],ft.insert(s[i]);
	random_shuffle(s+1,s+n+1);
	for(ri i=0;i<m;++i)e+='0';
	ans2=e;
	while(clock()-st<=2700){
		ri x=lim(rnd);
		if(vis[s[x]])continue;
		vis[s[x]]=true;
		vector<int>pos;
		for(ri i=0;i<m;++i)
			if(s[x][i]=='1')
				pos.pb(i);
		memset(f,0,sizeof f);
		for(ri i=1;i<=n;++i){
			ri tmp=0;
			for(ri j=0;j<pos.size();++j){
				tmp<<=1;
				if(s[i][pos[j]]=='1')tmp|=1;
			}
			++f[tmp];
		}
		for(ri i=0;i<pos.size();++i)
			for(ri j=0;j<(1<<pos.size());++j)
				if(j&(1<<i))
					f[j^(1<<i)]+=f[j];
		for(ri i=1;i<(1<<pos.size());++i)
			if(f[i]*2>=n&&b[i]>b[ans1]){
				ans1=i;
				ans2=e;
				for(ri j=pos.size()-1,k=i;~j;--j,k>>=1)
					if(k&1)
						ans2[pos[j]]='1';
			}
		if((rnd()&1)&&(rand()&1))rnd.seed(time(0)+rnd()+rand());
		wtf();
	}
	cout<<ans2;
	return 0;
}
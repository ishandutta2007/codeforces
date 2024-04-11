#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cassert>
#include<set>
#include<map>
#include<unordered_map>
#include<queue>
#include<stack>
using namespace std;
typedef long long LL;
typedef pair<int,int>pii;
typedef unsigned uint;
typedef unsigned long long uLL;
const double pi=acos(-1);
template<class T>
void Read(T &x){
	char c;
	bool f(0);
	while(c=getchar(),c!=EOF){
		if(c=='-')
			f=1;
		else if(c>='0'&&c<='9'){
			x=c-'0';
			while(c=getchar(),c>='0'&&c<='9')
				x=x*10+c-'0';
			ungetc(c,stdin);
			if(f)
				x=-x;
			return;
		}
	}
}
//
#define MAXN 128
vector<int>nst[MAXN+10];
int h,T,m,ans,t;
bool vis[MAXN+10],vis2[MAXN+10];
int cnt;
deque<int>q;
queue<int>q2,q3;
void go1(int u){
	while(1){
	vis[u]=1;
		q.push_back(u);
		printf("? %d\n",u);
					assert(++cnt<17);
		fflush(stdout);
		Read(m);
		int tm=m;
		nst[u].clear();
		while(tm--){
			Read(t);
			nst[u].push_back(t);
		}
		if(m==2){
			ans=u;
			return;
		}
		if(m==1)
			return;
		for(auto i:nst[u])
			if(!vis[i]){
				u=i;
				break;
			}
	}
}
void go2(int u){
	while(1){
	vis[u]=1;
		q.push_front(u);
		printf("? %d\n",u);
					assert(++cnt<17);
		fflush(stdout);
		Read(m);
		int tm=m;
		nst[u].clear();
		while(tm--){
			Read(t);
			nst[u].push_back(t);
		}
		if(m==2){
			ans=u;
			return;
		}
		if(m==1)
			return;
		for(auto i:nst[u])
			if(!vis[i]){
				u=i;
				break;
			}
	}
}
void preask(){
	q.clear();
	q.push_back(1);
	puts("? 1");
	fflush(stdout);
	Read(m);
	int t;
	nst[1].clear();
		int tm=m;
	while(tm--){
		Read(t);
		nst[1].push_back(t);
	}
	if(m==2){
		ans=1;
		return;
	}
	else if(m==1)
		return;
	go1(nst[1].front());
	if(ans)
		return;
	go2(nst[1].back());
	if(ans)
		return;
}
int main()
{
	int now;
	Read(T);
	while(T--){
		cnt=0;
		ans=0;
		Read(h);
		memset(vis,0,sizeof vis);
		vis[1]=1;
		preask();
		int t=q.size();
		t=t>>1;
		int dep=h-t;
		while(t--)
			q.pop_front();
		int lca=q.front();
		int tm;
		if(ans)
			goto pr;
		for(auto j:nst[lca])
			if(!vis[j]){
				lca=j;
				break;
			}
		int i;
		vis[lca]=1;
		printf("? %d\n",lca);
		fflush(stdout);
			nst[lca].clear();
		Read(m);
			tm=m;
		while(tm--){
			Read(t);
			nst[lca].push_back(t);
		}
		if(m==2){
			ans=lca;
			goto pr;
		}
		for(i=dep-1;i>3;i--){
			memset(vis2,0,sizeof vis2);
			now=lca;
			int nxt;
			for(auto j:nst[lca])
				if(!vis[j]){
					nxt=j;
					break;
				}
			for(int j=1;j<=h-i;j++){
				for(auto k:nst[now])
					if(!vis[k]&&!vis2[k]){
						now=k;
						break;
					}
				vis2[now]=1;
				printf("? %d\n",now);
					assert(++cnt<17);
				fflush(stdout);
				Read(m);
				nst[now].clear();
		int tm=m;
				while(tm--){
					Read(t);
					nst[now].push_back(t);
				}
				if(m==2){
					ans=now;
					goto pr;
				}
			}
			if(nst[now].size()==1){
				for(auto k:nst[lca])
					if(!vis[k]&&!vis2[k]){
						lca=k;
						break;
					}
				printf("? %d\n",lca);
					assert(++cnt<17);
				nst[lca].clear();
				fflush(stdout);
				Read(m);
		int tm=m;
				while(tm--){
					Read(t);
					nst[lca].push_back(t);
				}
				if(m==2){
					ans=lca;
					goto pr;
				}
			}
			else{
				lca=nxt;
			}
			q.push_front(nxt);
			vis[lca]=1;
		}
		while(!q2.empty())
			q2.pop();
		q2.push(lca);
		for(;i>1;i--){
			while(!q3.empty())
				q3.pop();
			while(!q2.empty()){
				int u=q2.front();
				q2.pop();
				if(!vis[u]){
					vis[u]=1;
					nst[u].clear();
					printf("? %d\n",u);
					assert(++cnt<17);
					fflush(stdout);
					Read(m);
					while(m--){
						Read(t);
						nst[u].push_back(t);
					}
				}
				for(auto j:nst[u])
					if(!vis[j])
						q3.push(j);
			}
			q2.swap(q3);
		}
		while(q2.size()>1){
			printf("? %d\n",q2.front());
					assert(++cnt<17);
			fflush(stdout);
			int u=q2.front();
			q2.pop();
			Read(m);
			int tm=m;
			while(tm--)
				Read(t);
			if(m==2){
				ans=u;
				break;
			}
		}
		if(!ans)
			ans=q2.front();
		pr:printf("! %d\n",ans);
		fflush(stdout);
	}
}
/*
4
3
5 6
5 3
6 4
6 1
3 2
3 7
4
12 1
12 6
1 4
1 2
6 11
6 13
4 5
4 14
2 9
2 3
11 15
11 7
13 10
13 8
4
9 5
9 7
5 11
5 2
7 13
7 1
11 14
11 8
2 3
2 15
13 10
13 6
1 4
1 12
2
2 3
2 1*/
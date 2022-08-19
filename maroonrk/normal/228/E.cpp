#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,b) FOR(i,0,b)
#define PB push_back

using namespace std;

typedef long long ll;

inline int Pack(int x,bool b){
	return (x<<1)+b;
}

inline int Idx(int x){
	return x>>1;
}

inline int Flag(int x){
	return x&1;
}

inline int Not(int x){
	return x^1;
}

struct TwoSAT{
	static const int maxN = 100*2;
	static const int maxM = 10000/2*2*2;
	int m,edge[maxM][2];
	TwoSAT():m(0),t(-1){
		memset(last,-1,sizeof(last));
		memset(pushed,false,sizeof(pushed));
	}
	void Add(int x,int y){
		edge[m][0]=Not(x);
		edge[m++][1]=y;
		edge[m][0]=Not(y);
		edge[m++][1]=x;
	}
	int t,last[maxN];
	int s,use[maxN];
	void Mark(int x){
		if(last[x]<t){
			last[x]=t;
			use[s++]=x;
		}
	}
	vector<int> graph[maxN];
	int sSize,sBuf[maxN];
	void Push(int x){
		sBuf[sSize++]=x;
	}
	int Pop(){
		return sBuf[--sSize];
	}
	bool pushed[maxN];
	int num,ord[maxN],low[maxN],group[maxN],cmps;
	void scc(int v){
		Push(v);
		pushed[v]=true;
		ord[v]=low[v]=num++;
		for(auto i:graph[v]){
			if(ord[i]==-1){
				scc(i);
				low[v]=min(low[v],low[i]);
			}else if(pushed[i])
				low[v]=min(low[v],ord[i]);
		}
		if(ord[v]==low[v]){
			while(1){
				int x=Pop();
				pushed[x]=false;
				group[x]=cmps;
				if(x==v)
					break;
			}
			cmps++;
		}
	}
	bool SAT(int b,int e){
		b*=2;
		e*=2;
		s=0;
		t++;
		FOR(i,b,e){
			Mark(edge[i][0]);
			Mark(edge[i][1]);
		}
		REP(_,s){
			int i=use[_];
			graph[i].clear();
			ord[i]=low[i]=-1;
		}
		FOR(i,b,e)
			graph[edge[i][0]].PB(edge[i][1]);
		sSize=0;
		num=0;
		cmps=0;
		REP(_,s){
			int i=use[_];
			if(ord[i]==-1)
				scc(i);
		}
		REP(_,s){
			int i=use[_];
			if(group[i]==group[Not(i)])
				return false;
		}
		return true;
	}
	vector<int> cmpG[maxN];
	int come[maxN],cmpOrd[maxN];
	bool Empty(){
		return sSize==0;
	}
	void Answer(bool ans[]){
		REP(_,s){
			int i=use[_];
			come[group[i]]=0;
		}
		REP(_,s){
			int i=use[_];
			for(auto j:graph[i])
				if(group[i]!=group[j]){
					cmpG[group[i]].PB(group[j]);
					come[group[j]]++;
				}
		}
		REP(_,s){
			int i=use[_];
			if(come[group[i]]==0){
				come[group[i]]=-1;
				Push(group[i]);
			}
		}
		int k=0;
		while(!Empty()){
			int g=Pop();
			cmpOrd[g]=k++;
			for(auto i:cmpG[g])
				if(--come[i]==0)
					Push(i);
		}
		REP(_,s){
			int i=use[_];
			if(Flag(i)==0)
				ans[Idx(i)]=cmpOrd[group[i]]>cmpOrd[group[Not(i)]];
		}
	}
} tSat;

int read(){
	int i;
	scanf("%d",&i);
	return i;
}

int w[100];
bool p[100];

int main(){
	int n=read(),m=read();
	REP(i,m){
		int a=read()-1,b=read()-1,c=read();
		tSat.Add(Pack(a,0),Pack(b,c));
		tSat.Add(Pack(a,1),Pack(b,c^1));
	}
	if(tSat.SAT(0,m*2)){
		tSat.Answer(p);
		int s=0;
		REP(i,n)
			if(p[i])
				w[s++]=i;
		printf("%d\n",s);
		REP(i,s)
			printf(i<s-1?"%d ":"%d\n",w[i]+1);
	}else
		printf("Impossible\n");
}
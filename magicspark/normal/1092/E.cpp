//By MagicSpark
/*
Problem:1092E
Main Idea:
Status:
*/
#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
const long long inf2=0x3f3f3f3f3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
int n,m;
vector<int> g[1111];
bool used[2222];
vector<pair<int,int> >edges;
int dist[1111][1111];
int pre[1111][1111];
int nxt[1111][1111];
void bfs(int v){
	//cerr<<v<<endl;
	for(int i=1;i<=n;i++)dist[v][i]=inf,pre[v][i]=nxt[v][i]=-1;
	queue<int>q;
	dist[v][v]=0;
	q.push(v);
	while(q.size()){
		int x=q.front();q.pop();
		for(int i=0;i<g[x].size();i++){
			if(dist[v][g[x][i]]>dist[v][x]+1){
				pre[v][g[x][i]]=x;
				dist[v][g[x][i]]=dist[v][x]+1;
				q.push(g[x][i]);
			}
		}
	}
}
struct Tree{
	vector<int>points;
	void clear(){
		points.clear();
	}
	void print(){
		cout<<"Tree:";
		for(auto p:points){
			cout<<p<<" ";
		}
		cout<<endl;
	}
	void push_back(int x){
		points.push_back(x);
	}
	int diameter(){
		if(!points.size())return 0;
		//cout<<"Error1"<<endl;
		bfs(points[0]);
		//cout<<points[0]<<endl;
		int pos=-1,mx=-1;
		for(int i=0;i<points.size();i++){
			//cout<<points[i]<<" "<<dist[points[0]][points[i]]<<endl;
			if(dist[points[0]][points[i]]>mx){
				mx=dist[points[0]][points[i]];
				pos=i;
			}
		}
		//cout<<points[pos]<<endl;
		bfs(points[pos]);
		int temp=points[pos];
		pos=-1;mx=-1;
		for(int i=0;i<points.size();i++){
			if(dist[temp][points[i]]>mx){
				mx=dist[temp][points[i]];
				pos=i;
			}
		}
		//cout<<"Why?"<<dist[temp][1]<<" "<<dist[temp][28]<<endl;
		//cout<<points[pos]<<" "<<mx<<endl;
		return mx;
	}
	int center(){
		if(!points.size())return -inf;
		//cout<<"Error2"<<endl;
		//printf("Center:\n");
		//print();
		//cout<<points[0]<<endl;
		bfs(points[0]);
		int pos=-1,mx=-1;
		for(int i=0;i<points.size();i++){
			if(dist[points[0]][points[i]]>mx){
				mx=dist[points[0]][points[i]];
				pos=i;
			}
		}
		bfs(points[pos]);
		int temp=points[pos];
		pos=-1;mx=-1;
		for(int i=0;i<points.size();i++){
			//cout<<points[i]<<" "<<dist[temp][points[i]]<<endl;
			if(dist[temp][points[i]]>mx){
				mx=dist[temp][points[i]];
				pos=i;
			}
		}
		int dis=mx;
		int start=temp;
		//cout<<temp<<" "<<dis<<endl;
		bfs(temp);
		bfs(points[pos]);
		while(dist[temp][start]<dis/2){
			//cout<<start<<endl;
			start=pre[points[pos]][start];
		}
		//cout<<start<<endl;
		return start;
	}
}tmp;
bool operator<(Tree a,Tree b){
	int da=a.diameter(),db=b.diameter();
	if(da!=db)return da>db;
	else return a.points>b.points;
}
set<Tree>Trees;
void build(int x,int par=-1){
	used[x]=true;
	tmp.push_back(x);
	for(int i=0;i<g[x].size();i++)if(g[x][i]!=par)build(g[x][i],x);
}
Tree unite(Tree a,Tree b){
	//if(a.center()==-inf||b.center()==-inf)1/0;
	int aa=a.center(),bb=b.center();
	edges.push_back(make_pair(aa,bb));
	g[aa].push_back(bb);
	g[bb].push_back(aa);
	//puts("1111111111111111111111111111111111");
	//cout<<aa<<" "<<bb<<endl;
	Tree c;
	c.clear();
	for(int i=0;i<a.points.size();i++)c.push_back(a.points[i]);
	for(int i=0;i<b.points.size();i++)c.push_back(b.points[i]);
	return c;
}
void init(){
	memset(dist,inf,sizeof(dist));
	for(int i=0;i<m;i++){
		int at,bt;
		cin>>at>>bt;
		//if(n==100&&m==98&&i>=74)cout<<a<<" "<<b<<endl;
		g[at].push_back(bt);
		g[bt].push_back(at);
	}
	cerr<<"ok input"<<endl;
	for(int i=1;i<=n;i++)if(!used[i]){
		build(i);
		Trees.insert(tmp);
		//cerr<<"Size:"<<tmp.points.size()<<endl;
		tmp.clear();
	}
	cerr<<"ok init"<<endl;
	while(Trees.size()>1){
		//cerr<<Trees.size()<<endl;
		set<Tree>::iterator itr=Trees.begin(),itr2=Trees.begin();
		itr2++;
		//printf("00000000000000\n");
		//Tree x=*itr;
		//x.print();x=*itr2;
		//x.print();
		//printf("00000000000000\n");
		Tree Tr=unite(*itr,*itr2);
		Trees.erase(itr);Trees.erase(itr2);
		Trees.insert(Tr);
	}
}
int main(){
	//freopen("data.cpp","w",stdout);
	//freopen("duipai.txt","r",stdin);
	cin>>n>>m;
	init();
	Tree T=*Trees.begin();
	//T.print();
	cout<<T.diameter()<<endl;
	for(auto p:edges){
		cout<<p.first<<" "<<p.second<<endl;
	}
	#ifndef ONLINE_JUDGE
		printf("\n-----\n");
        printf("Time: %d ms\n", (int)(clock() * 1000/ CLOCKS_PER_SEC));
    #endif
	return 0;
}
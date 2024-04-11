#include<bits/stdc++.h>
using namespace std;
int const N=250010;
typedef array<int,8> node;
int t,flg,f[N],deg[N];
vector<node>s;
node cur,a,b;
vector<int>e[N];
queue<int>q;
void dfs(int x,int mx){
	if(x>7){
		s.push_back(cur);
		return;
	}
	for(int i=mx;i<5;i++)
		dfs(x+1,cur[x]=i);
}
int ord(const node&x){
	return lower_bound(s.begin(),s.end(),x)-s.begin();
}
int ord(int x,int y){
	return x*s.size()+y;
}
int main(){
	ios::sync_with_stdio(0);
	dfs(0,0),sort(s.begin(),s.end());
	for(int i=0;i<s.size();i++)
		for(int j=0;j<s.size();j++){
			int x=ord(i,j);
			node ti=s[i],tj=s[j];
			for(int p=0;p<8;p++)
				for(int q=0;q<8;q++){
					if(!ti[p]||!tj[q])continue;
					node tp=ti;tp[p]=(tp[p]+tj[q])%5;
					sort(tp.begin(),tp.end());
					e[ord(j,ord(tp))].push_back(x),deg[x]++;
				}
		}
	for(int i=1;i<s.size();i++)
		f[ord(i,0)]=1,q.push(ord(i,0));
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int y:e[x]){
			if(f[y])continue;
			if(~f[x])f[y]=-1,q.push(y);
			else if(!--deg[y])f[y]=1,q.push(y);
		}
	}
	for(cin>>t;t--;){
		cin>>flg;
		for(int i=0;i<8;i++)
			cin>>a[i];
		for(int i=0;i<8;i++)
			cin>>b[i];
		sort(a.begin(),a.end());
		sort(b.begin(),b.end());
		if(flg)swap(a,b);
		int res=f[ord(ord(a),ord(b))];
		cout<<(!res?"Deal\n":res*(flg?-1:1)>0?"Bob\n":"Alice\n");
	}
}
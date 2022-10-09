#include<bits/stdc++.h>
using namespace std;
const int MAXN=222;
map<int,int> M;
int friends[MAXN][MAXN];
int ss[MAXN];
set<int> answers[MAXN];
int per[MAXN];
int rm[MAXN];
main(){
	int num=0;
	int m,k;scanf("%d%d",&m,&k);
	for(int i=1;i<=m;i++){
		int a,b;scanf("%d%d",&a,&b);
		if(M.find(a)==M.end())
			num++,M[a]=num,rm[num]=a;
		a=M[a];
		if(M.find(b)==M.end())
			num++,M[b]=num,rm[num]=b;
		b=M[b];
		friends[a][b]=1;
		friends[b][a]=1;	
		ss[a]++,ss[b]++;
	}
	int nr=1;
	for(auto it:M){
		per[nr]=it.second;
		nr++;
	}
	for(int a=1;a<=num;a++){
		for(int b=1;b<=num;b++){
			if(a==b||friends[a][b]) continue;
			int shf=0;
			for(int c=1;c<=num;c++){
				if(friends[a][c]&&friends[b][c]){
					shf++;
				}
			}
			if(shf*100>=k*ss[a]) answers[a].insert(rm[b]);
		}
	}
	for(int i=1;i<=num;i++){
		printf("%d: %d ",rm[per[i]],answers[per[i]].size());
		for(auto b:answers[per[i]]) printf("%d ",b);
		puts("");
	}
}
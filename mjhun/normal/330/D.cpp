#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
#define mp make_pair
#define fst first
#define snd second
#define INF 1<<30
using namespace std;

char mat[1024][1024];
int d[1024][1024];

int m,n;

void calcd(int ei, int ej){
	int sonsi[8];
	int sonsj[8];
	int k=0,i,j,a,b,dist;
	d[ei][ej]=0;
	queue<pair<int,int> > cola;
	
	cola.push(mp(ei,ej));
	
	while(!cola.empty()){
		a=cola.front().fst;
		b=cola.front().snd;
		cola.pop();
		k=0;
		if(a>1&&mat[a-1][b]!='T'){
			sonsi[k]=a-1;
			sonsj[k]=b;
			++k;
		}
		if(a<m&&mat[a+1][b]!='T'){
			sonsi[k]=a+1;
			sonsj[k]=b;
			++k;
		}
		if(b>1&&mat[a][b-1]!='T'){
			sonsi[k]=a;
			sonsj[k]=b-1;
			++k;
		}
		if(b<n&&mat[a][b+1]!='T'){
			sonsi[k]=a;
			sonsj[k]=b+1;
			++k;
		}
		for(i=0;i<k;++i){
			if(1+d[a][b]<d[sonsi[i]][sonsj[i]]){
				d[sonsi[i]][sonsj[i]]=1+d[a][b];
				cola.push(mp(sonsi[i],sonsj[i]));
			}
		}
	}
	
}

int main(){
	int i,j,si,sj,ei,ej,k,ds,r;
	cin>>m>>n;
	for(i=1;i<=m;++i){
		for(j=1;j<=n;++j){
			cin>>mat[i][j];
			if(mat[i][j]=='S'){
				si=i;
				sj=j;
			}
			if(mat[i][j]=='E'){
				ei=i;
				ej=j;
			}
		}
	}
	for(i=1;i<=m;++i){
		for(j=1;j<=n;++j){
			d[i][j]=INF;
		}
	}
	calcd(ei,ej);	
	
	ds=d[si][sj];
	
	r=0;
	
	for(i=1;i<=m;++i){
		for(j=1;j<=n;++j){
		//	cout<<(d[i][j]==INF?-1:d[i][j])<<' ';
			if(d[i][j]<=ds&&mat[i][j]>='1'&&mat[i][j]<='9')
				r+=mat[i][j]-'0';
		}
	//	cout<<endl;
	}
	
	cout<<r<<endl;
	
	return 0;
}
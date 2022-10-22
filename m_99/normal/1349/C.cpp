#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000

int main(){
	
	int n,m,t;
	scanf("%d %d %d",&n,&m,&t);
	
	vector<string> S(n);
	for(int i=0;i<n;i++)cin>>S[i];
	
	vector<vector<int>> cnt(n,vector<int>(m,-1));
	queue<pair<int,int>> Q;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			for(int d=0;d<4;d++){
				int y = i,x = j;
				if(d==0)y++;
				if(d==1)y--;
				if(d==2)x++;
				if(d==3)x--;
				
				if(y<0||x<0||x>=m||y>=n)continue;
				if(S[i][j]==S[y][x]){
					cnt[i][j]=1;
					Q.emplace(i,j);
				}
			}
		}
	}
	
	for(int i=1;Q.size()!=0;i++){
		queue<pair<int,int>> nQ;
		while(Q.size()!=0){
			int y = Q.front().first;
			int x = Q.front().second;
			Q.pop();
			
			for(int d=0;d<4;d++){
				int yy = y,xx = x;
				if(d==0)yy++;
				if(d==1)yy--;
				if(d==2)xx++;
				if(d==3)xx--;
				if(yy<0||xx<0||xx>=m||yy>=n)continue;
				if(cnt[yy][xx]==-1){
					cnt[yy][xx] = i+1;
					nQ.emplace(yy,xx);
				}
			}
		}
		swap(Q,nQ);
	}
	
	for(int i=0;i<t;i++){
		int I,J;
		long long P;
		scanf("%d %d %lld",&I,&J,&P);
		I--;J--;
		char ans;
		if(cnt[I][J]==-1||cnt[I][J]>P){
			ans = S[I][J];
		}
		else{
			if((P-cnt[I][J])%2==1)ans = S[I][J];
			else{
				if(S[I][J]=='0')ans = '1';
				else ans = '0';
			}
		}
		
		printf("%c\n",ans);
	}
	
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
vector<string> mp,mp2;
int n,m;
void go(vector<string> &mp,bool der){
	for(int i=n-1;i>=0;i--){
		for(int j=m-1;j>=0;j--){
			char &cur=mp[i][j];
			if(i==n-1&&j==m-1)continue;
			if(cur!='#'){
				cur='#';
				int dx=der?1:0,dy=1-dx;
				if(i+dx<n&&j+dy<m&&mp[i+dx][j+dy]!='#'){
					cur=dx==1?'v':'>';
					continue;
				}
				swap(dx,dy);
				if(i+dx<n&&j+dy<m&&mp[i+dx][j+dy]!='#'){
					cur=dx==1?'v':'>';
					continue;
				}
			};
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		static string s;
		cin>>s;
		mp.push_back(s);
	}
	mp2=mp;
	go(mp,true);
	if(mp[0][0]=='#'){
		puts("0");
		exit(0);
	}
	go(mp2,false);
	// for(int i=0;i<n;i++){
	// 	cerr<<mp[i]<<endl;
	// }
	// cerr<<endl;
	// for(int i=0;i<n;i++){
	// 	cerr<<mp2[i]<<endl;
	// }
	// cerr<<endl;
	int x=0,y=0;
	while(mp2[x][y]!='.'){
		if(mp2[x][y]=='v'){
			if(x!=0||y!=0){
				mp2[x][y]='#';
			}
			x++;
		}
		else{
			if(x!=0||y!=0){
				mp2[x][y]='#';
			}
			y++;
		}
	}
	x=0;
	y=0;
	while(mp[x][y]!='.'){
		if(mp2[x][y]=='#'){
			puts("1");
			exit(0);
		}
		if(mp[x][y]=='v'){
			x++;
		}
		else{
			y++;
		}
	}
	puts("2");
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
const int dx[4]={-1,0,0,1},dy[4]={0,-1,1,0};
int main(){
	int n,m,ans=0;
	cin>>n>>m;
	string s;
	pair<int,int> st,en;
	char in[n][m];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>in[i][j];
			if(in[i][j]=='S')st={i,j};
			else if(in[i][j]=='E')en={i,j};
		}
	}
	cin>>s;
	int ha[4]={0,1,2,3};
	do{
		int a=st.first,b=st.second;
		for(char c:s){
			a+=dx[ha[c-'0']];
			b+=dy[ha[c-'0']];
			if(a<0||b<0||a>=n||b>=m||in[a][b]=='#')break;
			if(a==en.first&&b==en.second){
				ans++;
				break;
			}
		}
	}while(next_permutation(ha,ha+4));
	cout<<ans<<"\n";
}
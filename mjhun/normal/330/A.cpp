#include <iostream>
using namespace std;
char mat[16][16];
int sumi[16];
int sumj[16];

int main(){
	int m,n,i,j,s,k;
	cin>>m>>n;
	for(i=1;i<=m;++i){
		for(j=1;j<=n;++j){
			cin>>mat[i][j];
			if(mat[i][j]=='.'){
				sumi[i]++;
				sumj[j]++;
			}
		}
	}
	s=0;
	k=0;
	for(i=1;i<=m;++i){
		if(sumi[i]==n){
			s+=n;
			k++;
		}
	}
	for(j=1;j<=n;++j){
		if(sumj[j]==m){
			s+=m-k;
		}
	}
	cout<<s<<endl;
	return 0;
}
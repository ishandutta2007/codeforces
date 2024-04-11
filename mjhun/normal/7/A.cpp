#include <iostream>
#define n 8
using namespace std;

char board[70][70];

int main(){
	int i,j,r=0;
	bool b;
	for(i=1;i<=n;++i)
		for(j=1;j<=n;++j)
			cin>>board[i][j];
	
	for(i=1;i<=n;++i){
		b=true;
		for(j=2;b&&j<=n;++j)
			b= board[i][j]=='B';
		r+=(int)b;
	}
	for(j=1;j<=n;++j){
		b=true;
		for(i=2;b&&i<=n;++i)
			b= board[i][j]=='B';
		r+=(int)b;
	}
	cout<<((r==16)?8:r)<<endl;
	return 0;
}
#include <cstdio>
#include <iostream>
using namespace std;

bool paint[1005][1005];
int t[1005][1005];
bool cont=true;

void f(int i, int j){
	if(i>0&&j>0&&!paint[i][j]){
		t[i][j]++;
		if(t[i][j]==9)
			cont=false;
	}
}

int main(){
	int n,k,i,j,a,p;
	cin>>n>>p;
	for(i=1;i<=n;++i){
		for(j=1;j<=n;++j){
			t[i][j]=0;
			paint[i][j]=false;
		}
	}
	for(k=1;k<=p&&cont;++k){
		cin>>i>>j;
		f(i,j);
		f(i-1,j);
		f(i-2,j);
		f(i-1,j-1);
		f(i-2,j-1);
		f(i-2,j-2);
		f(i,j-1);
		f(i,j-2);
		f(i-1,j-2);
	}
	while(getchar()!=EOF);
	cout<<(cont?-1:k-1)<<endl;
	return 0;
}
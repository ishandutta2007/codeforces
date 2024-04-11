#include <cstring>
#include <iostream>
using namespace std;
bool usab[1024];
int main(){
	int n,m,i,a,b,j;
	cin>>n>>m;
	memset(usab,true,sizeof(usab));
	for(i=0;i<m;++i){
		cin>>a>>b;
		usab[a]=false;
		usab[b]=false;
	}
	bool found=false;
	for(i=1;!found&&i<=n;++i){
		found=usab[i];
	}
	--i;
	cout<<n-1<<endl;
	for(j=1;j<=n;++j){
		if(j!=i){
			cout<<i<<' '<<j<<endl;
		}
	}
	return 0;
}
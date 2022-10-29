#include <iostream>
using namespace std;

char mat[128][128];
int is[128];
int js[128];
bool casti[128];
bool castj[128];

int main(){
	int n,i,j,k;
	cin>>n;
	k=0;
	for(i=1;i<=n;++i){
		for(j=1;j<=n;++j){
			cin>>mat[i][j];
		}
	}
	for(i=1;i<=n;++i){
		for(j=1;j<=n;++j){
			if(mat[i][j]!='E'&&!casti[i]){
				casti[i]=true;
				is[k]=i;
				js[k]=j;
				++k;
			}
		}
	}
	if(k==n){
		for(i=0;i<n;++i){
			cout<<is[i]<<' '<<js[i]<<endl;
		}
		return 0;
	}
	k=0;
	for(i=1;i<=n;++i){
		for(j=1;j<=n;++j){
			if(mat[i][j]!='E'&&!castj[j]){
				castj[j]=true;
				is[k]=i;
				js[k]=j;
				++k;
			}
		}
	}
	if(k!=n){
		cout<<-1<<endl;
	}
	else{
		for(i=0;i<n;++i){
			cout<<is[i]<<' '<<js[i]<<endl;
		}
	}
	return 0;
}
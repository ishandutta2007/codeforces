#include <iostream>
#define M 100005
using namespace std;

bool pcrim[M];
int pos[M];
int neg[M];
int res[M];

int main() {
	int n,m,i,k,npos=0,nneg,npcrim=0;
	cin>>n>>m;
	for(i=1;i<=n;++i){
		pos[i]=0;
		neg[i]=0;
	}
	for(i=1;i<=n;++i){
		cin>>k;
		res[i]=k;
		if(k>0){
			++npos;
			pos[k]=pos[k]+1;
		}
		else
			neg[-k]=neg[-k]+1;
	}
	nneg=n-npos;
	for(i=1;i<=n;++i)
		npcrim += (int) (pcrim[i] = pos[i]+nneg-neg[i]==m);
	
	for(i=1;i<=n;++i){
		k=res[i];
		if(k>0){
			if(pcrim[k])
				cout<<((npcrim==1)?"Truth":"Not defined")<<endl;
			else
				cout<<"Lie"<<endl;
		}
		else{
			if(pcrim[-k])
				cout<<((npcrim==1)?"Lie":"Not defined")<<endl;
			else
				cout<<"Truth"<<endl;
		}
	}
		
	return 0;
}
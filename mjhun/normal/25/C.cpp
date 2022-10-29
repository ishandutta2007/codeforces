#include <iostream>
using namespace std;

int cost[305][305];
int min(int x,int y){
	return((x<y)?x:y);
}
int main(){
	int n,k,a,b,c,i,j,x;
	long long int s=0;
	cin>>n;
	for(i=1;i<=n;++i) {
		for(j=1;j<=n;++j){
			cin>>k;
			cost[i][j]=k;
			s+=k;
		}
	}
	cin>>k;
	while(k--){
		cin>>a>>b>>c;
		for(i=1;i<=n;++i){
			for(j=1;j<=n;++j){
				x=c+min(cost[i][a]+cost[j][b],cost[i][b]+cost[j][a]);
				if(x<cost[i][j]){
					s+=x-cost[i][j];
					cost[i][j]=x;
				}
			}
		}
		cout<<(s/2)<<' ';
	}
	cout<<endl;
	return 0;
}
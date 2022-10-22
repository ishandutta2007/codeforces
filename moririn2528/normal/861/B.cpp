#include<iostream>
using namespace std;
int f[105][2];
int main(){
	int n,m;
	int i,j,k;
	bool pos=true;//possible
	int s=-1;
	cin>>n>>m;
	for(i=0;i<m;i++){
		cin>>f[i][0]>>f[i][1];
	}
	for(i=1;i<=100;i++){
		pos=true;
		for(j=0;j<m;j++){
			k=(f[j][0]-1)/i+1;
			if(f[j][1]!=k){
				pos=false;
				break;
			}
		}
		if(pos){
			if(s==-1 || s==(n-1)/i+1)s=(n-1)/i+1;
			else{
				s=-1;
				break;
			}
		}
	}
	if(s==-1)cout<<-1<<endl;
	else cout<<s<<endl;
	return 0;
}
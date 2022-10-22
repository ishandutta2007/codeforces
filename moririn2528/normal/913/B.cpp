#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
bool leaf[1005];
vector<int> child[1005];
int main(){
	int n;
	int i,j,k;
	bool s=true;
	memset(leaf,true,sizeof(leaf));
	cin>>n;
	for(i=0;i<n-1;i++){
		cin>>k;
		leaf[--k]=false;
		child[k].push_back(i+1);
	}
	for(i=0;i<n;i++){
		if(leaf[i])continue;
		for(j=0,k=0;j<child[i].size();j++){
			if(leaf[child[i][j]])k++;
		}
		if(k<3)s=false;
	}
	if(s)cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
}
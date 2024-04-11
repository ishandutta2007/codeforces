#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
bool b1[200005];
int na[200005];
int nb[200005];
int main(){
	int n;
	int i,j,k;
	int a,b,c;
	int s=0;
	cin>>n;
	memset(b1,false,sizeof(b1));
	for(i=0;i<n;i++){
		scanf("%d",&na[i]);
		na[i]--;
		nb[na[i]]++;
	}
	for(i=0,j=0;i<n;i++){
		if(nb[na[i]]==1 && !b1[na[i]])continue;
		for(;j<n;j++){
			if(nb[j]==0)break;
		}
		if(b1[na[i]]){
			nb[na[i]]--;
			na[i]=j,nb[j]++,s++;
		}else{
			if(na[i]<j){
				b1[na[i]]=true;
				continue;
			}else{
				nb[na[i]]--;
				na[i]=j,nb[j]++,s++;
			}
		}
	}
	cout<<s<<endl;
	for(i=0;i<n;i++){
		printf("%d%c",na[i]+1,i==n-1?'\n':' ');
	}
	return 0;
}